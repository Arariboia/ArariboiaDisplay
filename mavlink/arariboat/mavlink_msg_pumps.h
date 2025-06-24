#pragma once
// MESSAGE PUMPS PACKING

#define MAVLINK_MSG_ID_PUMPS 10


typedef struct __mavlink_pumps_t {
 uint32_t timestamp_seconds; /*<  Seconds since Unix time*/
 uint16_t timestamp_milliseconds; /*<  Milliseconds within Unix time*/
 uint8_t pump_states; /*<  Bitmask of pump states. Bit 0: Pump Left, Bit 1: Pump Right*/
} mavlink_pumps_t;

#define MAVLINK_MSG_ID_PUMPS_LEN 7
#define MAVLINK_MSG_ID_PUMPS_MIN_LEN 7
#define MAVLINK_MSG_ID_10_LEN 7
#define MAVLINK_MSG_ID_10_MIN_LEN 7

#define MAVLINK_MSG_ID_PUMPS_CRC 246
#define MAVLINK_MSG_ID_10_CRC 246



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_PUMPS { \
    10, \
    "PUMPS", \
    3, \
    {  { "pump_states", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_pumps_t, pump_states) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_pumps_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_pumps_t, timestamp_milliseconds) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_PUMPS { \
    "PUMPS", \
    3, \
    {  { "pump_states", NULL, MAVLINK_TYPE_UINT8_T, 0, 6, offsetof(mavlink_pumps_t, pump_states) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_pumps_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_pumps_t, timestamp_milliseconds) }, \
         } \
}
#endif

/**
 * @brief Pack a pumps message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param pump_states  Bitmask of pump states. Bit 0: Pump Left, Bit 1: Pump Right
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pumps_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t pump_states, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PUMPS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 6, pump_states);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PUMPS_LEN);
#else
    mavlink_pumps_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.pump_states = pump_states;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PUMPS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PUMPS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_PUMPS_MIN_LEN, MAVLINK_MSG_ID_PUMPS_LEN, MAVLINK_MSG_ID_PUMPS_CRC);
}

/**
 * @brief Pack a pumps message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param pump_states  Bitmask of pump states. Bit 0: Pump Left, Bit 1: Pump Right
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pumps_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint8_t pump_states, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PUMPS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 6, pump_states);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PUMPS_LEN);
#else
    mavlink_pumps_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.pump_states = pump_states;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PUMPS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PUMPS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_PUMPS_MIN_LEN, MAVLINK_MSG_ID_PUMPS_LEN, MAVLINK_MSG_ID_PUMPS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_PUMPS_MIN_LEN, MAVLINK_MSG_ID_PUMPS_LEN);
#endif
}

/**
 * @brief Pack a pumps message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pump_states  Bitmask of pump states. Bit 0: Pump Left, Bit 1: Pump Right
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_pumps_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t pump_states,uint32_t timestamp_seconds,uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PUMPS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 6, pump_states);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_PUMPS_LEN);
#else
    mavlink_pumps_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.pump_states = pump_states;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_PUMPS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_PUMPS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_PUMPS_MIN_LEN, MAVLINK_MSG_ID_PUMPS_LEN, MAVLINK_MSG_ID_PUMPS_CRC);
}

/**
 * @brief Encode a pumps struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param pumps C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pumps_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_pumps_t* pumps)
{
    return mavlink_msg_pumps_pack(system_id, component_id, msg, pumps->pump_states, pumps->timestamp_seconds, pumps->timestamp_milliseconds);
}

/**
 * @brief Encode a pumps struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pumps C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pumps_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_pumps_t* pumps)
{
    return mavlink_msg_pumps_pack_chan(system_id, component_id, chan, msg, pumps->pump_states, pumps->timestamp_seconds, pumps->timestamp_milliseconds);
}

/**
 * @brief Encode a pumps struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param pumps C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_pumps_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_pumps_t* pumps)
{
    return mavlink_msg_pumps_pack_status(system_id, component_id, _status, msg,  pumps->pump_states, pumps->timestamp_seconds, pumps->timestamp_milliseconds);
}

/**
 * @brief Send a pumps message
 * @param chan MAVLink channel to send the message
 *
 * @param pump_states  Bitmask of pump states. Bit 0: Pump Left, Bit 1: Pump Right
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_pumps_send(mavlink_channel_t chan, uint8_t pump_states, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_PUMPS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 6, pump_states);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PUMPS, buf, MAVLINK_MSG_ID_PUMPS_MIN_LEN, MAVLINK_MSG_ID_PUMPS_LEN, MAVLINK_MSG_ID_PUMPS_CRC);
#else
    mavlink_pumps_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.pump_states = pump_states;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PUMPS, (const char *)&packet, MAVLINK_MSG_ID_PUMPS_MIN_LEN, MAVLINK_MSG_ID_PUMPS_LEN, MAVLINK_MSG_ID_PUMPS_CRC);
#endif
}

/**
 * @brief Send a pumps message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_pumps_send_struct(mavlink_channel_t chan, const mavlink_pumps_t* pumps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_pumps_send(chan, pumps->pump_states, pumps->timestamp_seconds, pumps->timestamp_milliseconds);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PUMPS, (const char *)pumps, MAVLINK_MSG_ID_PUMPS_MIN_LEN, MAVLINK_MSG_ID_PUMPS_LEN, MAVLINK_MSG_ID_PUMPS_CRC);
#endif
}

#if MAVLINK_MSG_ID_PUMPS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_pumps_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t pump_states, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 6, pump_states);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PUMPS, buf, MAVLINK_MSG_ID_PUMPS_MIN_LEN, MAVLINK_MSG_ID_PUMPS_LEN, MAVLINK_MSG_ID_PUMPS_CRC);
#else
    mavlink_pumps_t *packet = (mavlink_pumps_t *)msgbuf;
    packet->timestamp_seconds = timestamp_seconds;
    packet->timestamp_milliseconds = timestamp_milliseconds;
    packet->pump_states = pump_states;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_PUMPS, (const char *)packet, MAVLINK_MSG_ID_PUMPS_MIN_LEN, MAVLINK_MSG_ID_PUMPS_LEN, MAVLINK_MSG_ID_PUMPS_CRC);
#endif
}
#endif

#endif

// MESSAGE PUMPS UNPACKING


/**
 * @brief Get field pump_states from pumps message
 *
 * @return  Bitmask of pump states. Bit 0: Pump Left, Bit 1: Pump Right
 */
static inline uint8_t mavlink_msg_pumps_get_pump_states(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  6);
}

/**
 * @brief Get field timestamp_seconds from pumps message
 *
 * @return  Seconds since Unix time
 */
static inline uint32_t mavlink_msg_pumps_get_timestamp_seconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field timestamp_milliseconds from pumps message
 *
 * @return  Milliseconds within Unix time
 */
static inline uint16_t mavlink_msg_pumps_get_timestamp_milliseconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Decode a pumps message into a struct
 *
 * @param msg The message to decode
 * @param pumps C-struct to decode the message contents into
 */
static inline void mavlink_msg_pumps_decode(const mavlink_message_t* msg, mavlink_pumps_t* pumps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    pumps->timestamp_seconds = mavlink_msg_pumps_get_timestamp_seconds(msg);
    pumps->timestamp_milliseconds = mavlink_msg_pumps_get_timestamp_milliseconds(msg);
    pumps->pump_states = mavlink_msg_pumps_get_pump_states(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_PUMPS_LEN? msg->len : MAVLINK_MSG_ID_PUMPS_LEN;
        memset(pumps, 0, MAVLINK_MSG_ID_PUMPS_LEN);
    memcpy(pumps, _MAV_PAYLOAD(msg), len);
#endif
}
