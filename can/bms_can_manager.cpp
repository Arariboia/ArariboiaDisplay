#include "bms_can_manager.h"

// Example CAN IDs for BMS data (replace with actual IDs from your BMS protocol)
#define BMS_VOLTAGE_ID_POLL 0x18900140
#define BMS_CHARGE_DISCHARGE_ID_POLL 0x18930140
#define BMS_STATUS_ID_POLL 0x18940140
#define BMS_CELL_VOLTAGE_ID_POLL 0x18950140
#define BMS_TEMPERATURE_ID_POLL 0x18960140
#define BMS_FAILURE_ID_POLL 0x18980140

#define BMS_VOLTAGE_ID_RESPONSE 0x18904001
#define BMS_CHARGE_DISCHARGE_ID_RESPONSE 0x18934001
#define BMS_STATUS_ID_RESPONSE 0x18944001
#define BMS_CELL_VOLTAGE_ID_RESPONSE 0x18954001
#define BMS_TEMPERATURE_ID_RESPONSE 0x18964001
#define BMS_FAILURE_ID_RESPONSE 0x18984001


static const char* TAG_BMS = "BMS_CAN";

BMSCANManager::BMSCANManager(QObject *parent) : QObject(parent) {
    initialize_can_handlers();
}   

void BMSCANManager::print_can_handlers() {
    char buffer[256] = {0};
    snprintf(buffer, sizeof(buffer), "[BMS] CAN Handlers: ");
    for (const auto& handler : _can_handlers) {
        snprintf(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), "0x%X ", handler.first);
    }
}

bool BMSCANManager::handle_can_frame(const QCanBusFrame &message) {
    if (_can_handlers.find(message.frameId()) != _can_handlers.end()) {
        _can_handlers[message.frameId()](message);
        return true;
    }
    return false;
}

void BMSCANManager::initialize_can_handlers() {
    _can_handlers[BMS_VOLTAGE_ID_RESPONSE] = [this](const QCanBusFrame &message) {
        handle_voltage_response(message);
    };
    _can_handlers[BMS_CHARGE_DISCHARGE_ID_RESPONSE] = [this](const QCanBusFrame &message) {
        handle_charge_discharge_response(message);
    };
    _can_handlers[BMS_STATUS_ID_RESPONSE] = [this](const QCanBusFrame &message) {
        handle_status_response(message);
    };
    _can_handlers[BMS_CELL_VOLTAGE_ID_RESPONSE] = [this](const QCanBusFrame &message) {
        handle_cell_voltage_response(message);
    };
    _can_handlers[BMS_TEMPERATURE_ID_RESPONSE] = [this](const QCanBusFrame &message) {
        handle_temperature_response(message);
    };
    _can_handlers[BMS_FAILURE_ID_RESPONSE] = [this](const QCanBusFrame &message) {
        handle_failure_response(message);
    };
}

// Helper to check and publish
void BMSCANManager::check_and_publish() {
    if (_received_flags == ALL_FLAGS) {
        emit DataReceived(_bms_data);
        _received_flags = 0; // Reset for next cycle
    }
}

void BMSCANManager::handle_voltage_response(const QCanBusFrame &message) {
    _bms_data.voltage_data.cumulative_voltage_decivolts = (message.payload()[0] << 8) | (message.payload()[1]);
    _bms_data.voltage_data.current_deciamps = ((message.payload()[4] << 8) | (message.payload()[5])) - 30000;
    _bms_data.voltage_data.soc_decipercent = ((message.payload()[6]) << 8) | (message.payload()[7]);
    _received_flags |= FLAG_VOLTAGE;
    check_and_publish();
}

void BMSCANManager::handle_charge_discharge_response(const QCanBusFrame &message) {
    _bms_data.charge_discharge_status.state = message.payload()[0];
    _bms_data.charge_discharge_status.charge_mos = message.payload()[1];
    _bms_data.charge_discharge_status.discharge_mos = message.payload()[2];
    _bms_data.charge_discharge_status.bms_life_cycles = message.payload()[3];
    _bms_data.charge_discharge_status.remaining_capacity_raw = ((message.payload()[4]) << 24) | ((message.payload()[5]) << 16) | ((message.payload()[6]) << 8) | ((message.payload()[7]));
    _received_flags |= FLAG_CHARGE_DISCHARGE;
    check_and_publish();
}

void BMSCANManager::handle_status_response(const QCanBusFrame &message) {
    _bms_data.bms_status.num_strings = message.payload()[0];
    _bms_data.bms_status.num_temp_sensors = message.payload()[1];
    _bms_data.bms_status.charger_status = message.payload()[2];
    _bms_data.bms_status.load_status = message.payload()[3];
    _bms_data.bms_status.io_bitfield = message.payload()[4];
    _received_flags |= FLAG_STATUS;
    check_and_publish();
}

void BMSCANManager::handle_cell_voltage_response(const QCanBusFrame &message) {
    uint8_t frame_index = static_cast<uint8_t>(message.payload()[0]) - 1;
    constexpr uint8_t MAX_CELLS = 16; // Maximum number of cells
    //Each frame contains up to 3 cell voltages(2 bytes each)
    for (int i = 0; i < 3; i++) {
        int cell_id = i + frame_index * 3;
        if (cell_id < MAX_CELLS) {
            uint16_t cell_mv = ((message.payload()[1 + i * 2]) << 8) | ((message.payload()[2 + i * 2]));
            _bms_data.cell_voltage_frame[frame_index].voltages_mv[i] = cell_mv;
        }
    }
    _received_flags |= FLAG_CELL_VOLTAGE;
    check_and_publish();
}
    
void BMSCANManager::handle_temperature_response(const QCanBusFrame &message) {
    uint8_t frame_index = message.payload()[0] - 1;
    constexpr uint8_t MAX_TEMPS = 2; // Maximum number of temperature sensors
    //Each frame contains up to 7 temperatures(1 byte each)
    for (int i = 0; i < 7; i++) {
        int temp_id = i + frame_index * 7;
        if (temp_id < MAX_TEMPS) {
            int8_t temp_c = message.payload()[i + 1] - 40; // Offset +40°C
            _bms_data.temperature_frame[frame_index].raw_temps[i] = temp_c;
        }
    }
    _received_flags |= FLAG_TEMPERATURE;
    check_and_publish();
}

void BMSCANManager::handle_failure_response(const QCanBusFrame &message) {
    memcpy(_bms_data.failure_status.raw, message.payload(), sizeof(_bms_data.failure_status.raw));
    char buffer[128];
    snprintf(buffer, sizeof(buffer), "[BMS] Failure Status: [");
    for (int i = 0; i < sizeof(_bms_data.failure_status.raw); i++) {
        snprintf(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer),
                "0x%02X", _bms_data.failure_status.raw[i]);
        if (i < sizeof(_bms_data.failure_status.raw) - 1) {
            snprintf(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), ", ");
        }
    }
    snprintf(buffer + strlen(buffer), sizeof(buffer) - strlen(buffer), "]\n");

    _received_flags |= FLAG_FAILURE;
    check_and_publish();
}

void BMSCANManager::poll_bms_data() {
    // Send poll commands to the BMS for each data type
    send_poll_command(BMS_VOLTAGE_ID_POLL);
    send_poll_command(BMS_CHARGE_DISCHARGE_ID_POLL);
    send_poll_command(BMS_STATUS_ID_POLL);
    send_poll_command(BMS_CELL_VOLTAGE_ID_POLL);
    send_poll_command(BMS_TEMPERATURE_ID_POLL);
    send_poll_command(BMS_FAILURE_ID_POLL);
}

void BMSCANManager::send_poll_command(uint32_t data_id) {
//    QCanBusFrame message;
//    message.extd = 1; // Extended frame format
//    message.frameId() = data_id;
//    message.data_length_code = 8; // Assuming 8 bytes of data for the poll command, all zero
//    memset(message.data, 0, sizeof(message.data));

//    twai_transmit(&message, pdMS_TO_TICKS(10)); // Send the message with a timeout of 1 second
}
