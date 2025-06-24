#include "motor_can_manager.h"
#include <QDebug>

#define CAN_ELECTRICAL_DATA_ID_LEFT  0x180117F0
#define CAN_STATE_DATA_ID_LEFT 0x180217F0
#define CAN_ELECTRICAL_DATA_ID_RIGHT  0x180117EF
#define CAN_STATE_DATA_ID_RIGHT 0x180217EF

#define BIT21   0x00200000
#define BIT20   0x00100000
#define BIT19   0x00080000
#define BIT18   0x00040000
#define BIT17   0x00020000
#define BIT16   0x00010000
#define BIT15   0x00008000
#define BIT14   0x00004000
#define BIT13   0x00002000
#define BIT12   0x00001000
#define BIT11   0x00000800
#define BIT10   0x00000400
#define BIT9     0x00000200
#define BIT8     0x00000100
#define BIT7     0x00000080
#define BIT6     0x00000040
#define BIT5     0x00000020
#define BIT4     0x00000010
#define BIT3     0x00000008
#define BIT2     0x00000004
#define BIT1     0x00000002
#define BIT0     0x00000001

static const char* TAG = "CAN";

MotorCANManager::MotorCANManager() {
    initialize_can_handlers();
}

bool MotorCANManager::handle_can_frame(const QCanBusFrame &message) {
    if (can_handlers.find(message.frameId()) != can_handlers.end()) {
        can_handlers[message.frameId()](message);
        return true;
    }
    return false;
}

void MotorCANManager::handle_electrical_data(const QCanBusFrame &message, motor_electrical_data_t &data) {
    data.bus_voltage_dV = (message.payload()[0] | (message.payload()[1] << 8));
    data.bus_current_dA = (message.payload()[2] | (message.payload()[3] << 8)) - 32000;
    data.phase_current_dA = (message.payload()[4] | (message.payload()[5] << 8)) - 32000;
    data.rpm = (message.payload()[6] | (message.payload()[7] << 8)) - 32000;
    
    if (message.frameId() == CAN_ELECTRICAL_DATA_ID_LEFT) {
        _received_flags_left |= FLAG_ELECTRICAL;
    } else if (message.frameId() == CAN_ELECTRICAL_DATA_ID_RIGHT) {
        _received_flags_right |= FLAG_ELECTRICAL;
    }
    check_and_publish(); // Check and publish data if all flags are set
}

void MotorCANManager::handle_state_data(const QCanBusFrame &message, motor_state_data_t &data) {
    data.controller_temp_C = message.payload()[0] - 40;
    data.motor_temp_C = message.payload()[1] - 40;
    data.accelerator_percent = message.payload()[2];
    data.status = message.payload()[3];
    data.error = message.payload()[4] | (message.payload()[5] << 8) | (message.payload()[6] << 16) | (message.payload()[7] << 24);

    if (message.frameId() == CAN_STATE_DATA_ID_LEFT) {
        _received_flags_left |= FLAG_STATE;
    } else if (message.frameId() == CAN_STATE_DATA_ID_RIGHT) {
        _received_flags_right |= FLAG_STATE;
    }
    check_and_publish(); // Check and publish data if all flags are set

    decode_motor_status(data.status);
    decode_motor_error(data.error);
}

void MotorCANManager::check_and_publish() {
    if (_received_flags_left == (FLAG_ELECTRICAL | FLAG_STATE)) {
        emit DataLeftReceived(motor_data_left);
        _received_flags_left = 0; // Reset for next cycle
    }

    if (_received_flags_right == (FLAG_ELECTRICAL | FLAG_STATE)) {
        emit DataRightReceived(motor_data_right);
        _received_flags_right = 0; // Reset for next cycle
    }
}

void MotorCANManager::initialize_can_handlers() {
    can_handlers[CAN_ELECTRICAL_DATA_ID_LEFT] = [this](const QCanBusFrame &message) {
        handle_electrical_data(message, motor_data_left.electrical_data);
    };
    can_handlers[CAN_STATE_DATA_ID_LEFT] = [this](const QCanBusFrame &message) {
        handle_state_data(message, motor_data_left.state_data);
    };
    can_handlers[CAN_ELECTRICAL_DATA_ID_RIGHT] = [this](const QCanBusFrame &message) {
        handle_electrical_data(message, motor_data_right.electrical_data);
    };
    can_handlers[CAN_STATE_DATA_ID_RIGHT] = [this](const QCanBusFrame &message) {
        handle_state_data(message, motor_data_right.state_data);
    };
}

void MotorCANManager::decode_motor_status(uint8_t status) {
    uint8_t gear = status & (BIT2 | BIT1 | BIT0); // Mask for gear bits
    const char* gear_str = "";
    switch (gear) {
        case 0b000: gear_str = "NO"; break;
        case 0b001: gear_str = "R"; break;
        case 0b010: gear_str = "N"; break;
        case 0b011: gear_str = "D1"; break;
        case 0b100: gear_str = "D2"; break;
        case 0b101: gear_str = "D3"; break;
        case 0b110: gear_str = "S"; break;
        case 0b111: gear_str = "P"; break;
        default: gear_str = "Unknown gear"; break;
    }

    bool brake = (status & BIT3) >> 3; // Brake bit
    const char* brake_str = brake ? "ON" : "OFF";

    uint8_t operation_mode = (status & (BIT6 | BIT5 | BIT4)) >> 4;
    const char* operation_mode_str = "";
    switch (operation_mode) {
        case 0b000: operation_mode_str = "Stopped"; break;
        case 0b001: operation_mode_str = "Drive"; break;
        case 0b010: operation_mode_str = "Cruise"; break;
        case 0b011: operation_mode_str = "EBS"; break;
        case 0b100: operation_mode_str = "Hold"; break;
    }

    uint8_t dc_contactor = (status & BIT7) >> 7; // DC contactor bit
    const char* dc_contactor_str = dc_contactor ? "ON" : "OFF";

    printf("Gear: %s, Brake: %s, Operation Mode: %s, DC Contactor: %s\n",
        gear_str, brake_str, operation_mode_str, dc_contactor_str);
}

void MotorCANManager::decode_motor_error(uint32_t error) {
    std::map<uint32_t, const char*> error_map = {
        {BIT0, "Motor Overcurrent"},
        {BIT1, "Motor Overload"},
        {BIT2, "Motor Overvoltage"},
        {BIT3, "Motor Undervoltage"},
        {BIT4, "Controller Overheat"},
        {BIT5, "Motor Overheat"},
        {BIT6, "Motor Stalled"},
        {BIT7, "Motor Out of Phase"},
        {BIT8, "Motor Sensor Failure"},
        {BIT9, "Motor AUX Sensor"},
        {BIT10, "Encoder Misaligned"},
        {BIT11, "Anti-Runaway Engaged"},
        {BIT12, "Main Accelerator"},
        {BIT13, "AUX Accelerator"},
        {BIT14, "Pre-charge"},
        {BIT15, "DC Contactor"},
        {BIT16, "Power Valve"},
        {BIT17, "Current Sensor"},
        {BIT18, "Auto-tune"},
        {BIT19, "RS485"},
        {BIT20, "CAN"},
        {BIT21, "Software"}
    };

    for (const auto& pair : error_map) {
        if (error & pair.first) {
            qDebug() << "Error: " << pair.second;
        }
    }
}
