#pragma once
// MESSAGE ELETRONIC_PROPULSION PACKING

#define MAVLINK_MSG_ID_ELETRONIC_PROPULSION 11


typedef struct __mavlink_eletronic_propulsion_t {
 uint32_t timestamp_seconds; /*<  Seconds since Unix time*/
 uint16_t helm_potentiometer; /*< [mV] Helm potenciometer value.*/
 uint16_t throttle_left_potentiometer; /*< [mV] Left throttle potenciometer value.*/
 uint16_t throttle_right_potentiometer; /*< [mV] Right throttle potenciometer value.*/
 uint16_t timestamp_milliseconds; /*<  Milliseconds within Unix time*/
 uint8_t state; /*<  Bit 0: OFF, Bit 1: ON*/
} mavlink_eletronic_propulsion_t;

#define MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN 13
#define MAVLINK_MSG_ID_ELETRONIC_PROPULSION_MIN_LEN 13
#define MAVLINK_MSG_ID_11_LEN 13
#define MAVLINK_MSG_ID_11_MIN_LEN 13

#define MAVLINK_MSG_ID_ELETRONIC_PROPULSION_CRC 83
#define MAVLINK_MSG_ID_11_CRC 83



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_ELETRONIC_PROPULSION { \
    11, \
    "ELETRONIC_PROPULSION", \
    6, \
    {  { "helm_potentiometer", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_eletronic_propulsion_t, helm_potentiometer) }, \
         { "throttle_left_potentiometer", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_eletronic_propulsion_t, throttle_left_potentiometer) }, \
         { "throttle_right_potentiometer", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_eletronic_propulsion_t, throttle_right_potentiometer) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_eletronic_propulsion_t, state) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_eletronic_propulsion_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_eletronic_propulsion_t, timestamp_milliseconds) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_ELETRONIC_PROPULSION { \
    "ELETRONIC_PROPULSION", \
    6, \
    {  { "helm_potentiometer", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_eletronic_propulsion_t, helm_potentiometer) }, \
         { "throttle_left_potentiometer", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_eletronic_propulsion_t, throttle_left_potentiometer) }, \
         { "throttle_right_potentiometer", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_eletronic_propulsion_t, throttle_right_potentiometer) }, \
         { "state", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_eletronic_propulsion_t, state) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_eletronic_propulsion_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_eletronic_propulsion_t, timestamp_milliseconds) }, \
         } \
}
#endif

/**
 * @brief Pack a eletronic_propulsion message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param helm_potentiometer [mV] Helm potenciometer value.
 * @param throttle_left_potentiometer [mV] Left throttle potenciometer value.
 * @param throttle_right_potentiometer [mV] Right throttle potenciometer value.
 * @param state  Bit 0: OFF, Bit 1: ON
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_eletronic_propulsion_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t helm_potentiometer, uint16_t throttle_left_potentiometer, uint16_t throttle_right_potentiometer, uint8_t state, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, helm_potentiometer);
    _mav_put_uint16_t(buf, 6, throttle_left_potentiometer);
    _mav_put_uint16_t(buf, 8, throttle_right_potentiometer);
    _mav_put_uint16_t(buf, 10, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 12, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN);
#else
    mavlink_eletronic_propulsion_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.helm_potentiometer = helm_potentiometer;
    packet.throttle_left_potentiometer = throttle_left_potentiometer;
    packet.throttle_right_potentiometer = throttle_right_potentiometer;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ELETRONIC_PROPULSION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_MIN_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_CRC);
}

/**
 * @brief Pack a eletronic_propulsion message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param helm_potentiometer [mV] Helm potenciometer value.
 * @param throttle_left_potentiometer [mV] Left throttle potenciometer value.
 * @param throttle_right_potentiometer [mV] Right throttle potenciometer value.
 * @param state  Bit 0: OFF, Bit 1: ON
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_eletronic_propulsion_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint16_t helm_potentiometer, uint16_t throttle_left_potentiometer, uint16_t throttle_right_potentiometer, uint8_t state, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, helm_potentiometer);
    _mav_put_uint16_t(buf, 6, throttle_left_potentiometer);
    _mav_put_uint16_t(buf, 8, throttle_right_potentiometer);
    _mav_put_uint16_t(buf, 10, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 12, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN);
#else
    mavlink_eletronic_propulsion_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.helm_potentiometer = helm_potentiometer;
    packet.throttle_left_potentiometer = throttle_left_potentiometer;
    packet.throttle_right_potentiometer = throttle_right_potentiometer;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ELETRONIC_PROPULSION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_MIN_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_MIN_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN);
#endif
}

/**
 * @brief Pack a eletronic_propulsion message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param helm_potentiometer [mV] Helm potenciometer value.
 * @param throttle_left_potentiometer [mV] Left throttle potenciometer value.
 * @param throttle_right_potentiometer [mV] Right throttle potenciometer value.
 * @param state  Bit 0: OFF, Bit 1: ON
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_eletronic_propulsion_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t helm_potentiometer,uint16_t throttle_left_potentiometer,uint16_t throttle_right_potentiometer,uint8_t state,uint32_t timestamp_seconds,uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, helm_potentiometer);
    _mav_put_uint16_t(buf, 6, throttle_left_potentiometer);
    _mav_put_uint16_t(buf, 8, throttle_right_potentiometer);
    _mav_put_uint16_t(buf, 10, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 12, state);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN);
#else
    mavlink_eletronic_propulsion_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.helm_potentiometer = helm_potentiometer;
    packet.throttle_left_potentiometer = throttle_left_potentiometer;
    packet.throttle_right_potentiometer = throttle_right_potentiometer;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.state = state;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_ELETRONIC_PROPULSION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_MIN_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_CRC);
}

/**
 * @brief Encode a eletronic_propulsion struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param eletronic_propulsion C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_eletronic_propulsion_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_eletronic_propulsion_t* eletronic_propulsion)
{
    return mavlink_msg_eletronic_propulsion_pack(system_id, component_id, msg, eletronic_propulsion->helm_potentiometer, eletronic_propulsion->throttle_left_potentiometer, eletronic_propulsion->throttle_right_potentiometer, eletronic_propulsion->state, eletronic_propulsion->timestamp_seconds, eletronic_propulsion->timestamp_milliseconds);
}

/**
 * @brief Encode a eletronic_propulsion struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param eletronic_propulsion C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_eletronic_propulsion_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_eletronic_propulsion_t* eletronic_propulsion)
{
    return mavlink_msg_eletronic_propulsion_pack_chan(system_id, component_id, chan, msg, eletronic_propulsion->helm_potentiometer, eletronic_propulsion->throttle_left_potentiometer, eletronic_propulsion->throttle_right_potentiometer, eletronic_propulsion->state, eletronic_propulsion->timestamp_seconds, eletronic_propulsion->timestamp_milliseconds);
}

/**
 * @brief Encode a eletronic_propulsion struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param eletronic_propulsion C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_eletronic_propulsion_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_eletronic_propulsion_t* eletronic_propulsion)
{
    return mavlink_msg_eletronic_propulsion_pack_status(system_id, component_id, _status, msg,  eletronic_propulsion->helm_potentiometer, eletronic_propulsion->throttle_left_potentiometer, eletronic_propulsion->throttle_right_potentiometer, eletronic_propulsion->state, eletronic_propulsion->timestamp_seconds, eletronic_propulsion->timestamp_milliseconds);
}

/**
 * @brief Send a eletronic_propulsion message
 * @param chan MAVLink channel to send the message
 *
 * @param helm_potentiometer [mV] Helm potenciometer value.
 * @param throttle_left_potentiometer [mV] Left throttle potenciometer value.
 * @param throttle_right_potentiometer [mV] Right throttle potenciometer value.
 * @param state  Bit 0: OFF, Bit 1: ON
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_eletronic_propulsion_send(mavlink_channel_t chan, uint16_t helm_potentiometer, uint16_t throttle_left_potentiometer, uint16_t throttle_right_potentiometer, uint8_t state, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, helm_potentiometer);
    _mav_put_uint16_t(buf, 6, throttle_left_potentiometer);
    _mav_put_uint16_t(buf, 8, throttle_right_potentiometer);
    _mav_put_uint16_t(buf, 10, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 12, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELETRONIC_PROPULSION, buf, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_MIN_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_CRC);
#else
    mavlink_eletronic_propulsion_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.helm_potentiometer = helm_potentiometer;
    packet.throttle_left_potentiometer = throttle_left_potentiometer;
    packet.throttle_right_potentiometer = throttle_right_potentiometer;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.state = state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELETRONIC_PROPULSION, (const char *)&packet, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_MIN_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_CRC);
#endif
}

/**
 * @brief Send a eletronic_propulsion message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_eletronic_propulsion_send_struct(mavlink_channel_t chan, const mavlink_eletronic_propulsion_t* eletronic_propulsion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_eletronic_propulsion_send(chan, eletronic_propulsion->helm_potentiometer, eletronic_propulsion->throttle_left_potentiometer, eletronic_propulsion->throttle_right_potentiometer, eletronic_propulsion->state, eletronic_propulsion->timestamp_seconds, eletronic_propulsion->timestamp_milliseconds);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELETRONIC_PROPULSION, (const char *)eletronic_propulsion, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_MIN_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_CRC);
#endif
}

#if MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_eletronic_propulsion_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t helm_potentiometer, uint16_t throttle_left_potentiometer, uint16_t throttle_right_potentiometer, uint8_t state, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, helm_potentiometer);
    _mav_put_uint16_t(buf, 6, throttle_left_potentiometer);
    _mav_put_uint16_t(buf, 8, throttle_right_potentiometer);
    _mav_put_uint16_t(buf, 10, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 12, state);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELETRONIC_PROPULSION, buf, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_MIN_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_CRC);
#else
    mavlink_eletronic_propulsion_t *packet = (mavlink_eletronic_propulsion_t *)msgbuf;
    packet->timestamp_seconds = timestamp_seconds;
    packet->helm_potentiometer = helm_potentiometer;
    packet->throttle_left_potentiometer = throttle_left_potentiometer;
    packet->throttle_right_potentiometer = throttle_right_potentiometer;
    packet->timestamp_milliseconds = timestamp_milliseconds;
    packet->state = state;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_ELETRONIC_PROPULSION, (const char *)packet, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_MIN_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_CRC);
#endif
}
#endif

#endif

// MESSAGE ELETRONIC_PROPULSION UNPACKING


/**
 * @brief Get field helm_potentiometer from eletronic_propulsion message
 *
 * @return [mV] Helm potenciometer value.
 */
static inline uint16_t mavlink_msg_eletronic_propulsion_get_helm_potentiometer(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field throttle_left_potentiometer from eletronic_propulsion message
 *
 * @return [mV] Left throttle potenciometer value.
 */
static inline uint16_t mavlink_msg_eletronic_propulsion_get_throttle_left_potentiometer(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field throttle_right_potentiometer from eletronic_propulsion message
 *
 * @return [mV] Right throttle potenciometer value.
 */
static inline uint16_t mavlink_msg_eletronic_propulsion_get_throttle_right_potentiometer(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field state from eletronic_propulsion message
 *
 * @return  Bit 0: OFF, Bit 1: ON
 */
static inline uint8_t mavlink_msg_eletronic_propulsion_get_state(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field timestamp_seconds from eletronic_propulsion message
 *
 * @return  Seconds since Unix time
 */
static inline uint32_t mavlink_msg_eletronic_propulsion_get_timestamp_seconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field timestamp_milliseconds from eletronic_propulsion message
 *
 * @return  Milliseconds within Unix time
 */
static inline uint16_t mavlink_msg_eletronic_propulsion_get_timestamp_milliseconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Decode a eletronic_propulsion message into a struct
 *
 * @param msg The message to decode
 * @param eletronic_propulsion C-struct to decode the message contents into
 */
static inline void mavlink_msg_eletronic_propulsion_decode(const mavlink_message_t* msg, mavlink_eletronic_propulsion_t* eletronic_propulsion)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    eletronic_propulsion->timestamp_seconds = mavlink_msg_eletronic_propulsion_get_timestamp_seconds(msg);
    eletronic_propulsion->helm_potentiometer = mavlink_msg_eletronic_propulsion_get_helm_potentiometer(msg);
    eletronic_propulsion->throttle_left_potentiometer = mavlink_msg_eletronic_propulsion_get_throttle_left_potentiometer(msg);
    eletronic_propulsion->throttle_right_potentiometer = mavlink_msg_eletronic_propulsion_get_throttle_right_potentiometer(msg);
    eletronic_propulsion->timestamp_milliseconds = mavlink_msg_eletronic_propulsion_get_timestamp_milliseconds(msg);
    eletronic_propulsion->state = mavlink_msg_eletronic_propulsion_get_state(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN? msg->len : MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN;
        memset(eletronic_propulsion, 0, MAVLINK_MSG_ID_ELETRONIC_PROPULSION_LEN);
    memcpy(eletronic_propulsion, _MAV_PAYLOAD(msg), len);
#endif
}
