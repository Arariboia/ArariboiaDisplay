#pragma once
// MESSAGE MPPT_STATE PACKING

#define MAVLINK_MSG_ID_MPPT_STATE 5


typedef struct __mavlink_mppt_state_t {
 uint32_t timestamp_seconds; /*<  Seconds since Unix time*/
 uint16_t battery_status; /*<  Status of the battery,ID=3200.*/
 uint16_t charging_equipment_status; /*<  Status of the MPPT,ID=3201.*/
 uint16_t timestamp_milliseconds; /*<  Milliseconds within Unix time*/
} mavlink_mppt_state_t;

#define MAVLINK_MSG_ID_MPPT_STATE_LEN 10
#define MAVLINK_MSG_ID_MPPT_STATE_MIN_LEN 10
#define MAVLINK_MSG_ID_5_LEN 10
#define MAVLINK_MSG_ID_5_MIN_LEN 10

#define MAVLINK_MSG_ID_MPPT_STATE_CRC 40
#define MAVLINK_MSG_ID_5_CRC 40



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_MPPT_STATE { \
    5, \
    "MPPT_STATE", \
    4, \
    {  { "battery_status", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_mppt_state_t, battery_status) }, \
         { "charging_equipment_status", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_mppt_state_t, charging_equipment_status) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_mppt_state_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_mppt_state_t, timestamp_milliseconds) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_MPPT_STATE { \
    "MPPT_STATE", \
    4, \
    {  { "battery_status", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_mppt_state_t, battery_status) }, \
         { "charging_equipment_status", NULL, MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_mppt_state_t, charging_equipment_status) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_mppt_state_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 8, offsetof(mavlink_mppt_state_t, timestamp_milliseconds) }, \
         } \
}
#endif

/**
 * @brief Pack a mppt_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param battery_status  Status of the battery,ID=3200.
 * @param charging_equipment_status  Status of the MPPT,ID=3201.
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mppt_state_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t battery_status, uint16_t charging_equipment_status, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPPT_STATE_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, battery_status);
    _mav_put_uint16_t(buf, 6, charging_equipment_status);
    _mav_put_uint16_t(buf, 8, timestamp_milliseconds);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MPPT_STATE_LEN);
#else
    mavlink_mppt_state_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.battery_status = battery_status;
    packet.charging_equipment_status = charging_equipment_status;
    packet.timestamp_milliseconds = timestamp_milliseconds;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MPPT_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MPPT_STATE;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_MPPT_STATE_MIN_LEN, MAVLINK_MSG_ID_MPPT_STATE_LEN, MAVLINK_MSG_ID_MPPT_STATE_CRC);
}

/**
 * @brief Pack a mppt_state message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param battery_status  Status of the battery,ID=3200.
 * @param charging_equipment_status  Status of the MPPT,ID=3201.
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mppt_state_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint16_t battery_status, uint16_t charging_equipment_status, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPPT_STATE_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, battery_status);
    _mav_put_uint16_t(buf, 6, charging_equipment_status);
    _mav_put_uint16_t(buf, 8, timestamp_milliseconds);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MPPT_STATE_LEN);
#else
    mavlink_mppt_state_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.battery_status = battery_status;
    packet.charging_equipment_status = charging_equipment_status;
    packet.timestamp_milliseconds = timestamp_milliseconds;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MPPT_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MPPT_STATE;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MPPT_STATE_MIN_LEN, MAVLINK_MSG_ID_MPPT_STATE_LEN, MAVLINK_MSG_ID_MPPT_STATE_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_MPPT_STATE_MIN_LEN, MAVLINK_MSG_ID_MPPT_STATE_LEN);
#endif
}

/**
 * @brief Pack a mppt_state message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param battery_status  Status of the battery,ID=3200.
 * @param charging_equipment_status  Status of the MPPT,ID=3201.
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_mppt_state_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t battery_status,uint16_t charging_equipment_status,uint32_t timestamp_seconds,uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPPT_STATE_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, battery_status);
    _mav_put_uint16_t(buf, 6, charging_equipment_status);
    _mav_put_uint16_t(buf, 8, timestamp_milliseconds);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_MPPT_STATE_LEN);
#else
    mavlink_mppt_state_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.battery_status = battery_status;
    packet.charging_equipment_status = charging_equipment_status;
    packet.timestamp_milliseconds = timestamp_milliseconds;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_MPPT_STATE_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_MPPT_STATE;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_MPPT_STATE_MIN_LEN, MAVLINK_MSG_ID_MPPT_STATE_LEN, MAVLINK_MSG_ID_MPPT_STATE_CRC);
}

/**
 * @brief Encode a mppt_state struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param mppt_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mppt_state_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_mppt_state_t* mppt_state)
{
    return mavlink_msg_mppt_state_pack(system_id, component_id, msg, mppt_state->battery_status, mppt_state->charging_equipment_status, mppt_state->timestamp_seconds, mppt_state->timestamp_milliseconds);
}

/**
 * @brief Encode a mppt_state struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param mppt_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mppt_state_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_mppt_state_t* mppt_state)
{
    return mavlink_msg_mppt_state_pack_chan(system_id, component_id, chan, msg, mppt_state->battery_status, mppt_state->charging_equipment_status, mppt_state->timestamp_seconds, mppt_state->timestamp_milliseconds);
}

/**
 * @brief Encode a mppt_state struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param mppt_state C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_mppt_state_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_mppt_state_t* mppt_state)
{
    return mavlink_msg_mppt_state_pack_status(system_id, component_id, _status, msg,  mppt_state->battery_status, mppt_state->charging_equipment_status, mppt_state->timestamp_seconds, mppt_state->timestamp_milliseconds);
}

/**
 * @brief Send a mppt_state message
 * @param chan MAVLink channel to send the message
 *
 * @param battery_status  Status of the battery,ID=3200.
 * @param charging_equipment_status  Status of the MPPT,ID=3201.
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_mppt_state_send(mavlink_channel_t chan, uint16_t battery_status, uint16_t charging_equipment_status, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_MPPT_STATE_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, battery_status);
    _mav_put_uint16_t(buf, 6, charging_equipment_status);
    _mav_put_uint16_t(buf, 8, timestamp_milliseconds);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT_STATE, buf, MAVLINK_MSG_ID_MPPT_STATE_MIN_LEN, MAVLINK_MSG_ID_MPPT_STATE_LEN, MAVLINK_MSG_ID_MPPT_STATE_CRC);
#else
    mavlink_mppt_state_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.battery_status = battery_status;
    packet.charging_equipment_status = charging_equipment_status;
    packet.timestamp_milliseconds = timestamp_milliseconds;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT_STATE, (const char *)&packet, MAVLINK_MSG_ID_MPPT_STATE_MIN_LEN, MAVLINK_MSG_ID_MPPT_STATE_LEN, MAVLINK_MSG_ID_MPPT_STATE_CRC);
#endif
}

/**
 * @brief Send a mppt_state message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_mppt_state_send_struct(mavlink_channel_t chan, const mavlink_mppt_state_t* mppt_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_mppt_state_send(chan, mppt_state->battery_status, mppt_state->charging_equipment_status, mppt_state->timestamp_seconds, mppt_state->timestamp_milliseconds);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT_STATE, (const char *)mppt_state, MAVLINK_MSG_ID_MPPT_STATE_MIN_LEN, MAVLINK_MSG_ID_MPPT_STATE_LEN, MAVLINK_MSG_ID_MPPT_STATE_CRC);
#endif
}

#if MAVLINK_MSG_ID_MPPT_STATE_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_mppt_state_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t battery_status, uint16_t charging_equipment_status, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, battery_status);
    _mav_put_uint16_t(buf, 6, charging_equipment_status);
    _mav_put_uint16_t(buf, 8, timestamp_milliseconds);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT_STATE, buf, MAVLINK_MSG_ID_MPPT_STATE_MIN_LEN, MAVLINK_MSG_ID_MPPT_STATE_LEN, MAVLINK_MSG_ID_MPPT_STATE_CRC);
#else
    mavlink_mppt_state_t *packet = (mavlink_mppt_state_t *)msgbuf;
    packet->timestamp_seconds = timestamp_seconds;
    packet->battery_status = battery_status;
    packet->charging_equipment_status = charging_equipment_status;
    packet->timestamp_milliseconds = timestamp_milliseconds;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_MPPT_STATE, (const char *)packet, MAVLINK_MSG_ID_MPPT_STATE_MIN_LEN, MAVLINK_MSG_ID_MPPT_STATE_LEN, MAVLINK_MSG_ID_MPPT_STATE_CRC);
#endif
}
#endif

#endif

// MESSAGE MPPT_STATE UNPACKING


/**
 * @brief Get field battery_status from mppt_state message
 *
 * @return  Status of the battery,ID=3200.
 */
static inline uint16_t mavlink_msg_mppt_state_get_battery_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field charging_equipment_status from mppt_state message
 *
 * @return  Status of the MPPT,ID=3201.
 */
static inline uint16_t mavlink_msg_mppt_state_get_charging_equipment_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field timestamp_seconds from mppt_state message
 *
 * @return  Seconds since Unix time
 */
static inline uint32_t mavlink_msg_mppt_state_get_timestamp_seconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field timestamp_milliseconds from mppt_state message
 *
 * @return  Milliseconds within Unix time
 */
static inline uint16_t mavlink_msg_mppt_state_get_timestamp_milliseconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  8);
}

/**
 * @brief Decode a mppt_state message into a struct
 *
 * @param msg The message to decode
 * @param mppt_state C-struct to decode the message contents into
 */
static inline void mavlink_msg_mppt_state_decode(const mavlink_message_t* msg, mavlink_mppt_state_t* mppt_state)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mppt_state->timestamp_seconds = mavlink_msg_mppt_state_get_timestamp_seconds(msg);
    mppt_state->battery_status = mavlink_msg_mppt_state_get_battery_status(msg);
    mppt_state->charging_equipment_status = mavlink_msg_mppt_state_get_charging_equipment_status(msg);
    mppt_state->timestamp_milliseconds = mavlink_msg_mppt_state_get_timestamp_milliseconds(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_MPPT_STATE_LEN? msg->len : MAVLINK_MSG_ID_MPPT_STATE_LEN;
        memset(mppt_state, 0, MAVLINK_MSG_ID_MPPT_STATE_LEN);
    memcpy(mppt_state, _MAV_PAYLOAD(msg), len);
#endif
}
