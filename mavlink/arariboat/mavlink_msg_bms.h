#pragma once
// MESSAGE BMS PACKING

#define MAVLINK_MSG_ID_BMS 6


typedef struct __mavlink_bms_t {
 uint32_t timestamp_seconds; /*<  Seconds since Unix time*/
 uint16_t voltages[16]; /*< [mV] Voltage of each cell.*/
 int16_t temperatures[2]; /*< [cdegC] Temperature of the battery*/
 int16_t current_battery; /*< [dA] Battery current*/
 uint16_t timestamp_milliseconds; /*<  Milliseconds within Unix time*/
 int8_t state_of_charge; /*< [%] Remaining battery energy. Values: [0-100]*/
} mavlink_bms_t;

#define MAVLINK_MSG_ID_BMS_LEN 45
#define MAVLINK_MSG_ID_BMS_MIN_LEN 45
#define MAVLINK_MSG_ID_6_LEN 45
#define MAVLINK_MSG_ID_6_MIN_LEN 45

#define MAVLINK_MSG_ID_BMS_CRC 65
#define MAVLINK_MSG_ID_6_CRC 65

#define MAVLINK_MSG_BMS_FIELD_VOLTAGES_LEN 16
#define MAVLINK_MSG_BMS_FIELD_TEMPERATURES_LEN 2

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_BMS { \
    6, \
    "BMS", \
    6, \
    {  { "voltages", NULL, MAVLINK_TYPE_UINT16_T, 16, 4, offsetof(mavlink_bms_t, voltages) }, \
         { "temperatures", NULL, MAVLINK_TYPE_INT16_T, 2, 36, offsetof(mavlink_bms_t, temperatures) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_bms_t, current_battery) }, \
         { "state_of_charge", NULL, MAVLINK_TYPE_INT8_T, 0, 44, offsetof(mavlink_bms_t, state_of_charge) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_bms_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_bms_t, timestamp_milliseconds) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_BMS { \
    "BMS", \
    6, \
    {  { "voltages", NULL, MAVLINK_TYPE_UINT16_T, 16, 4, offsetof(mavlink_bms_t, voltages) }, \
         { "temperatures", NULL, MAVLINK_TYPE_INT16_T, 2, 36, offsetof(mavlink_bms_t, temperatures) }, \
         { "current_battery", NULL, MAVLINK_TYPE_INT16_T, 0, 40, offsetof(mavlink_bms_t, current_battery) }, \
         { "state_of_charge", NULL, MAVLINK_TYPE_INT8_T, 0, 44, offsetof(mavlink_bms_t, state_of_charge) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_bms_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 42, offsetof(mavlink_bms_t, timestamp_milliseconds) }, \
         } \
}
#endif

/**
 * @brief Pack a bms message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param voltages [mV] Voltage of each cell.
 * @param temperatures [cdegC] Temperature of the battery
 * @param current_battery [dA] Battery current
 * @param state_of_charge [%] Remaining battery energy. Values: [0-100]
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bms_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const uint16_t *voltages, const int16_t *temperatures, int16_t current_battery, int8_t state_of_charge, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BMS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_int16_t(buf, 40, current_battery);
    _mav_put_uint16_t(buf, 42, timestamp_milliseconds);
    _mav_put_int8_t(buf, 44, state_of_charge);
    _mav_put_uint16_t_array(buf, 4, voltages, 16);
    _mav_put_int16_t_array(buf, 36, temperatures, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BMS_LEN);
#else
    mavlink_bms_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.current_battery = current_battery;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.state_of_charge = state_of_charge;
    mav_array_memcpy(packet.voltages, voltages, sizeof(uint16_t)*16);
    mav_array_memcpy(packet.temperatures, temperatures, sizeof(int16_t)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BMS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_BMS_MIN_LEN, MAVLINK_MSG_ID_BMS_LEN, MAVLINK_MSG_ID_BMS_CRC);
}

/**
 * @brief Pack a bms message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param voltages [mV] Voltage of each cell.
 * @param temperatures [cdegC] Temperature of the battery
 * @param current_battery [dA] Battery current
 * @param state_of_charge [%] Remaining battery energy. Values: [0-100]
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bms_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               const uint16_t *voltages, const int16_t *temperatures, int16_t current_battery, int8_t state_of_charge, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BMS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_int16_t(buf, 40, current_battery);
    _mav_put_uint16_t(buf, 42, timestamp_milliseconds);
    _mav_put_int8_t(buf, 44, state_of_charge);
    _mav_put_uint16_t_array(buf, 4, voltages, 16);
    _mav_put_int16_t_array(buf, 36, temperatures, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BMS_LEN);
#else
    mavlink_bms_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.current_battery = current_battery;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.state_of_charge = state_of_charge;
    mav_array_memcpy(packet.voltages, voltages, sizeof(uint16_t)*16);
    mav_array_memcpy(packet.temperatures, temperatures, sizeof(int16_t)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BMS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_BMS_MIN_LEN, MAVLINK_MSG_ID_BMS_LEN, MAVLINK_MSG_ID_BMS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_BMS_MIN_LEN, MAVLINK_MSG_ID_BMS_LEN);
#endif
}

/**
 * @brief Pack a bms message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param voltages [mV] Voltage of each cell.
 * @param temperatures [cdegC] Temperature of the battery
 * @param current_battery [dA] Battery current
 * @param state_of_charge [%] Remaining battery energy. Values: [0-100]
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_bms_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const uint16_t *voltages,const int16_t *temperatures,int16_t current_battery,int8_t state_of_charge,uint32_t timestamp_seconds,uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BMS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_int16_t(buf, 40, current_battery);
    _mav_put_uint16_t(buf, 42, timestamp_milliseconds);
    _mav_put_int8_t(buf, 44, state_of_charge);
    _mav_put_uint16_t_array(buf, 4, voltages, 16);
    _mav_put_int16_t_array(buf, 36, temperatures, 2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_BMS_LEN);
#else
    mavlink_bms_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.current_battery = current_battery;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.state_of_charge = state_of_charge;
    mav_array_memcpy(packet.voltages, voltages, sizeof(uint16_t)*16);
    mav_array_memcpy(packet.temperatures, temperatures, sizeof(int16_t)*2);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_BMS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_BMS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_BMS_MIN_LEN, MAVLINK_MSG_ID_BMS_LEN, MAVLINK_MSG_ID_BMS_CRC);
}

/**
 * @brief Encode a bms struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param bms C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bms_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_bms_t* bms)
{
    return mavlink_msg_bms_pack(system_id, component_id, msg, bms->voltages, bms->temperatures, bms->current_battery, bms->state_of_charge, bms->timestamp_seconds, bms->timestamp_milliseconds);
}

/**
 * @brief Encode a bms struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param bms C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bms_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_bms_t* bms)
{
    return mavlink_msg_bms_pack_chan(system_id, component_id, chan, msg, bms->voltages, bms->temperatures, bms->current_battery, bms->state_of_charge, bms->timestamp_seconds, bms->timestamp_milliseconds);
}

/**
 * @brief Encode a bms struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param bms C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_bms_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_bms_t* bms)
{
    return mavlink_msg_bms_pack_status(system_id, component_id, _status, msg,  bms->voltages, bms->temperatures, bms->current_battery, bms->state_of_charge, bms->timestamp_seconds, bms->timestamp_milliseconds);
}

/**
 * @brief Send a bms message
 * @param chan MAVLink channel to send the message
 *
 * @param voltages [mV] Voltage of each cell.
 * @param temperatures [cdegC] Temperature of the battery
 * @param current_battery [dA] Battery current
 * @param state_of_charge [%] Remaining battery energy. Values: [0-100]
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_bms_send(mavlink_channel_t chan, const uint16_t *voltages, const int16_t *temperatures, int16_t current_battery, int8_t state_of_charge, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_BMS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_int16_t(buf, 40, current_battery);
    _mav_put_uint16_t(buf, 42, timestamp_milliseconds);
    _mav_put_int8_t(buf, 44, state_of_charge);
    _mav_put_uint16_t_array(buf, 4, voltages, 16);
    _mav_put_int16_t_array(buf, 36, temperatures, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS, buf, MAVLINK_MSG_ID_BMS_MIN_LEN, MAVLINK_MSG_ID_BMS_LEN, MAVLINK_MSG_ID_BMS_CRC);
#else
    mavlink_bms_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.current_battery = current_battery;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.state_of_charge = state_of_charge;
    mav_array_memcpy(packet.voltages, voltages, sizeof(uint16_t)*16);
    mav_array_memcpy(packet.temperatures, temperatures, sizeof(int16_t)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS, (const char *)&packet, MAVLINK_MSG_ID_BMS_MIN_LEN, MAVLINK_MSG_ID_BMS_LEN, MAVLINK_MSG_ID_BMS_CRC);
#endif
}

/**
 * @brief Send a bms message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_bms_send_struct(mavlink_channel_t chan, const mavlink_bms_t* bms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_bms_send(chan, bms->voltages, bms->temperatures, bms->current_battery, bms->state_of_charge, bms->timestamp_seconds, bms->timestamp_milliseconds);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS, (const char *)bms, MAVLINK_MSG_ID_BMS_MIN_LEN, MAVLINK_MSG_ID_BMS_LEN, MAVLINK_MSG_ID_BMS_CRC);
#endif
}

#if MAVLINK_MSG_ID_BMS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_bms_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const uint16_t *voltages, const int16_t *temperatures, int16_t current_battery, int8_t state_of_charge, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_int16_t(buf, 40, current_battery);
    _mav_put_uint16_t(buf, 42, timestamp_milliseconds);
    _mav_put_int8_t(buf, 44, state_of_charge);
    _mav_put_uint16_t_array(buf, 4, voltages, 16);
    _mav_put_int16_t_array(buf, 36, temperatures, 2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS, buf, MAVLINK_MSG_ID_BMS_MIN_LEN, MAVLINK_MSG_ID_BMS_LEN, MAVLINK_MSG_ID_BMS_CRC);
#else
    mavlink_bms_t *packet = (mavlink_bms_t *)msgbuf;
    packet->timestamp_seconds = timestamp_seconds;
    packet->current_battery = current_battery;
    packet->timestamp_milliseconds = timestamp_milliseconds;
    packet->state_of_charge = state_of_charge;
    mav_array_memcpy(packet->voltages, voltages, sizeof(uint16_t)*16);
    mav_array_memcpy(packet->temperatures, temperatures, sizeof(int16_t)*2);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_BMS, (const char *)packet, MAVLINK_MSG_ID_BMS_MIN_LEN, MAVLINK_MSG_ID_BMS_LEN, MAVLINK_MSG_ID_BMS_CRC);
#endif
}
#endif

#endif

// MESSAGE BMS UNPACKING


/**
 * @brief Get field voltages from bms message
 *
 * @return [mV] Voltage of each cell.
 */
static inline uint16_t mavlink_msg_bms_get_voltages(const mavlink_message_t* msg, uint16_t *voltages)
{
    return _MAV_RETURN_uint16_t_array(msg, voltages, 16,  4);
}

/**
 * @brief Get field temperatures from bms message
 *
 * @return [cdegC] Temperature of the battery
 */
static inline uint16_t mavlink_msg_bms_get_temperatures(const mavlink_message_t* msg, int16_t *temperatures)
{
    return _MAV_RETURN_int16_t_array(msg, temperatures, 2,  36);
}

/**
 * @brief Get field current_battery from bms message
 *
 * @return [dA] Battery current
 */
static inline int16_t mavlink_msg_bms_get_current_battery(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  40);
}

/**
 * @brief Get field state_of_charge from bms message
 *
 * @return [%] Remaining battery energy. Values: [0-100]
 */
static inline int8_t mavlink_msg_bms_get_state_of_charge(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  44);
}

/**
 * @brief Get field timestamp_seconds from bms message
 *
 * @return  Seconds since Unix time
 */
static inline uint32_t mavlink_msg_bms_get_timestamp_seconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field timestamp_milliseconds from bms message
 *
 * @return  Milliseconds within Unix time
 */
static inline uint16_t mavlink_msg_bms_get_timestamp_milliseconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  42);
}

/**
 * @brief Decode a bms message into a struct
 *
 * @param msg The message to decode
 * @param bms C-struct to decode the message contents into
 */
static inline void mavlink_msg_bms_decode(const mavlink_message_t* msg, mavlink_bms_t* bms)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    bms->timestamp_seconds = mavlink_msg_bms_get_timestamp_seconds(msg);
    mavlink_msg_bms_get_voltages(msg, bms->voltages);
    mavlink_msg_bms_get_temperatures(msg, bms->temperatures);
    bms->current_battery = mavlink_msg_bms_get_current_battery(msg);
    bms->timestamp_milliseconds = mavlink_msg_bms_get_timestamp_milliseconds(msg);
    bms->state_of_charge = mavlink_msg_bms_get_state_of_charge(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_BMS_LEN? msg->len : MAVLINK_MSG_ID_BMS_LEN;
        memset(bms, 0, MAVLINK_MSG_ID_BMS_LEN);
    memcpy(bms, _MAV_PAYLOAD(msg), len);
#endif
}
