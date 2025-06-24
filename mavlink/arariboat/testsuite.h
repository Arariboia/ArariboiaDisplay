/** @file
 *    @brief MAVLink comm protocol testsuite generated from arariboat.xml
 *    @see https://mavlink.io/en/
 */
#pragma once
#ifndef ARARIBOAT_TESTSUITE_H
#define ARARIBOAT_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_arariboat(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_arariboat(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_instrumentation(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_INSTRUMENTATION >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_instrumentation_t packet_in = {
        963497464,17443,17547,17651,17755,17859,17963,18067,18171,18275
    };
    mavlink_instrumentation_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp_seconds = packet_in.timestamp_seconds;
        packet1.battery_current = packet_in.battery_current;
        packet1.motor_current_left = packet_in.motor_current_left;
        packet1.motor_current_right = packet_in.motor_current_right;
        packet1.mppt_current = packet_in.mppt_current;
        packet1.auxiliary_battery_current = packet_in.auxiliary_battery_current;
        packet1.battery_voltage = packet_in.battery_voltage;
        packet1.auxiliary_battery_voltage = packet_in.auxiliary_battery_voltage;
        packet1.irradiance = packet_in.irradiance;
        packet1.timestamp_milliseconds = packet_in.timestamp_milliseconds;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_INSTRUMENTATION_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_INSTRUMENTATION_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_instrumentation_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_instrumentation_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_instrumentation_pack(system_id, component_id, &msg , packet1.battery_current , packet1.motor_current_left , packet1.motor_current_right , packet1.mppt_current , packet1.auxiliary_battery_current , packet1.battery_voltage , packet1.auxiliary_battery_voltage , packet1.irradiance , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_instrumentation_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_instrumentation_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.battery_current , packet1.motor_current_left , packet1.motor_current_right , packet1.mppt_current , packet1.auxiliary_battery_current , packet1.battery_voltage , packet1.auxiliary_battery_voltage , packet1.irradiance , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_instrumentation_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_instrumentation_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_instrumentation_send(MAVLINK_COMM_1 , packet1.battery_current , packet1.motor_current_left , packet1.motor_current_right , packet1.mppt_current , packet1.auxiliary_battery_current , packet1.battery_voltage , packet1.auxiliary_battery_voltage , packet1.irradiance , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_instrumentation_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("INSTRUMENTATION") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_INSTRUMENTATION) != NULL);
#endif
}

static void mavlink_test_temperatures(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_TEMPERATURES >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_temperatures_t packet_in = {
        963497464,17443,17547,17651,17755,17859
    };
    mavlink_temperatures_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp_seconds = packet_in.timestamp_seconds;
        packet1.temperature_battery_left = packet_in.temperature_battery_left;
        packet1.temperature_battery_right = packet_in.temperature_battery_right;
        packet1.temperature_mppt_left = packet_in.temperature_mppt_left;
        packet1.temperature_mppt_right = packet_in.temperature_mppt_right;
        packet1.timestamp_milliseconds = packet_in.timestamp_milliseconds;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_TEMPERATURES_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_TEMPERATURES_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_temperatures_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_temperatures_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_temperatures_pack(system_id, component_id, &msg , packet1.temperature_battery_left , packet1.temperature_battery_right , packet1.temperature_mppt_left , packet1.temperature_mppt_right , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_temperatures_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_temperatures_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.temperature_battery_left , packet1.temperature_battery_right , packet1.temperature_mppt_left , packet1.temperature_mppt_right , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_temperatures_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_temperatures_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_temperatures_send(MAVLINK_COMM_1 , packet1.temperature_battery_left , packet1.temperature_battery_right , packet1.temperature_mppt_left , packet1.temperature_mppt_right , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_temperatures_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("TEMPERATURES") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_TEMPERATURES) != NULL);
#endif
}

static void mavlink_test_gps(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_GPS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_gps_t packet_in = {
        963497464,963497672,963497880,17859,17963,53,120,187,254
    };
    mavlink_gps_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.latitude = packet_in.latitude;
        packet1.longitude = packet_in.longitude;
        packet1.timestamp_seconds = packet_in.timestamp_seconds;
        packet1.speed = packet_in.speed;
        packet1.timestamp_milliseconds = packet_in.timestamp_milliseconds;
        packet1.course = packet_in.course;
        packet1.heading = packet_in.heading;
        packet1.satellites_visible = packet_in.satellites_visible;
        packet1.hdop = packet_in.hdop;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_GPS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_GPS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gps_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_gps_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gps_pack(system_id, component_id, &msg , packet1.latitude , packet1.longitude , packet1.speed , packet1.course , packet1.heading , packet1.satellites_visible , packet1.hdop , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_gps_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gps_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.latitude , packet1.longitude , packet1.speed , packet1.course , packet1.heading , packet1.satellites_visible , packet1.hdop , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_gps_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_gps_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_gps_send(MAVLINK_COMM_1 , packet1.latitude , packet1.longitude , packet1.speed , packet1.course , packet1.heading , packet1.satellites_visible , packet1.hdop , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_gps_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("GPS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_GPS) != NULL);
#endif
}

static void mavlink_test_mppt(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MPPT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mppt_t packet_in = {
        963497464,17443,17547,17651,17755,17859
    };
    mavlink_mppt_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp_seconds = packet_in.timestamp_seconds;
        packet1.pv_voltage = packet_in.pv_voltage;
        packet1.pv_current = packet_in.pv_current;
        packet1.battery_voltage = packet_in.battery_voltage;
        packet1.battery_current = packet_in.battery_current;
        packet1.timestamp_milliseconds = packet_in.timestamp_milliseconds;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MPPT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MPPT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mppt_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mppt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mppt_pack(system_id, component_id, &msg , packet1.pv_voltage , packet1.pv_current , packet1.battery_voltage , packet1.battery_current , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_mppt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mppt_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.pv_voltage , packet1.pv_current , packet1.battery_voltage , packet1.battery_current , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_mppt_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mppt_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mppt_send(MAVLINK_COMM_1 , packet1.pv_voltage , packet1.pv_current , packet1.battery_voltage , packet1.battery_current , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_mppt_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MPPT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MPPT) != NULL);
#endif
}

static void mavlink_test_mppt_state(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_MPPT_STATE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_mppt_state_t packet_in = {
        963497464,17443,17547,17651
    };
    mavlink_mppt_state_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp_seconds = packet_in.timestamp_seconds;
        packet1.battery_status = packet_in.battery_status;
        packet1.charging_equipment_status = packet_in.charging_equipment_status;
        packet1.timestamp_milliseconds = packet_in.timestamp_milliseconds;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_MPPT_STATE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_MPPT_STATE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mppt_state_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_mppt_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mppt_state_pack(system_id, component_id, &msg , packet1.battery_status , packet1.charging_equipment_status , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_mppt_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mppt_state_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.battery_status , packet1.charging_equipment_status , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_mppt_state_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_mppt_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_mppt_state_send(MAVLINK_COMM_1 , packet1.battery_status , packet1.charging_equipment_status , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_mppt_state_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("MPPT_STATE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_MPPT_STATE) != NULL);
#endif
}

static void mavlink_test_bms(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BMS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_bms_t packet_in = {
        963497464,{ 17443, 17444, 17445, 17446, 17447, 17448, 17449, 17450, 17451, 17452, 17453, 17454, 17455, 17456, 17457, 17458 },{ 19107, 19108 },19315,19419,137
    };
    mavlink_bms_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp_seconds = packet_in.timestamp_seconds;
        packet1.current_battery = packet_in.current_battery;
        packet1.timestamp_milliseconds = packet_in.timestamp_milliseconds;
        packet1.state_of_charge = packet_in.state_of_charge;
        
        mav_array_memcpy(packet1.voltages, packet_in.voltages, sizeof(uint16_t)*16);
        mav_array_memcpy(packet1.temperatures, packet_in.temperatures, sizeof(int16_t)*2);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BMS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BMS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bms_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_bms_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bms_pack(system_id, component_id, &msg , packet1.voltages , packet1.temperatures , packet1.current_battery , packet1.state_of_charge , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_bms_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bms_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.voltages , packet1.temperatures , packet1.current_battery , packet1.state_of_charge , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_bms_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_bms_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bms_send(MAVLINK_COMM_1 , packet1.voltages , packet1.temperatures , packet1.current_battery , packet1.state_of_charge , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_bms_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("BMS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_BMS) != NULL);
#endif
}

static void mavlink_test_bms_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_BMS_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_bms_status_t packet_in = {
        963497464,{ 17443, 17444 },17651,163,230,41,108,175,242,53,120,187
    };
    mavlink_bms_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp_seconds = packet_in.timestamp_seconds;
        packet1.timestamp_milliseconds = packet_in.timestamp_milliseconds;
        packet1.status = packet_in.status;
        packet1.failure_flags_byte0 = packet_in.failure_flags_byte0;
        packet1.failure_flags_byte1 = packet_in.failure_flags_byte1;
        packet1.failure_flags_byte2 = packet_in.failure_flags_byte2;
        packet1.failure_flags_byte3 = packet_in.failure_flags_byte3;
        packet1.failure_flags_byte4 = packet_in.failure_flags_byte4;
        packet1.failure_flags_byte5 = packet_in.failure_flags_byte5;
        packet1.failure_flags_byte6 = packet_in.failure_flags_byte6;
        packet1.fault_code_byte7 = packet_in.fault_code_byte7;
        
        mav_array_memcpy(packet1.temperatures, packet_in.temperatures, sizeof(int16_t)*2);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_BMS_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_BMS_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bms_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_bms_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bms_status_pack(system_id, component_id, &msg , packet1.temperatures , packet1.status , packet1.failure_flags_byte0 , packet1.failure_flags_byte1 , packet1.failure_flags_byte2 , packet1.failure_flags_byte3 , packet1.failure_flags_byte4 , packet1.failure_flags_byte5 , packet1.failure_flags_byte6 , packet1.fault_code_byte7 , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_bms_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bms_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.temperatures , packet1.status , packet1.failure_flags_byte0 , packet1.failure_flags_byte1 , packet1.failure_flags_byte2 , packet1.failure_flags_byte3 , packet1.failure_flags_byte4 , packet1.failure_flags_byte5 , packet1.failure_flags_byte6 , packet1.fault_code_byte7 , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_bms_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_bms_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_bms_status_send(MAVLINK_COMM_1 , packet1.temperatures , packet1.status , packet1.failure_flags_byte0 , packet1.failure_flags_byte1 , packet1.failure_flags_byte2 , packet1.failure_flags_byte3 , packet1.failure_flags_byte4 , packet1.failure_flags_byte5 , packet1.failure_flags_byte6 , packet1.fault_code_byte7 , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_bms_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("BMS_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_BMS_STATUS) != NULL);
#endif
}

static void mavlink_test_ezkontrol_mcu_meter_data_i(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ezkontrol_mcu_meter_data_i_t packet_in = {
        963497464,17443,17547,17651,17755,41,108
    };
    mavlink_ezkontrol_mcu_meter_data_i_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp_seconds = packet_in.timestamp_seconds;
        packet1.bus_voltage = packet_in.bus_voltage;
        packet1.bus_current = packet_in.bus_current;
        packet1.rpm = packet_in.rpm;
        packet1.timestamp_milliseconds = packet_in.timestamp_milliseconds;
        packet1.accelerator_opening = packet_in.accelerator_opening;
        packet1.instance = packet_in.instance;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ezkontrol_mcu_meter_data_i_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ezkontrol_mcu_meter_data_i_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ezkontrol_mcu_meter_data_i_pack(system_id, component_id, &msg , packet1.bus_voltage , packet1.bus_current , packet1.rpm , packet1.accelerator_opening , packet1.instance , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_ezkontrol_mcu_meter_data_i_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ezkontrol_mcu_meter_data_i_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.bus_voltage , packet1.bus_current , packet1.rpm , packet1.accelerator_opening , packet1.instance , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_ezkontrol_mcu_meter_data_i_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ezkontrol_mcu_meter_data_i_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ezkontrol_mcu_meter_data_i_send(MAVLINK_COMM_1 , packet1.bus_voltage , packet1.bus_current , packet1.rpm , packet1.accelerator_opening , packet1.instance , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_ezkontrol_mcu_meter_data_i_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("EZKONTROL_MCU_METER_DATA_I") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I) != NULL);
#endif
}

static void mavlink_test_ezkontrol_mcu_meter_data_ii(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_ezkontrol_mcu_meter_data_ii_t packet_in = {
        963497464,17443,151,218,29,96,163,230,41,108
    };
    mavlink_ezkontrol_mcu_meter_data_ii_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp_seconds = packet_in.timestamp_seconds;
        packet1.timestamp_milliseconds = packet_in.timestamp_milliseconds;
        packet1.controller_temperature = packet_in.controller_temperature;
        packet1.motor_temperature = packet_in.motor_temperature;
        packet1.status = packet_in.status;
        packet1.error_flags_byte4 = packet_in.error_flags_byte4;
        packet1.error_flags_byte5 = packet_in.error_flags_byte5;
        packet1.error_flags_byte6 = packet_in.error_flags_byte6;
        packet1.life_signal = packet_in.life_signal;
        packet1.instance = packet_in.instance;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ezkontrol_mcu_meter_data_ii_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_ezkontrol_mcu_meter_data_ii_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ezkontrol_mcu_meter_data_ii_pack(system_id, component_id, &msg , packet1.controller_temperature , packet1.motor_temperature , packet1.status , packet1.error_flags_byte4 , packet1.error_flags_byte5 , packet1.error_flags_byte6 , packet1.life_signal , packet1.instance , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_ezkontrol_mcu_meter_data_ii_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ezkontrol_mcu_meter_data_ii_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.controller_temperature , packet1.motor_temperature , packet1.status , packet1.error_flags_byte4 , packet1.error_flags_byte5 , packet1.error_flags_byte6 , packet1.life_signal , packet1.instance , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_ezkontrol_mcu_meter_data_ii_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_ezkontrol_mcu_meter_data_ii_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_ezkontrol_mcu_meter_data_ii_send(MAVLINK_COMM_1 , packet1.controller_temperature , packet1.motor_temperature , packet1.status , packet1.error_flags_byte4 , packet1.error_flags_byte5 , packet1.error_flags_byte6 , packet1.life_signal , packet1.instance , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_ezkontrol_mcu_meter_data_ii_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("EZKONTROL_MCU_METER_DATA_II") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II) != NULL);
#endif
}

static void mavlink_test_pumps(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PUMPS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_pumps_t packet_in = {
        963497464,17443,151
    };
    mavlink_pumps_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp_seconds = packet_in.timestamp_seconds;
        packet1.timestamp_milliseconds = packet_in.timestamp_milliseconds;
        packet1.pump_states = packet_in.pump_states;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PUMPS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PUMPS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pumps_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_pumps_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pumps_pack(system_id, component_id, &msg , packet1.pump_states , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_pumps_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pumps_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.pump_states , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_pumps_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_pumps_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_pumps_send(MAVLINK_COMM_1 , packet1.pump_states , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_pumps_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("PUMPS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_PUMPS) != NULL);
#endif
}

static void mavlink_test_param_request_read(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PARAM_REQUEST_READ >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_param_request_read_t packet_in = {
        17235,"CDEFGHIJKLMNOPQ"
    };
    mavlink_param_request_read_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param_index = packet_in.param_index;
        
        mav_array_memcpy(packet1.param_id, packet_in.param_id, sizeof(char)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PARAM_REQUEST_READ_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PARAM_REQUEST_READ_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_request_read_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_param_request_read_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_request_read_pack(system_id, component_id, &msg , packet1.param_id , packet1.param_index );
    mavlink_msg_param_request_read_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_request_read_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.param_id , packet1.param_index );
    mavlink_msg_param_request_read_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_param_request_read_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_request_read_send(MAVLINK_COMM_1 , packet1.param_id , packet1.param_index );
    mavlink_msg_param_request_read_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("PARAM_REQUEST_READ") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_PARAM_REQUEST_READ) != NULL);
#endif
}

static void mavlink_test_param_value(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PARAM_VALUE >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_param_value_t packet_in = {
        17.0,17443,17547,"IJKLMNOPQRSTUVW",77
    };
    mavlink_param_value_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param_value = packet_in.param_value;
        packet1.param_count = packet_in.param_count;
        packet1.param_index = packet_in.param_index;
        packet1.param_type = packet_in.param_type;
        
        mav_array_memcpy(packet1.param_id, packet_in.param_id, sizeof(char)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PARAM_VALUE_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PARAM_VALUE_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_value_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_param_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_value_pack(system_id, component_id, &msg , packet1.param_id , packet1.param_value , packet1.param_type , packet1.param_count , packet1.param_index );
    mavlink_msg_param_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_value_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.param_id , packet1.param_value , packet1.param_type , packet1.param_count , packet1.param_index );
    mavlink_msg_param_value_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_param_value_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_value_send(MAVLINK_COMM_1 , packet1.param_id , packet1.param_value , packet1.param_type , packet1.param_count , packet1.param_index );
    mavlink_msg_param_value_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("PARAM_VALUE") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_PARAM_VALUE) != NULL);
#endif
}

static void mavlink_test_param_set(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_PARAM_SET >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_param_set_t packet_in = {
        17.0,"EFGHIJKLMNOPQRS",65
    };
    mavlink_param_set_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.param_value = packet_in.param_value;
        packet1.param_type = packet_in.param_type;
        
        mav_array_memcpy(packet1.param_id, packet_in.param_id, sizeof(char)*16);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_PARAM_SET_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_PARAM_SET_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_set_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_param_set_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_set_pack(system_id, component_id, &msg , packet1.param_id , packet1.param_value , packet1.param_type );
    mavlink_msg_param_set_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_set_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.param_id , packet1.param_value , packet1.param_type );
    mavlink_msg_param_set_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_param_set_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_param_set_send(MAVLINK_COMM_1 , packet1.param_id , packet1.param_value , packet1.param_type );
    mavlink_msg_param_set_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("PARAM_SET") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_PARAM_SET) != NULL);
#endif
}

static void mavlink_test_radio_status(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_RADIO_STATUS >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_radio_status_t packet_in = {
        963497464,17443,17547,29,96
    };
    mavlink_radio_status_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.timestamp_seconds = packet_in.timestamp_seconds;
        packet1.rxerrors = packet_in.rxerrors;
        packet1.timestamp_milliseconds = packet_in.timestamp_milliseconds;
        packet1.instance = packet_in.instance;
        packet1.rssi = packet_in.rssi;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_RADIO_STATUS_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_RADIO_STATUS_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_status_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_radio_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_status_pack(system_id, component_id, &msg , packet1.instance , packet1.rssi , packet1.rxerrors , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_radio_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_status_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.instance , packet1.rssi , packet1.rxerrors , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_radio_status_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_radio_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_radio_status_send(MAVLINK_COMM_1 , packet1.instance , packet1.rssi , packet1.rxerrors , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_radio_status_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("RADIO_STATUS") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_RADIO_STATUS) != NULL);
#endif
}

static void mavlink_test_named_value_float(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_NAMED_VALUE_FLOAT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_named_value_float_t packet_in = {
        963497464,45.0,963497880,17859,"OPQRSTUVW"
    };
    mavlink_named_value_float_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_boot_ms = packet_in.time_boot_ms;
        packet1.value = packet_in.value;
        packet1.timestamp_seconds = packet_in.timestamp_seconds;
        packet1.timestamp_milliseconds = packet_in.timestamp_milliseconds;
        
        mav_array_memcpy(packet1.name, packet_in.name, sizeof(char)*10);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_NAMED_VALUE_FLOAT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_NAMED_VALUE_FLOAT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_named_value_float_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_named_value_float_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_named_value_float_pack(system_id, component_id, &msg , packet1.time_boot_ms , packet1.name , packet1.value , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_named_value_float_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_named_value_float_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_boot_ms , packet1.name , packet1.value , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_named_value_float_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_named_value_float_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_named_value_float_send(MAVLINK_COMM_1 , packet1.time_boot_ms , packet1.name , packet1.value , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_named_value_float_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("NAMED_VALUE_FLOAT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_NAMED_VALUE_FLOAT) != NULL);
#endif
}

static void mavlink_test_named_value_int(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_NAMED_VALUE_INT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_named_value_int_t packet_in = {
        963497464,963497672,963497880,17859,"OPQRSTUVW"
    };
    mavlink_named_value_int_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_boot_ms = packet_in.time_boot_ms;
        packet1.value = packet_in.value;
        packet1.timestamp_seconds = packet_in.timestamp_seconds;
        packet1.timestamp_milliseconds = packet_in.timestamp_milliseconds;
        
        mav_array_memcpy(packet1.name, packet_in.name, sizeof(char)*10);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_NAMED_VALUE_INT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_NAMED_VALUE_INT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_named_value_int_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_named_value_int_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_named_value_int_pack(system_id, component_id, &msg , packet1.time_boot_ms , packet1.name , packet1.value , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_named_value_int_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_named_value_int_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_boot_ms , packet1.name , packet1.value , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_named_value_int_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_named_value_int_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_named_value_int_send(MAVLINK_COMM_1 , packet1.time_boot_ms , packet1.name , packet1.value , packet1.timestamp_seconds , packet1.timestamp_milliseconds );
    mavlink_msg_named_value_int_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("NAMED_VALUE_INT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_NAMED_VALUE_INT) != NULL);
#endif
}

static void mavlink_test_statustext(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_STATUSTEXT >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_statustext_t packet_in = {
        5,"BCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWX"
    };
    mavlink_statustext_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.severity = packet_in.severity;
        
        mav_array_memcpy(packet1.text, packet_in.text, sizeof(char)*50);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_STATUSTEXT_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_STATUSTEXT_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_statustext_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_statustext_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_statustext_pack(system_id, component_id, &msg , packet1.severity , packet1.text );
    mavlink_msg_statustext_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_statustext_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.severity , packet1.text );
    mavlink_msg_statustext_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_statustext_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_statustext_send(MAVLINK_COMM_1 , packet1.severity , packet1.text );
    mavlink_msg_statustext_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("STATUSTEXT") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_STATUSTEXT) != NULL);
#endif
}

static void mavlink_test_debug(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_DEBUG >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_debug_t packet_in = {
        963497464,45.0,29
    };
    mavlink_debug_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.time_boot_ms = packet_in.time_boot_ms;
        packet1.value = packet_in.value;
        packet1.ind = packet_in.ind;
        
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_DEBUG_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_DEBUG_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_debug_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_debug_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_debug_pack(system_id, component_id, &msg , packet1.time_boot_ms , packet1.ind , packet1.value );
    mavlink_msg_debug_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_debug_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_boot_ms , packet1.ind , packet1.value );
    mavlink_msg_debug_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_debug_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_debug_send(MAVLINK_COMM_1 , packet1.time_boot_ms , packet1.ind , packet1.value );
    mavlink_msg_debug_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

#ifdef MAVLINK_HAVE_GET_MESSAGE_INFO
    MAVLINK_ASSERT(mavlink_get_message_info_by_name("DEBUG") != NULL);
    MAVLINK_ASSERT(mavlink_get_message_info_by_id(MAVLINK_MSG_ID_DEBUG) != NULL);
#endif
}

static void mavlink_test_arariboat(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_instrumentation(system_id, component_id, last_msg);
    mavlink_test_temperatures(system_id, component_id, last_msg);
    mavlink_test_gps(system_id, component_id, last_msg);
    mavlink_test_mppt(system_id, component_id, last_msg);
    mavlink_test_mppt_state(system_id, component_id, last_msg);
    mavlink_test_bms(system_id, component_id, last_msg);
    mavlink_test_bms_status(system_id, component_id, last_msg);
    mavlink_test_ezkontrol_mcu_meter_data_i(system_id, component_id, last_msg);
    mavlink_test_ezkontrol_mcu_meter_data_ii(system_id, component_id, last_msg);
    mavlink_test_pumps(system_id, component_id, last_msg);
    mavlink_test_param_request_read(system_id, component_id, last_msg);
    mavlink_test_param_value(system_id, component_id, last_msg);
    mavlink_test_param_set(system_id, component_id, last_msg);
    mavlink_test_radio_status(system_id, component_id, last_msg);
    mavlink_test_named_value_float(system_id, component_id, last_msg);
    mavlink_test_named_value_int(system_id, component_id, last_msg);
    mavlink_test_statustext(system_id, component_id, last_msg);
    mavlink_test_debug(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // ARARIBOAT_TESTSUITE_H
