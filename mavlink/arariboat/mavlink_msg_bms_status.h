#pragma once
// MESSAGE BMS_STATUS PACKING

#define MAVLINK_MSG_ID_BMS_STATUS 7


typedef struct __mavlink_bms_status_t {
 uint32_t timestamp_seconds; /*<  Seconds since Unix time*/
 int16_t temperatures[2]; /*< [cdegC] Temperature of the battery*/
 uint16_t timestamp_milliseconds; /*<  Milliseconds within Unix time*/
 uint8_t status; /*<  Charge/Discharge FET status and current charging status*/
 uint8_t failure_flags_byte0; /*<  Failure flags: Voltage related (Byte 0).*/
 uint8_t failure_flags_byte1; /*<  Failure flags: Temperature related (Byte 1).*/
 uint8_t failure_flags_byte2; /*<  Failure flags: Current and SOC related (Byte 2).*/
 uint8_t failure_flags_byte3; /*<  Failure flags: Differential V/T related (Byte 3).*/
 uint8_t failure_flags_byte4; /*<  Failure flags: MOSFET and sensor related (Byte 4).*/
 uint8_t failure_flags_byte5; /*<  Failure flags: System/Component related (Byte 5).*/
 uint8_t failure_flags_byte6; /*<  Failure flags: Other faults (Byte 6).*/
 uint8_t fault_code_byte7; /*<  Raw fault code (Byte 7 from original message).*/
} mavlink_bms_status_t;

#define MAVLINK_MSG_ID_BMS_STATUS_LEN 19
#define MAVLINK_MSG_ID_BMS_STATUS_MIN_LEN 19
#define MAVLINK_MSG_ID_7_LEN 19
#define MAVLINK_MSG_ID_7_MIN_LEN 19

#define MAVLINK_MSG_ID_BMS_STATUS_CRC 161
#define MAVLINK_MSG_ID_7_CRC 161

#define MAVLINK_MSG_BMS_STATUS_FIELD_TEMPERATURES_LEN 2

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BMS_STATUS { \
    7, \
    "BMS_STATUS", \
    12, \
    {  { "temperatures", NULL, MAVLINK_TYPE_INT16_T, 2, 4, offsetof(mavlink_bms_status_t, temperatures) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_bms_status_t, status) }, \
         { "failure_flags_byte0", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_bms_status_t, failure_flags_byte0) }, \
         { "failure_flags_byte1", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_bms_status_t, failure_flags_byte1) }, \
         { "failure_flags_byte2", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_bms_status_t, failure_flags_byte2) }, \
         { "failure_flags_byte3", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_bms_status_t, failure_flags_byte3) }, \
         { "failure_flags_byte4", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_bms_status_t, failure_flags_byte4) }, \
         { "failure_flags_byte5", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_bms_status_t, failure_flags_byte5) }, \
         { "failure_flags_byte6", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_bms_status_t, failure_flags_byte6) }, \
         { "fault_code_byte7", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_bms_status_t, fault_code_byte7) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_bms_status_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_bms_status_t, timestamp_milliseconds) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BMS_STATUS { \
    "BMS_STATUS", \
    12, \
    {  { "temperatures", NULL, MAVLINK_TYPE_INT16_T, 2, 4, offsetof(mavlink_bms_status_t, temperatures) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_bms_status_t, status) }, \
         { "failure_flags_byte0", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_bms_status_t, failure_flags_byte0) }, \
         { "failure_flags_byte1", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_bms_status_t, failure_flags_byte1) }, \
         { "failure_flags_byte2", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_bms_status_t, failure_flags_byte2) }, \
         { "failure_flags_byte3", NULL, MAVLINK_TYPE_UINT8_T, 0, 14, offsetof(mavlink_bms_status_t, failure_flags_byte3) }, \
         { "failure_flags_byte4", NULL, MAVLINK_TYPE_UINT8_T, 0, 15, offsetof(mavlink_bms_status_t, failure_flags_byte4) }, \
         { "failure_flags_byte5", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_bms_status_t, failure_flags_byte5) }, \
         { "failure_flags_byte6", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_bms_status_t, failure_flags_byte6) }, \
         { "fault_code_byte7", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_bms_status_t, fault_code_byte7) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_bms_status_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_bms_status_t, timestamp_milliseconds) }, \
         } \
}
#endif

/**
 * @brief Pack a bms_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param temperatures [cdegC] Temperature of the battery
 * @param status  Charge/Discharge FET status and current charging status
 * @param failure_flags_byte0  Failure flags: Voltage related (Byte 0).
 * @param failure_flags_byte1  Failure flags: Temperature related (Byte 1).
 * @param failure_flags_byte2  Failure flags: Current and SOC related (Byte 2).
 * @param failure_flags_byte3  Failure flags: Differential V/T related (Byte 3).
 * @param failure_flags_byte4  Failure flags: MOSFET and sensor related (Byte 4).
 * @param failure_flags_byte5  Failure flags: System/Component related (Byte 5).
 * @param failure_flags_byte6  Failure flags: Other faults (Byte 6).
 * @param fault_code_byte7  Raw fault code (Byte 7 from original message).
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bms_status_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const int16_t *temperatures, uint8_t status, uint8_t failure_flags_byte0, uint8_t failure_flags_byte1, uint8_t failure_flags_byte2, uint8_t failure_flags_byte3, uint8_t failure_flags_byte4, uint8_t failure_flags_byte5, uint8_t failure_flags_byte6, uint8_t fault_code_byte7, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BMS_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 8, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 10, status);
    _mav_put_uint8_t(buf, 11, failure_flags_byte0);
    _mav_put_uint8_t(buf, 12, failure_flags_byte1);
    _mav_put_uint8_t(buf, 13, failure_flags_byte2);
    _mav_put_uint8_t(buf, 14, failure_flags_byte3);
    _mav_put_uint8_t(buf, 15, failure_flags_byte4);
    _mav_put_uint8_t(buf, 16, failure_flags_byte5);
    _mav_put_uint8_t(buf, 17, failure_flags_byte6);
    _mav_put_uint8_t(buf, 18, fault_code_byte7);
    _mav_put_int16_t_array(buf, 4, temperatures, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BMS_STATUS_LEN);
#else
    mavlink_bms_status_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.status = status;
    packet.failure_flags_byte0 = failure_flags_byte0;
    packet.failure_flags_byte1 = failure_flags_byte1;
    packet.failure_flags_byte2 = failure_flags_byte2;
    packet.failure_flags_byte3 = failure_flags_byte3;
    packet.failure_flags_byte4 = failure_flags_byte4;
    packet.failure_flags_byte5 = failure_flags_byte5;
    packet.failure_flags_byte6 = failure_flags_byte6;
    packet.fault_code_byte7 = fault_code_byte7;
    mav_array_memcpy(packet.temperatures, temperatures, sizeof(int16_t)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BMS_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BMS_STATUS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_BMS_STATUS_LEN, MAVLINK_MSG_ID_BMS_STATUS_CRC);
}

/**
 * @brief Pack a bms_status message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param temperatures [cdegC] Temperature of the battery
 * @param status  Charge/Discharge FET status and current charging status
 * @param failure_flags_byte0  Failure flags: Voltage related (Byte 0).
 * @param failure_flags_byte1  Failure flags: Temperature related (Byte 1).
 * @param failure_flags_byte2  Failure flags: Current and SOC related (Byte 2).
 * @param failure_flags_byte3  Failure flags: Differential V/T related (Byte 3).
 * @param failure_flags_byte4  Failure flags: MOSFET and sensor related (Byte 4).
 * @param failure_flags_byte5  Failure flags: System/Component related (Byte 5).
 * @param failure_flags_byte6  Failure flags: Other faults (Byte 6).
 * @param fault_code_byte7  Raw fault code (Byte 7 from original message).
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bms_status_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               const int16_t *temperatures, uint8_t status, uint8_t failure_flags_byte0, uint8_t failure_flags_byte1, uint8_t failure_flags_byte2, uint8_t failure_flags_byte3, uint8_t failure_flags_byte4, uint8_t failure_flags_byte5, uint8_t failure_flags_byte6, uint8_t fault_code_byte7, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BMS_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 8, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 10, status);
    _mav_put_uint8_t(buf, 11, failure_flags_byte0);
    _mav_put_uint8_t(buf, 12, failure_flags_byte1);
    _mav_put_uint8_t(buf, 13, failure_flags_byte2);
    _mav_put_uint8_t(buf, 14, failure_flags_byte3);
    _mav_put_uint8_t(buf, 15, failure_flags_byte4);
    _mav_put_uint8_t(buf, 16, failure_flags_byte5);
    _mav_put_uint8_t(buf, 17, failure_flags_byte6);
    _mav_put_uint8_t(buf, 18, fault_code_byte7);
    _mav_put_int16_t_array(buf, 4, temperatures, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BMS_STATUS_LEN);
#else
    mavlink_bms_status_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.status = status;
    packet.failure_flags_byte0 = failure_flags_byte0;
    packet.failure_flags_byte1 = failure_flags_byte1;
    packet.failure_flags_byte2 = failure_flags_byte2;
    packet.failure_flags_byte3 = failure_flags_byte3;
    packet.failure_flags_byte4 = failure_flags_byte4;
    packet.failure_flags_byte5 = failure_flags_byte5;
    packet.failure_flags_byte6 = failure_flags_byte6;
    packet.fault_code_byte7 = fault_code_byte7;
    mav_array_memcpy(packet.temperatures, temperatures, sizeof(int16_t)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BMS_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BMS_STATUS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_BMS_STATUS_LEN, MAVLINK_MSG_ID_BMS_STATUS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_BMS_STATUS_LEN);
#endif
}

/**
 * @brief Pack a bms_status message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param temperatures [cdegC] Temperature of the battery
 * @param status  Charge/Discharge FET status and current charging status
 * @param failure_flags_byte0  Failure flags: Voltage related (Byte 0).
 * @param failure_flags_byte1  Failure flags: Temperature related (Byte 1).
 * @param failure_flags_byte2  Failure flags: Current and SOC related (Byte 2).
 * @param failure_flags_byte3  Failure flags: Differential V/T related (Byte 3).
 * @param failure_flags_byte4  Failure flags: MOSFET and sensor related (Byte 4).
 * @param failure_flags_byte5  Failure flags: System/Component related (Byte 5).
 * @param failure_flags_byte6  Failure flags: Other faults (Byte 6).
 * @param fault_code_byte7  Raw fault code (Byte 7 from original message).
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bms_status_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const int16_t *temperatures,uint8_t status,uint8_t failure_flags_byte0,uint8_t failure_flags_byte1,uint8_t failure_flags_byte2,uint8_t failure_flags_byte3,uint8_t failure_flags_byte4,uint8_t failure_flags_byte5,uint8_t failure_flags_byte6,uint8_t fault_code_byte7,uint32_t timestamp_seconds,uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BMS_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 8, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 10, status);
    _mav_put_uint8_t(buf, 11, failure_flags_byte0);
    _mav_put_uint8_t(buf, 12, failure_flags_byte1);
    _mav_put_uint8_t(buf, 13, failure_flags_byte2);
    _mav_put_uint8_t(buf, 14, failure_flags_byte3);
    _mav_put_uint8_t(buf, 15, failure_flags_byte4);
    _mav_put_uint8_t(buf, 16, failure_flags_byte5);
    _mav_put_uint8_t(buf, 17, failure_flags_byte6);
    _mav_put_uint8_t(buf, 18, fault_code_byte7);
    _mav_put_int16_t_array(buf, 4, temperatures, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BMS_STATUS_LEN);
#else
    mavlink_bms_status_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.status = status;
    packet.failure_flags_byte0 = failure_flags_byte0;
    packet.failure_flags_byte1 = failure_flags_byte1;
    packet.failure_flags_byte2 = failure_flags_byte2;
    packet.failure_flags_byte3 = failure_flags_byte3;
    packet.failure_flags_byte4 = failure_flags_byte4;
    packet.failure_flags_byte5 = failure_flags_byte5;
    packet.failure_flags_byte6 = failure_flags_byte6;
    packet.fault_code_byte7 = fault_code_byte7;
    mav_array_memcpy(packet.temperatures, temperatures, sizeof(int16_t)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BMS_STATUS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BMS_STATUS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_BMS_STATUS_LEN, MAVLINK_MSG_ID_BMS_STATUS_CRC);
}

/**
 * @brief Encode a bms_status struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param bms_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bms_status_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_bms_status_t* bms_status)
{
    return mavlink_msg_bms_status_pack(system_id, component_id, msg, bms_status->temperatures, bms_status->status, bms_status->failure_flags_byte0, bms_status->failure_flags_byte1, bms_status->failure_flags_byte2, bms_status->failure_flags_byte3, bms_status->failure_flags_byte4, bms_status->failure_flags_byte5, bms_status->failure_flags_byte6, bms_status->fault_code_byte7, bms_status->timestamp_seconds, bms_status->timestamp_milliseconds);
}

/**
 * @brief Encode a bms_status struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param bms_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bms_status_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_bms_status_t* bms_status)
{
    return mavlink_msg_bms_status_pack_chan(system_id, component_id, chan, msg, bms_status->temperatures, bms_status->status, bms_status->failure_flags_byte0, bms_status->failure_flags_byte1, bms_status->failure_flags_byte2, bms_status->failure_flags_byte3, bms_status->failure_flags_byte4, bms_status->failure_flags_byte5, bms_status->failure_flags_byte6, bms_status->fault_code_byte7, bms_status->timestamp_seconds, bms_status->timestamp_milliseconds);
}

/**
 * @brief Encode a bms_status struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param bms_status C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bms_status_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_bms_status_t* bms_status)
{
    return mavlink_msg_bms_status_pack_status(system_id, component_id, _status, msg,  bms_status->temperatures, bms_status->status, bms_status->failure_flags_byte0, bms_status->failure_flags_byte1, bms_status->failure_flags_byte2, bms_status->failure_flags_byte3, bms_status->failure_flags_byte4, bms_status->failure_flags_byte5, bms_status->failure_flags_byte6, bms_status->fault_code_byte7, bms_status->timestamp_seconds, bms_status->timestamp_milliseconds);
}

/**
 * @brief Send a bms_status message
 * @param chan MAVLink channel to send the message
 *
 * @param temperatures [cdegC] Temperature of the battery
 * @param status  Charge/Discharge FET status and current charging status
 * @param failure_flags_byte0  Failure flags: Voltage related (Byte 0).
 * @param failure_flags_byte1  Failure flags: Temperature related (Byte 1).
 * @param failure_flags_byte2  Failure flags: Current and SOC related (Byte 2).
 * @param failure_flags_byte3  Failure flags: Differential V/T related (Byte 3).
 * @param failure_flags_byte4  Failure flags: MOSFET and sensor related (Byte 4).
 * @param failure_flags_byte5  Failure flags: System/Component related (Byte 5).
 * @param failure_flags_byte6  Failure flags: Other faults (Byte 6).
 * @param fault_code_byte7  Raw fault code (Byte 7 from original message).
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_bms_status_send(mavlink_channel_t chan, const int16_t *temperatures, uint8_t status, uint8_t failure_flags_byte0, uint8_t failure_flags_byte1, uint8_t failure_flags_byte2, uint8_t failure_flags_byte3, uint8_t failure_flags_byte4, uint8_t failure_flags_byte5, uint8_t failure_flags_byte6, uint8_t fault_code_byte7, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BMS_STATUS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 8, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 10, status);
    _mav_put_uint8_t(buf, 11, failure_flags_byte0);
    _mav_put_uint8_t(buf, 12, failure_flags_byte1);
    _mav_put_uint8_t(buf, 13, failure_flags_byte2);
    _mav_put_uint8_t(buf, 14, failure_flags_byte3);
    _mav_put_uint8_t(buf, 15, failure_flags_byte4);
    _mav_put_uint8_t(buf, 16, failure_flags_byte5);
    _mav_put_uint8_t(buf, 17, failure_flags_byte6);
    _mav_put_uint8_t(buf, 18, fault_code_byte7);
    _mav_put_int16_t_array(buf, 4, temperatures, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS_STATUS, buf, MAVLINK_MSG_ID_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_BMS_STATUS_LEN, MAVLINK_MSG_ID_BMS_STATUS_CRC);
#else
    mavlink_bms_status_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.status = status;
    packet.failure_flags_byte0 = failure_flags_byte0;
    packet.failure_flags_byte1 = failure_flags_byte1;
    packet.failure_flags_byte2 = failure_flags_byte2;
    packet.failure_flags_byte3 = failure_flags_byte3;
    packet.failure_flags_byte4 = failure_flags_byte4;
    packet.failure_flags_byte5 = failure_flags_byte5;
    packet.failure_flags_byte6 = failure_flags_byte6;
    packet.fault_code_byte7 = fault_code_byte7;
    mav_array_memcpy(packet.temperatures, temperatures, sizeof(int16_t)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS_STATUS, (const char *)&packet, MAVLINK_MSG_ID_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_BMS_STATUS_LEN, MAVLINK_MSG_ID_BMS_STATUS_CRC);
#endif
}

/**
 * @brief Send a bms_status message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_bms_status_send_struct(mavlink_channel_t chan, const mavlink_bms_status_t* bms_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_bms_status_send(chan, bms_status->temperatures, bms_status->status, bms_status->failure_flags_byte0, bms_status->failure_flags_byte1, bms_status->failure_flags_byte2, bms_status->failure_flags_byte3, bms_status->failure_flags_byte4, bms_status->failure_flags_byte5, bms_status->failure_flags_byte6, bms_status->fault_code_byte7, bms_status->timestamp_seconds, bms_status->timestamp_milliseconds);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS_STATUS, (const char *)bms_status, MAVLINK_MSG_ID_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_BMS_STATUS_LEN, MAVLINK_MSG_ID_BMS_STATUS_CRC);
#endif
}

#if MAVLINK_MSG_ID_BMS_STATUS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_bms_status_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const int16_t *temperatures, uint8_t status, uint8_t failure_flags_byte0, uint8_t failure_flags_byte1, uint8_t failure_flags_byte2, uint8_t failure_flags_byte3, uint8_t failure_flags_byte4, uint8_t failure_flags_byte5, uint8_t failure_flags_byte6, uint8_t fault_code_byte7, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 8, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 10, status);
    _mav_put_uint8_t(buf, 11, failure_flags_byte0);
    _mav_put_uint8_t(buf, 12, failure_flags_byte1);
    _mav_put_uint8_t(buf, 13, failure_flags_byte2);
    _mav_put_uint8_t(buf, 14, failure_flags_byte3);
    _mav_put_uint8_t(buf, 15, failure_flags_byte4);
    _mav_put_uint8_t(buf, 16, failure_flags_byte5);
    _mav_put_uint8_t(buf, 17, failure_flags_byte6);
    _mav_put_uint8_t(buf, 18, fault_code_byte7);
    _mav_put_int16_t_array(buf, 4, temperatures, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS_STATUS, buf, MAVLINK_MSG_ID_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_BMS_STATUS_LEN, MAVLINK_MSG_ID_BMS_STATUS_CRC);
#else
    mavlink_bms_status_t *packet = (mavlink_bms_status_t *)msgbuf;
    packet->timestamp_seconds = timestamp_seconds;
    packet->timestamp_milliseconds = timestamp_milliseconds;
    packet->status = status;
    packet->failure_flags_byte0 = failure_flags_byte0;
    packet->failure_flags_byte1 = failure_flags_byte1;
    packet->failure_flags_byte2 = failure_flags_byte2;
    packet->failure_flags_byte3 = failure_flags_byte3;
    packet->failure_flags_byte4 = failure_flags_byte4;
    packet->failure_flags_byte5 = failure_flags_byte5;
    packet->failure_flags_byte6 = failure_flags_byte6;
    packet->fault_code_byte7 = fault_code_byte7;
    mav_array_memcpy(packet->temperatures, temperatures, sizeof(int16_t)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS_STATUS, (const char *)packet, MAVLINK_MSG_ID_BMS_STATUS_MIN_LEN, MAVLINK_MSG_ID_BMS_STATUS_LEN, MAVLINK_MSG_ID_BMS_STATUS_CRC);
#endif
}
#endif

#endif

// MESSAGE BMS_STATUS UNPACKING


/**
 * @brief Get field temperatures from bms_status message
 *
 * @return [cdegC] Temperature of the battery
 */
static inline uint16_t mavlink_msg_bms_status_get_temperatures(const mavlink_message_t* msg, int16_t *temperatures)
{
    return _MAV_RETURN_int16_t_array(msg, temperatures, 2,  4);
}

/**
 * @brief Get field status from bms_status message
 *
 * @return  Charge/Discharge FET status and current charging status
 */
static inline uint8_t mavlink_msg_bms_status_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field failure_flags_byte0 from bms_status message
 *
 * @return  Failure flags: Voltage related (Byte 0).
 */
static inline uint8_t mavlink_msg_bms_status_get_failure_flags_byte0(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field failure_flags_byte1 from bms_status message
 *
 * @return  Failure flags: Temperature related (Byte 1).
 */
static inline uint8_t mavlink_msg_bms_status_get_failure_flags_byte1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field failure_flags_byte2 from bms_status message
 *
 * @return  Failure flags: Current and SOC related (Byte 2).
 */
static inline uint8_t mavlink_msg_bms_status_get_failure_flags_byte2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field failure_flags_byte3 from bms_status message
 *
 * @return  Failure flags: Differential V/T related (Byte 3).
 */
static inline uint8_t mavlink_msg_bms_status_get_failure_flags_byte3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  14);
}

/**
 * @brief Get field failure_flags_byte4 from bms_status message
 *
 * @return  Failure flags: MOSFET and sensor related (Byte 4).
 */
static inline uint8_t mavlink_msg_bms_status_get_failure_flags_byte4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  15);
}

/**
 * @brief Get field failure_flags_byte5 from bms_status message
 *
 * @return  Failure flags: System/Component related (Byte 5).
 */
static inline uint8_t mavlink_msg_bms_status_get_failure_flags_byte5(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field failure_flags_byte6 from bms_status message
 *
 * @return  Failure flags: Other faults (Byte 6).
 */
static inline uint8_t mavlink_msg_bms_status_get_failure_flags_byte6(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field fault_code_byte7 from bms_status message
 *
 * @return  Raw fault code (Byte 7 from original message).
 */
static inline uint8_t mavlink_msg_bms_status_get_fault_code_byte7(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field timestamp_seconds from bms_status message
 *
 * @return  Seconds since Unix time
 */
static inline uint32_t mavlink_msg_bms_status_get_timestamp_seconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field timestamp_milliseconds from bms_status message
 *
 * @return  Milliseconds within Unix time
 */
static inline uint16_t mavlink_msg_bms_status_get_timestamp_milliseconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Decode a bms_status message into a struct
 *
 * @param msg The message to decode
 * @param bms_status C-struct to decode the message contents into
 */
static inline void mavlink_msg_bms_status_decode(const mavlink_message_t* msg, mavlink_bms_status_t* bms_status)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    bms_status->timestamp_seconds = mavlink_msg_bms_status_get_timestamp_seconds(msg);
    mavlink_msg_bms_status_get_temperatures(msg, bms_status->temperatures);
    bms_status->timestamp_milliseconds = mavlink_msg_bms_status_get_timestamp_milliseconds(msg);
    bms_status->status = mavlink_msg_bms_status_get_status(msg);
    bms_status->failure_flags_byte0 = mavlink_msg_bms_status_get_failure_flags_byte0(msg);
    bms_status->failure_flags_byte1 = mavlink_msg_bms_status_get_failure_flags_byte1(msg);
    bms_status->failure_flags_byte2 = mavlink_msg_bms_status_get_failure_flags_byte2(msg);
    bms_status->failure_flags_byte3 = mavlink_msg_bms_status_get_failure_flags_byte3(msg);
    bms_status->failure_flags_byte4 = mavlink_msg_bms_status_get_failure_flags_byte4(msg);
    bms_status->failure_flags_byte5 = mavlink_msg_bms_status_get_failure_flags_byte5(msg);
    bms_status->failure_flags_byte6 = mavlink_msg_bms_status_get_failure_flags_byte6(msg);
    bms_status->fault_code_byte7 = mavlink_msg_bms_status_get_fault_code_byte7(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_BMS_STATUS_LEN? msg->len : MAVLINK_MSG_ID_BMS_STATUS_LEN;
        memset(bms_status, 0, MAVLINK_MSG_ID_BMS_STATUS_LEN);
    memcpy(bms_status, _MAV_PAYLOAD(msg), len);
#endif
}
