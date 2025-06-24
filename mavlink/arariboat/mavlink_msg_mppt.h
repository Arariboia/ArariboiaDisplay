#pragma once
// MESSAGE MPPT PACKING

#define MAVLINK_MSG_ID_MPPT 4


typedef struct __mavlink_mppt_t {
 uint32_t timestamp_seconds; /*<  Seconds since Unix time*/
 uint16_t pv_voltage; /*< [cV] Solar array voltage,ID=3100*/
 int16_t pv_current; /*< [cV] Solar array current,ID=3101*/
 uint16_t battery_voltage; /*< [cV] Battery voltage,ID=3104*/
 int16_t battery_current; /*< [cA] Net battery current(positive=charging),ID=331B*/
 uint16_t timestamp_milliseconds; /*<  Milliseconds within Unix time*/
} mavlink_mppt_t;

#define MAVLINK_MSG_ID_MPPT_LEN 14
#define MAVLINK_MSG_ID_MPPT_MIN_LEN 14
#define MAVLINK_MSG_ID_4_LEN 14
#define MAVLINK_MSG_ID_4_MIN_LEN 14

#define MAVLINK_MSG_ID_MPPT_CRC 26
#define MAVLINK_MSG_ID_4_CRC 26



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MPPT { \
    4, \
    "MPPT", \
    6, \
    {  { "pv_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_mppt_t, pv_voltage) }, \
         { "pv_current", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_mppt_t, pv_current) }, \
         { "battery_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_mppt_t, battery_voltage) }, \
         { "battery_current", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_mppt_t, battery_current) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_mppt_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_mppt_t, timestamp_milliseconds) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MPPT { \
    "MPPT", \
    6, \
    {  { "pv_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_mppt_t, pv_voltage) }, \
         { "pv_current", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_mppt_t, pv_current) }, \
         { "battery_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_mppt_t, battery_voltage) }, \
         { "battery_current", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_mppt_t, battery_current) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_mppt_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_mppt_t, timestamp_milliseconds) }, \
         } \
}
#endif

/**
 * @brief Pack a mppt message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param pv_voltage [cV] Solar array voltage,ID=3100
 * @param pv_current [cV] Solar array current,ID=3101
 * @param battery_voltage [cV] Battery voltage,ID=3104
 * @param battery_current [cA] Net battery current(positive=charging),ID=331B
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mppt_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t pv_voltage, int16_t pv_current, uint16_t battery_voltage, int16_t battery_current, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPPT_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, pv_voltage);
    _mav_put_int16_t(buf, 6, pv_current);
    _mav_put_uint16_t(buf, 8, battery_voltage);
    _mav_put_int16_t(buf, 10, battery_current);
    _mav_put_uint16_t(buf, 12, timestamp_milliseconds);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MPPT_LEN);
#else
    mavlink_mppt_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.pv_voltage = pv_voltage;
    packet.pv_current = pv_current;
    packet.battery_voltage = battery_voltage;
    packet.battery_current = battery_current;
    packet.timestamp_milliseconds = timestamp_milliseconds;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MPPT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MPPT;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MPPT_MIN_LEN, MAVLINK_MSG_ID_MPPT_LEN, MAVLINK_MSG_ID_MPPT_CRC);
}

/**
 * @brief Pack a mppt message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param pv_voltage [cV] Solar array voltage,ID=3100
 * @param pv_current [cV] Solar array current,ID=3101
 * @param battery_voltage [cV] Battery voltage,ID=3104
 * @param battery_current [cA] Net battery current(positive=charging),ID=331B
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mppt_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint16_t pv_voltage, int16_t pv_current, uint16_t battery_voltage, int16_t battery_current, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPPT_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, pv_voltage);
    _mav_put_int16_t(buf, 6, pv_current);
    _mav_put_uint16_t(buf, 8, battery_voltage);
    _mav_put_int16_t(buf, 10, battery_current);
    _mav_put_uint16_t(buf, 12, timestamp_milliseconds);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MPPT_LEN);
#else
    mavlink_mppt_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.pv_voltage = pv_voltage;
    packet.pv_current = pv_current;
    packet.battery_voltage = battery_voltage;
    packet.battery_current = battery_current;
    packet.timestamp_milliseconds = timestamp_milliseconds;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MPPT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MPPT;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MPPT_MIN_LEN, MAVLINK_MSG_ID_MPPT_LEN, MAVLINK_MSG_ID_MPPT_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MPPT_MIN_LEN, MAVLINK_MSG_ID_MPPT_LEN);
#endif
}

/**
 * @brief Pack a mppt message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param pv_voltage [cV] Solar array voltage,ID=3100
 * @param pv_current [cV] Solar array current,ID=3101
 * @param battery_voltage [cV] Battery voltage,ID=3104
 * @param battery_current [cA] Net battery current(positive=charging),ID=331B
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mppt_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t pv_voltage,int16_t pv_current,uint16_t battery_voltage,int16_t battery_current,uint32_t timestamp_seconds,uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPPT_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, pv_voltage);
    _mav_put_int16_t(buf, 6, pv_current);
    _mav_put_uint16_t(buf, 8, battery_voltage);
    _mav_put_int16_t(buf, 10, battery_current);
    _mav_put_uint16_t(buf, 12, timestamp_milliseconds);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MPPT_LEN);
#else
    mavlink_mppt_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.pv_voltage = pv_voltage;
    packet.pv_current = pv_current;
    packet.battery_voltage = battery_voltage;
    packet.battery_current = battery_current;
    packet.timestamp_milliseconds = timestamp_milliseconds;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MPPT_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MPPT;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MPPT_MIN_LEN, MAVLINK_MSG_ID_MPPT_LEN, MAVLINK_MSG_ID_MPPT_CRC);
}

/**
 * @brief Encode a mppt struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mppt C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mppt_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mppt_t* mppt)
{
    return mavlink_msg_mppt_pack(system_id, component_id, msg, mppt->pv_voltage, mppt->pv_current, mppt->battery_voltage, mppt->battery_current, mppt->timestamp_seconds, mppt->timestamp_milliseconds);
}

/**
 * @brief Encode a mppt struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mppt C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mppt_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mppt_t* mppt)
{
    return mavlink_msg_mppt_pack_chan(system_id, component_id, chan, msg, mppt->pv_voltage, mppt->pv_current, mppt->battery_voltage, mppt->battery_current, mppt->timestamp_seconds, mppt->timestamp_milliseconds);
}

/**
 * @brief Encode a mppt struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param mppt C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mppt_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_mppt_t* mppt)
{
    return mavlink_msg_mppt_pack_status(system_id, component_id, _status, msg,  mppt->pv_voltage, mppt->pv_current, mppt->battery_voltage, mppt->battery_current, mppt->timestamp_seconds, mppt->timestamp_milliseconds);
}

/**
 * @brief Send a mppt message
 * @param chan MAVLink channel to send the message
 *
 * @param pv_voltage [cV] Solar array voltage,ID=3100
 * @param pv_current [cV] Solar array current,ID=3101
 * @param battery_voltage [cV] Battery voltage,ID=3104
 * @param battery_current [cA] Net battery current(positive=charging),ID=331B
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mppt_send(mavlink_channel_t chan, uint16_t pv_voltage, int16_t pv_current, uint16_t battery_voltage, int16_t battery_current, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPPT_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, pv_voltage);
    _mav_put_int16_t(buf, 6, pv_current);
    _mav_put_uint16_t(buf, 8, battery_voltage);
    _mav_put_int16_t(buf, 10, battery_current);
    _mav_put_uint16_t(buf, 12, timestamp_milliseconds);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT, buf, MAVLINK_MSG_ID_MPPT_MIN_LEN, MAVLINK_MSG_ID_MPPT_LEN, MAVLINK_MSG_ID_MPPT_CRC);
#else
    mavlink_mppt_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.pv_voltage = pv_voltage;
    packet.pv_current = pv_current;
    packet.battery_voltage = battery_voltage;
    packet.battery_current = battery_current;
    packet.timestamp_milliseconds = timestamp_milliseconds;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT, (const char *)&packet, MAVLINK_MSG_ID_MPPT_MIN_LEN, MAVLINK_MSG_ID_MPPT_LEN, MAVLINK_MSG_ID_MPPT_CRC);
#endif
}

/**
 * @brief Send a mppt message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mppt_send_struct(mavlink_channel_t chan, const mavlink_mppt_t* mppt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mppt_send(chan, mppt->pv_voltage, mppt->pv_current, mppt->battery_voltage, mppt->battery_current, mppt->timestamp_seconds, mppt->timestamp_milliseconds);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT, (const char *)mppt, MAVLINK_MSG_ID_MPPT_MIN_LEN, MAVLINK_MSG_ID_MPPT_LEN, MAVLINK_MSG_ID_MPPT_CRC);
#endif
}

#if MAVLINK_MSG_ID_MPPT_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mppt_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t pv_voltage, int16_t pv_current, uint16_t battery_voltage, int16_t battery_current, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, pv_voltage);
    _mav_put_int16_t(buf, 6, pv_current);
    _mav_put_uint16_t(buf, 8, battery_voltage);
    _mav_put_int16_t(buf, 10, battery_current);
    _mav_put_uint16_t(buf, 12, timestamp_milliseconds);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT, buf, MAVLINK_MSG_ID_MPPT_MIN_LEN, MAVLINK_MSG_ID_MPPT_LEN, MAVLINK_MSG_ID_MPPT_CRC);
#else
    mavlink_mppt_t *packet = (mavlink_mppt_t *)msgbuf;
    packet->timestamp_seconds = timestamp_seconds;
    packet->pv_voltage = pv_voltage;
    packet->pv_current = pv_current;
    packet->battery_voltage = battery_voltage;
    packet->battery_current = battery_current;
    packet->timestamp_milliseconds = timestamp_milliseconds;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT, (const char *)packet, MAVLINK_MSG_ID_MPPT_MIN_LEN, MAVLINK_MSG_ID_MPPT_LEN, MAVLINK_MSG_ID_MPPT_CRC);
#endif
}
#endif

#endif

// MESSAGE MPPT UNPACKING


/**
 * @brief Get field pv_voltage from mppt message
 *
 * @return [cV] Solar array voltage,ID=3100
 */
static inline uint16_t mavlink_msg_mppt_get_pv_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field pv_current from mppt message
 *
 * @return [cV] Solar array current,ID=3101
 */
static inline int16_t mavlink_msg_mppt_get_pv_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field battery_voltage from mppt message
 *
 * @return [cV] Battery voltage,ID=3104
 */
static inline uint16_t mavlink_msg_mppt_get_battery_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Get field battery_current from mppt message
 *
 * @return [cA] Net battery current(positive=charging),ID=331B
 */
static inline int16_t mavlink_msg_mppt_get_battery_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field timestamp_seconds from mppt message
 *
 * @return  Seconds since Unix time
 */
static inline uint32_t mavlink_msg_mppt_get_timestamp_seconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field timestamp_milliseconds from mppt message
 *
 * @return  Milliseconds within Unix time
 */
static inline uint16_t mavlink_msg_mppt_get_timestamp_milliseconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Decode a mppt message into a struct
 *
 * @param msg The message to decode
 * @param mppt C-struct to decode the message contents into
 */
static inline void mavlink_msg_mppt_decode(const mavlink_message_t* msg, mavlink_mppt_t* mppt)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mppt->timestamp_seconds = mavlink_msg_mppt_get_timestamp_seconds(msg);
    mppt->pv_voltage = mavlink_msg_mppt_get_pv_voltage(msg);
    mppt->pv_current = mavlink_msg_mppt_get_pv_current(msg);
    mppt->battery_voltage = mavlink_msg_mppt_get_battery_voltage(msg);
    mppt->battery_current = mavlink_msg_mppt_get_battery_current(msg);
    mppt->timestamp_milliseconds = mavlink_msg_mppt_get_timestamp_milliseconds(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MPPT_LEN? msg->len : MAVLINK_MSG_ID_MPPT_LEN;
        memset(mppt, 0, MAVLINK_MSG_ID_MPPT_LEN);
    memcpy(mppt, _MAV_PAYLOAD(msg), len);
#endif
}
