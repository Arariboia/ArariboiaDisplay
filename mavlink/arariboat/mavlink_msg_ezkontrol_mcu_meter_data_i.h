#pragma once
// MESSAGE EZKONTROL_MCU_METER_DATA_I PACKING

#define MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I 8


typedef struct __mavlink_ezkontrol_mcu_meter_data_i_t {
 uint32_t timestamp_seconds; /*<  Seconds since Unix time*/
 uint16_t bus_voltage; /*< [dV] 0.1V/bit, offset= 0*/
 int16_t bus_current; /*< [dA] 0.1A/bit, offset= -32000*/
 int16_t rpm; /*< [drpm/bit] 0.1rpm/bit, offset= -32000*/
 uint16_t timestamp_milliseconds; /*<  Milliseconds within Unix time*/
 uint8_t accelerator_opening; /*<  1%/bit, throttle signal*/
 uint8_t instance; /*<  0 for left motor, 1 for right motor*/
} mavlink_ezkontrol_mcu_meter_data_i_t;

#define MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN 14
#define MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_MIN_LEN 14
#define MAVLINK_MSG_ID_8_LEN 14
#define MAVLINK_MSG_ID_8_MIN_LEN 14

#define MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_CRC 194
#define MAVLINK_MSG_ID_8_CRC 194



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EZKONTROL_MCU_METER_DATA_I { \
    8, \
    "EZKONTROL_MCU_METER_DATA_I", \
    7, \
    {  { "bus_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_ezkontrol_mcu_meter_data_i_t, bus_voltage) }, \
         { "bus_current", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_ezkontrol_mcu_meter_data_i_t, bus_current) }, \
         { "rpm", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_ezkontrol_mcu_meter_data_i_t, rpm) }, \
         { "accelerator_opening", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_ezkontrol_mcu_meter_data_i_t, accelerator_opening) }, \
         { "instance", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_ezkontrol_mcu_meter_data_i_t, instance) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ezkontrol_mcu_meter_data_i_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_ezkontrol_mcu_meter_data_i_t, timestamp_milliseconds) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EZKONTROL_MCU_METER_DATA_I { \
    "EZKONTROL_MCU_METER_DATA_I", \
    7, \
    {  { "bus_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_ezkontrol_mcu_meter_data_i_t, bus_voltage) }, \
         { "bus_current", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_ezkontrol_mcu_meter_data_i_t, bus_current) }, \
         { "rpm", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_ezkontrol_mcu_meter_data_i_t, rpm) }, \
         { "accelerator_opening", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_ezkontrol_mcu_meter_data_i_t, accelerator_opening) }, \
         { "instance", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_ezkontrol_mcu_meter_data_i_t, instance) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ezkontrol_mcu_meter_data_i_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 10, offsetof(mavlink_ezkontrol_mcu_meter_data_i_t, timestamp_milliseconds) }, \
         } \
}
#endif

/**
 * @brief Pack a ezkontrol_mcu_meter_data_i message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param bus_voltage [dV] 0.1V/bit, offset= 0
 * @param bus_current [dA] 0.1A/bit, offset= -32000
 * @param rpm [drpm/bit] 0.1rpm/bit, offset= -32000
 * @param accelerator_opening  1%/bit, throttle signal
 * @param instance  0 for left motor, 1 for right motor
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_i_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint16_t bus_voltage, int16_t bus_current, int16_t rpm, uint8_t accelerator_opening, uint8_t instance, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, bus_voltage);
    _mav_put_int16_t(buf, 6, bus_current);
    _mav_put_int16_t(buf, 8, rpm);
    _mav_put_uint16_t(buf, 10, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 12, accelerator_opening);
    _mav_put_uint8_t(buf, 13, instance);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN);
#else
    mavlink_ezkontrol_mcu_meter_data_i_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.bus_voltage = bus_voltage;
    packet.bus_current = bus_current;
    packet.rpm = rpm;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.accelerator_opening = accelerator_opening;
    packet.instance = instance;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_CRC);
}

/**
 * @brief Pack a ezkontrol_mcu_meter_data_i message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param bus_voltage [dV] 0.1V/bit, offset= 0
 * @param bus_current [dA] 0.1A/bit, offset= -32000
 * @param rpm [drpm/bit] 0.1rpm/bit, offset= -32000
 * @param accelerator_opening  1%/bit, throttle signal
 * @param instance  0 for left motor, 1 for right motor
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_i_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               uint16_t bus_voltage, int16_t bus_current, int16_t rpm, uint8_t accelerator_opening, uint8_t instance, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, bus_voltage);
    _mav_put_int16_t(buf, 6, bus_current);
    _mav_put_int16_t(buf, 8, rpm);
    _mav_put_uint16_t(buf, 10, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 12, accelerator_opening);
    _mav_put_uint8_t(buf, 13, instance);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN);
#else
    mavlink_ezkontrol_mcu_meter_data_i_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.bus_voltage = bus_voltage;
    packet.bus_current = bus_current;
    packet.rpm = rpm;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.accelerator_opening = accelerator_opening;
    packet.instance = instance;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN);
#endif
}

/**
 * @brief Pack a ezkontrol_mcu_meter_data_i message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param bus_voltage [dV] 0.1V/bit, offset= 0
 * @param bus_current [dA] 0.1A/bit, offset= -32000
 * @param rpm [drpm/bit] 0.1rpm/bit, offset= -32000
 * @param accelerator_opening  1%/bit, throttle signal
 * @param instance  0 for left motor, 1 for right motor
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_i_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint16_t bus_voltage,int16_t bus_current,int16_t rpm,uint8_t accelerator_opening,uint8_t instance,uint32_t timestamp_seconds,uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, bus_voltage);
    _mav_put_int16_t(buf, 6, bus_current);
    _mav_put_int16_t(buf, 8, rpm);
    _mav_put_uint16_t(buf, 10, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 12, accelerator_opening);
    _mav_put_uint8_t(buf, 13, instance);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN);
#else
    mavlink_ezkontrol_mcu_meter_data_i_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.bus_voltage = bus_voltage;
    packet.bus_current = bus_current;
    packet.rpm = rpm;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.accelerator_opening = accelerator_opening;
    packet.instance = instance;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_CRC);
}

/**
 * @brief Encode a ezkontrol_mcu_meter_data_i struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ezkontrol_mcu_meter_data_i C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_i_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ezkontrol_mcu_meter_data_i_t* ezkontrol_mcu_meter_data_i)
{
    return mavlink_msg_ezkontrol_mcu_meter_data_i_pack(system_id, component_id, msg, ezkontrol_mcu_meter_data_i->bus_voltage, ezkontrol_mcu_meter_data_i->bus_current, ezkontrol_mcu_meter_data_i->rpm, ezkontrol_mcu_meter_data_i->accelerator_opening, ezkontrol_mcu_meter_data_i->instance, ezkontrol_mcu_meter_data_i->timestamp_seconds, ezkontrol_mcu_meter_data_i->timestamp_milliseconds);
}

/**
 * @brief Encode a ezkontrol_mcu_meter_data_i struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ezkontrol_mcu_meter_data_i C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_i_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ezkontrol_mcu_meter_data_i_t* ezkontrol_mcu_meter_data_i)
{
    return mavlink_msg_ezkontrol_mcu_meter_data_i_pack_chan(system_id, component_id, chan, msg, ezkontrol_mcu_meter_data_i->bus_voltage, ezkontrol_mcu_meter_data_i->bus_current, ezkontrol_mcu_meter_data_i->rpm, ezkontrol_mcu_meter_data_i->accelerator_opening, ezkontrol_mcu_meter_data_i->instance, ezkontrol_mcu_meter_data_i->timestamp_seconds, ezkontrol_mcu_meter_data_i->timestamp_milliseconds);
}

/**
 * @brief Encode a ezkontrol_mcu_meter_data_i struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param ezkontrol_mcu_meter_data_i C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_i_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_ezkontrol_mcu_meter_data_i_t* ezkontrol_mcu_meter_data_i)
{
    return mavlink_msg_ezkontrol_mcu_meter_data_i_pack_status(system_id, component_id, _status, msg,  ezkontrol_mcu_meter_data_i->bus_voltage, ezkontrol_mcu_meter_data_i->bus_current, ezkontrol_mcu_meter_data_i->rpm, ezkontrol_mcu_meter_data_i->accelerator_opening, ezkontrol_mcu_meter_data_i->instance, ezkontrol_mcu_meter_data_i->timestamp_seconds, ezkontrol_mcu_meter_data_i->timestamp_milliseconds);
}

/**
 * @brief Send a ezkontrol_mcu_meter_data_i message
 * @param chan MAVLink channel to send the message
 *
 * @param bus_voltage [dV] 0.1V/bit, offset= 0
 * @param bus_current [dA] 0.1A/bit, offset= -32000
 * @param rpm [drpm/bit] 0.1rpm/bit, offset= -32000
 * @param accelerator_opening  1%/bit, throttle signal
 * @param instance  0 for left motor, 1 for right motor
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ezkontrol_mcu_meter_data_i_send(mavlink_channel_t chan, uint16_t bus_voltage, int16_t bus_current, int16_t rpm, uint8_t accelerator_opening, uint8_t instance, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, bus_voltage);
    _mav_put_int16_t(buf, 6, bus_current);
    _mav_put_int16_t(buf, 8, rpm);
    _mav_put_uint16_t(buf, 10, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 12, accelerator_opening);
    _mav_put_uint8_t(buf, 13, instance);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I, buf, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_CRC);
#else
    mavlink_ezkontrol_mcu_meter_data_i_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.bus_voltage = bus_voltage;
    packet.bus_current = bus_current;
    packet.rpm = rpm;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.accelerator_opening = accelerator_opening;
    packet.instance = instance;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I, (const char *)&packet, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_CRC);
#endif
}

/**
 * @brief Send a ezkontrol_mcu_meter_data_i message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ezkontrol_mcu_meter_data_i_send_struct(mavlink_channel_t chan, const mavlink_ezkontrol_mcu_meter_data_i_t* ezkontrol_mcu_meter_data_i)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ezkontrol_mcu_meter_data_i_send(chan, ezkontrol_mcu_meter_data_i->bus_voltage, ezkontrol_mcu_meter_data_i->bus_current, ezkontrol_mcu_meter_data_i->rpm, ezkontrol_mcu_meter_data_i->accelerator_opening, ezkontrol_mcu_meter_data_i->instance, ezkontrol_mcu_meter_data_i->timestamp_seconds, ezkontrol_mcu_meter_data_i->timestamp_milliseconds);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I, (const char *)ezkontrol_mcu_meter_data_i, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_CRC);
#endif
}

#if MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ezkontrol_mcu_meter_data_i_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint16_t bus_voltage, int16_t bus_current, int16_t rpm, uint8_t accelerator_opening, uint8_t instance, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, bus_voltage);
    _mav_put_int16_t(buf, 6, bus_current);
    _mav_put_int16_t(buf, 8, rpm);
    _mav_put_uint16_t(buf, 10, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 12, accelerator_opening);
    _mav_put_uint8_t(buf, 13, instance);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I, buf, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_CRC);
#else
    mavlink_ezkontrol_mcu_meter_data_i_t *packet = (mavlink_ezkontrol_mcu_meter_data_i_t *)msgbuf;
    packet->timestamp_seconds = timestamp_seconds;
    packet->bus_voltage = bus_voltage;
    packet->bus_current = bus_current;
    packet->rpm = rpm;
    packet->timestamp_milliseconds = timestamp_milliseconds;
    packet->accelerator_opening = accelerator_opening;
    packet->instance = instance;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I, (const char *)packet, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_CRC);
#endif
}
#endif

#endif

// MESSAGE EZKONTROL_MCU_METER_DATA_I UNPACKING


/**
 * @brief Get field bus_voltage from ezkontrol_mcu_meter_data_i message
 *
 * @return [dV] 0.1V/bit, offset= 0
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_i_get_bus_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field bus_current from ezkontrol_mcu_meter_data_i message
 *
 * @return [dA] 0.1A/bit, offset= -32000
 */
static inline int16_t mavlink_msg_ezkontrol_mcu_meter_data_i_get_bus_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field rpm from ezkontrol_mcu_meter_data_i message
 *
 * @return [drpm/bit] 0.1rpm/bit, offset= -32000
 */
static inline int16_t mavlink_msg_ezkontrol_mcu_meter_data_i_get_rpm(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field accelerator_opening from ezkontrol_mcu_meter_data_i message
 *
 * @return  1%/bit, throttle signal
 */
static inline uint8_t mavlink_msg_ezkontrol_mcu_meter_data_i_get_accelerator_opening(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field instance from ezkontrol_mcu_meter_data_i message
 *
 * @return  0 for left motor, 1 for right motor
 */
static inline uint8_t mavlink_msg_ezkontrol_mcu_meter_data_i_get_instance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field timestamp_seconds from ezkontrol_mcu_meter_data_i message
 *
 * @return  Seconds since Unix time
 */
static inline uint32_t mavlink_msg_ezkontrol_mcu_meter_data_i_get_timestamp_seconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field timestamp_milliseconds from ezkontrol_mcu_meter_data_i message
 *
 * @return  Milliseconds within Unix time
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_i_get_timestamp_milliseconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  10);
}

/**
 * @brief Decode a ezkontrol_mcu_meter_data_i message into a struct
 *
 * @param msg The message to decode
 * @param ezkontrol_mcu_meter_data_i C-struct to decode the message contents into
 */
static inline void mavlink_msg_ezkontrol_mcu_meter_data_i_decode(const mavlink_message_t* msg, mavlink_ezkontrol_mcu_meter_data_i_t* ezkontrol_mcu_meter_data_i)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ezkontrol_mcu_meter_data_i->timestamp_seconds = mavlink_msg_ezkontrol_mcu_meter_data_i_get_timestamp_seconds(msg);
    ezkontrol_mcu_meter_data_i->bus_voltage = mavlink_msg_ezkontrol_mcu_meter_data_i_get_bus_voltage(msg);
    ezkontrol_mcu_meter_data_i->bus_current = mavlink_msg_ezkontrol_mcu_meter_data_i_get_bus_current(msg);
    ezkontrol_mcu_meter_data_i->rpm = mavlink_msg_ezkontrol_mcu_meter_data_i_get_rpm(msg);
    ezkontrol_mcu_meter_data_i->timestamp_milliseconds = mavlink_msg_ezkontrol_mcu_meter_data_i_get_timestamp_milliseconds(msg);
    ezkontrol_mcu_meter_data_i->accelerator_opening = mavlink_msg_ezkontrol_mcu_meter_data_i_get_accelerator_opening(msg);
    ezkontrol_mcu_meter_data_i->instance = mavlink_msg_ezkontrol_mcu_meter_data_i_get_instance(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN? msg->len : MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN;
        memset(ezkontrol_mcu_meter_data_i, 0, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_I_LEN);
    memcpy(ezkontrol_mcu_meter_data_i, _MAV_PAYLOAD(msg), len);
#endif
}
