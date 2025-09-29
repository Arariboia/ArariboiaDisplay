#pragma once
// MESSAGE MPPT_STRINGS PACKING

#define MAVLINK_MSG_ID_MPPT_STRINGS 12


typedef struct __mavlink_mppt_strings_t {
 uint32_t timestamp_seconds; /*<  Seconds since Unix time*/
 uint16_t string_1; /*< [mA] Current from string 1*/
 uint16_t string_2; /*< [mA] Current from string 2*/
 uint16_t string_3; /*< [mA] Current from string 3*/
 uint16_t string_4; /*< [mA] Current from string 4*/
 uint16_t timestamp_milliseconds; /*<  Milliseconds within Unix time*/
} mavlink_mppt_strings_t;

#define MAVLINK_MSG_ID_MPPT_STRINGS_LEN 14
#define MAVLINK_MSG_ID_MPPT_STRINGS_MIN_LEN 14
#define MAVLINK_MSG_ID_12_LEN 14
#define MAVLINK_MSG_ID_12_MIN_LEN 14

#define MAVLINK_MSG_ID_MPPT_STRINGS_CRC 181
#define MAVLINK_MSG_ID_12_CRC 181



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MPPT_STRINGS { \
    12, \
    "MPPT_STRINGS", \
    6, \
    {  { "string_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_mppt_strings_t, string_1) }, \
         { "string_2", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_mppt_strings_t, string_2) }, \
         { "string_3", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_mppt_strings_t, string_3) }, \
         { "string_4", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_mppt_strings_t, string_4) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_mppt_strings_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_mppt_strings_t, timestamp_milliseconds) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MPPT_STRINGS { \
    "MPPT_STRINGS", \
    6, \
    {  { "string_1", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_mppt_strings_t, string_1) }, \
         { "string_2", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_mppt_strings_t, string_2) }, \
         { "string_3", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_mppt_strings_t, string_3) }, \
         { "string_4", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_mppt_strings_t, string_4) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_mppt_strings_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_mppt_strings_t, timestamp_milliseconds) }, \
         } \
}
#endif

/**
 * @brief Pack a mppt_strings message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param string_1 [mA] Current from string 1
 * @param string_2 [mA] Current from string 2
 * @param string_3 [mA] Current from string 3
 * @param string_4 [mA] Current from string 4
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mppt_strings_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t string_1, uint16_t string_2, uint16_t string_3, uint16_t string_4, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPPT_STRINGS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, string_1);
    _mav_put_uint16_t(buf, 6, string_2);
    _mav_put_uint16_t(buf, 8, string_3);
    _mav_put_uint16_t(buf, 10, string_4);
    _mav_put_uint16_t(buf, 12, timestamp_milliseconds);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MPPT_STRINGS_LEN);
#else
    mavlink_mppt_strings_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.string_1 = string_1;
    packet.string_2 = string_2;
    packet.string_3 = string_3;
    packet.string_4 = string_4;
    packet.timestamp_milliseconds = timestamp_milliseconds;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MPPT_STRINGS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MPPT_STRINGS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MPPT_STRINGS_MIN_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_CRC);
}

/**
 * @brief Pack a mppt_strings message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param string_1 [mA] Current from string 1
 * @param string_2 [mA] Current from string 2
 * @param string_3 [mA] Current from string 3
 * @param string_4 [mA] Current from string 4
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mppt_strings_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint16_t string_1, uint16_t string_2, uint16_t string_3, uint16_t string_4, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPPT_STRINGS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, string_1);
    _mav_put_uint16_t(buf, 6, string_2);
    _mav_put_uint16_t(buf, 8, string_3);
    _mav_put_uint16_t(buf, 10, string_4);
    _mav_put_uint16_t(buf, 12, timestamp_milliseconds);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MPPT_STRINGS_LEN);
#else
    mavlink_mppt_strings_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.string_1 = string_1;
    packet.string_2 = string_2;
    packet.string_3 = string_3;
    packet.string_4 = string_4;
    packet.timestamp_milliseconds = timestamp_milliseconds;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MPPT_STRINGS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MPPT_STRINGS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MPPT_STRINGS_MIN_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MPPT_STRINGS_MIN_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_LEN);
#endif
}

/**
 * @brief Pack a mppt_strings message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param string_1 [mA] Current from string 1
 * @param string_2 [mA] Current from string 2
 * @param string_3 [mA] Current from string 3
 * @param string_4 [mA] Current from string 4
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mppt_strings_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t string_1,uint16_t string_2,uint16_t string_3,uint16_t string_4,uint32_t timestamp_seconds,uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPPT_STRINGS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, string_1);
    _mav_put_uint16_t(buf, 6, string_2);
    _mav_put_uint16_t(buf, 8, string_3);
    _mav_put_uint16_t(buf, 10, string_4);
    _mav_put_uint16_t(buf, 12, timestamp_milliseconds);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MPPT_STRINGS_LEN);
#else
    mavlink_mppt_strings_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.string_1 = string_1;
    packet.string_2 = string_2;
    packet.string_3 = string_3;
    packet.string_4 = string_4;
    packet.timestamp_milliseconds = timestamp_milliseconds;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MPPT_STRINGS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MPPT_STRINGS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MPPT_STRINGS_MIN_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_CRC);
}

/**
 * @brief Encode a mppt_strings struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mppt_strings C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mppt_strings_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mppt_strings_t* mppt_strings)
{
    return mavlink_msg_mppt_strings_pack(system_id, component_id, msg, mppt_strings->string_1, mppt_strings->string_2, mppt_strings->string_3, mppt_strings->string_4, mppt_strings->timestamp_seconds, mppt_strings->timestamp_milliseconds);
}

/**
 * @brief Encode a mppt_strings struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mppt_strings C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mppt_strings_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mppt_strings_t* mppt_strings)
{
    return mavlink_msg_mppt_strings_pack_chan(system_id, component_id, chan, msg, mppt_strings->string_1, mppt_strings->string_2, mppt_strings->string_3, mppt_strings->string_4, mppt_strings->timestamp_seconds, mppt_strings->timestamp_milliseconds);
}

/**
 * @brief Encode a mppt_strings struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param mppt_strings C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mppt_strings_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_mppt_strings_t* mppt_strings)
{
    return mavlink_msg_mppt_strings_pack_status(system_id, component_id, _status, msg,  mppt_strings->string_1, mppt_strings->string_2, mppt_strings->string_3, mppt_strings->string_4, mppt_strings->timestamp_seconds, mppt_strings->timestamp_milliseconds);
}

/**
 * @brief Send a mppt_strings message
 * @param chan MAVLink channel to send the message
 *
 * @param string_1 [mA] Current from string 1
 * @param string_2 [mA] Current from string 2
 * @param string_3 [mA] Current from string 3
 * @param string_4 [mA] Current from string 4
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mppt_strings_send(mavlink_channel_t chan, uint16_t string_1, uint16_t string_2, uint16_t string_3, uint16_t string_4, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPPT_STRINGS_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, string_1);
    _mav_put_uint16_t(buf, 6, string_2);
    _mav_put_uint16_t(buf, 8, string_3);
    _mav_put_uint16_t(buf, 10, string_4);
    _mav_put_uint16_t(buf, 12, timestamp_milliseconds);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT_STRINGS, buf, MAVLINK_MSG_ID_MPPT_STRINGS_MIN_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_CRC);
#else
    mavlink_mppt_strings_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.string_1 = string_1;
    packet.string_2 = string_2;
    packet.string_3 = string_3;
    packet.string_4 = string_4;
    packet.timestamp_milliseconds = timestamp_milliseconds;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT_STRINGS, (const char *)&packet, MAVLINK_MSG_ID_MPPT_STRINGS_MIN_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_CRC);
#endif
}

/**
 * @brief Send a mppt_strings message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mppt_strings_send_struct(mavlink_channel_t chan, const mavlink_mppt_strings_t* mppt_strings)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mppt_strings_send(chan, mppt_strings->string_1, mppt_strings->string_2, mppt_strings->string_3, mppt_strings->string_4, mppt_strings->timestamp_seconds, mppt_strings->timestamp_milliseconds);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT_STRINGS, (const char *)mppt_strings, MAVLINK_MSG_ID_MPPT_STRINGS_MIN_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_CRC);
#endif
}

#if MAVLINK_MSG_ID_MPPT_STRINGS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mppt_strings_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t string_1, uint16_t string_2, uint16_t string_3, uint16_t string_4, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, string_1);
    _mav_put_uint16_t(buf, 6, string_2);
    _mav_put_uint16_t(buf, 8, string_3);
    _mav_put_uint16_t(buf, 10, string_4);
    _mav_put_uint16_t(buf, 12, timestamp_milliseconds);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT_STRINGS, buf, MAVLINK_MSG_ID_MPPT_STRINGS_MIN_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_CRC);
#else
    mavlink_mppt_strings_t *packet = (mavlink_mppt_strings_t *)msgbuf;
    packet->timestamp_seconds = timestamp_seconds;
    packet->string_1 = string_1;
    packet->string_2 = string_2;
    packet->string_3 = string_3;
    packet->string_4 = string_4;
    packet->timestamp_milliseconds = timestamp_milliseconds;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT_STRINGS, (const char *)packet, MAVLINK_MSG_ID_MPPT_STRINGS_MIN_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_LEN, MAVLINK_MSG_ID_MPPT_STRINGS_CRC);
#endif
}
#endif

#endif

// MESSAGE MPPT_STRINGS UNPACKING


/**
 * @brief Get field string_1 from mppt_strings message
 *
 * @return [mA] Current from string 1
 */
static inline uint16_t mavlink_msg_mppt_strings_get_string_1(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field string_2 from mppt_strings message
 *
 * @return [mA] Current from string 2
 */
static inline uint16_t mavlink_msg_mppt_strings_get_string_2(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field string_3 from mppt_strings message
 *
 * @return [mA] Current from string 3
 */
static inline uint16_t mavlink_msg_mppt_strings_get_string_3(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field string_4 from mppt_strings message
 *
 * @return [mA] Current from string 4
 */
static inline uint16_t mavlink_msg_mppt_strings_get_string_4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Get field timestamp_seconds from mppt_strings message
 *
 * @return  Seconds since Unix time
 */
static inline uint32_t mavlink_msg_mppt_strings_get_timestamp_seconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field timestamp_milliseconds from mppt_strings message
 *
 * @return  Milliseconds within Unix time
 */
static inline uint16_t mavlink_msg_mppt_strings_get_timestamp_milliseconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Decode a mppt_strings message into a struct
 *
 * @param msg The message to decode
 * @param mppt_strings C-struct to decode the message contents into
 */
static inline void mavlink_msg_mppt_strings_decode(const mavlink_message_t* msg, mavlink_mppt_strings_t* mppt_strings)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mppt_strings->timestamp_seconds = mavlink_msg_mppt_strings_get_timestamp_seconds(msg);
    mppt_strings->string_1 = mavlink_msg_mppt_strings_get_string_1(msg);
    mppt_strings->string_2 = mavlink_msg_mppt_strings_get_string_2(msg);
    mppt_strings->string_3 = mavlink_msg_mppt_strings_get_string_3(msg);
    mppt_strings->string_4 = mavlink_msg_mppt_strings_get_string_4(msg);
    mppt_strings->timestamp_milliseconds = mavlink_msg_mppt_strings_get_timestamp_milliseconds(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MPPT_STRINGS_LEN? msg->len : MAVLINK_MSG_ID_MPPT_STRINGS_LEN;
        memset(mppt_strings, 0, MAVLINK_MSG_ID_MPPT_STRINGS_LEN);
    memcpy(mppt_strings, _MAV_PAYLOAD(msg), len);
#endif
}
