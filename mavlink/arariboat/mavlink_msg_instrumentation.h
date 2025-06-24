#pragma once
// MESSAGE INSTRUMENTATION PACKING

#define MAVLINK_MSG_ID_INSTRUMENTATION 1


typedef struct __mavlink_instrumentation_t {
 uint32_t timestamp_seconds; /*<  Seconds since Unix time*/
 int16_t battery_current; /*< [cA] */
 int16_t motor_current_left; /*< [cA] */
 int16_t motor_current_right; /*< [cA] */
 int16_t mppt_current; /*< [cA] */
 int16_t auxiliary_battery_current; /*< [cA] */
 uint16_t battery_voltage; /*< [cV] */
 uint16_t auxiliary_battery_voltage; /*< [cV] */
 uint16_t irradiance; /*< [W/m^2] */
 uint16_t timestamp_milliseconds; /*<  Milliseconds within Unix time*/
} mavlink_instrumentation_t;

#define MAVLINK_MSG_ID_INSTRUMENTATION_LEN 22
#define MAVLINK_MSG_ID_INSTRUMENTATION_MIN_LEN 22
#define MAVLINK_MSG_ID_1_LEN 22
#define MAVLINK_MSG_ID_1_MIN_LEN 22

#define MAVLINK_MSG_ID_INSTRUMENTATION_CRC 83
#define MAVLINK_MSG_ID_1_CRC 83



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_INSTRUMENTATION { \
    1, \
    "INSTRUMENTATION", \
    10, \
    {  { "battery_current", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_instrumentation_t, battery_current) }, \
         { "motor_current_left", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_instrumentation_t, motor_current_left) }, \
         { "motor_current_right", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_instrumentation_t, motor_current_right) }, \
         { "mppt_current", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_instrumentation_t, mppt_current) }, \
         { "auxiliary_battery_current", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_instrumentation_t, auxiliary_battery_current) }, \
         { "battery_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_instrumentation_t, battery_voltage) }, \
         { "auxiliary_battery_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_instrumentation_t, auxiliary_battery_voltage) }, \
         { "irradiance", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_instrumentation_t, irradiance) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_instrumentation_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_instrumentation_t, timestamp_milliseconds) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_INSTRUMENTATION { \
    "INSTRUMENTATION", \
    10, \
    {  { "battery_current", NULL, MAVLINK_TYPE_INT16_T, 0, 4, offsetof(mavlink_instrumentation_t, battery_current) }, \
         { "motor_current_left", NULL, MAVLINK_TYPE_INT16_T, 0, 6, offsetof(mavlink_instrumentation_t, motor_current_left) }, \
         { "motor_current_right", NULL, MAVLINK_TYPE_INT16_T, 0, 8, offsetof(mavlink_instrumentation_t, motor_current_right) }, \
         { "mppt_current", NULL, MAVLINK_TYPE_INT16_T, 0, 10, offsetof(mavlink_instrumentation_t, mppt_current) }, \
         { "auxiliary_battery_current", NULL, MAVLINK_TYPE_INT16_T, 0, 12, offsetof(mavlink_instrumentation_t, auxiliary_battery_current) }, \
         { "battery_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_instrumentation_t, battery_voltage) }, \
         { "auxiliary_battery_voltage", NULL, MAVLINK_TYPE_UINT16_T, 0, 16, offsetof(mavlink_instrumentation_t, auxiliary_battery_voltage) }, \
         { "irradiance", NULL, MAVLINK_TYPE_UINT16_T, 0, 18, offsetof(mavlink_instrumentation_t, irradiance) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_instrumentation_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 20, offsetof(mavlink_instrumentation_t, timestamp_milliseconds) }, \
         } \
}
#endif

/**
 * @brief Pack a instrumentation message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param battery_current [cA] 
 * @param motor_current_left [cA] 
 * @param motor_current_right [cA] 
 * @param mppt_current [cA] 
 * @param auxiliary_battery_current [cA] 
 * @param battery_voltage [cV] 
 * @param auxiliary_battery_voltage [cV] 
 * @param irradiance [W/m^2] 
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_instrumentation_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int16_t battery_current, int16_t motor_current_left, int16_t motor_current_right, int16_t mppt_current, int16_t auxiliary_battery_current, uint16_t battery_voltage, uint16_t auxiliary_battery_voltage, uint16_t irradiance, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_INSTRUMENTATION_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_int16_t(buf, 4, battery_current);
    _mav_put_int16_t(buf, 6, motor_current_left);
    _mav_put_int16_t(buf, 8, motor_current_right);
    _mav_put_int16_t(buf, 10, mppt_current);
    _mav_put_int16_t(buf, 12, auxiliary_battery_current);
    _mav_put_uint16_t(buf, 14, battery_voltage);
    _mav_put_uint16_t(buf, 16, auxiliary_battery_voltage);
    _mav_put_uint16_t(buf, 18, irradiance);
    _mav_put_uint16_t(buf, 20, timestamp_milliseconds);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_INSTRUMENTATION_LEN);
#else
    mavlink_instrumentation_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.battery_current = battery_current;
    packet.motor_current_left = motor_current_left;
    packet.motor_current_right = motor_current_right;
    packet.mppt_current = mppt_current;
    packet.auxiliary_battery_current = auxiliary_battery_current;
    packet.battery_voltage = battery_voltage;
    packet.auxiliary_battery_voltage = auxiliary_battery_voltage;
    packet.irradiance = irradiance;
    packet.timestamp_milliseconds = timestamp_milliseconds;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_INSTRUMENTATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_INSTRUMENTATION;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_INSTRUMENTATION_MIN_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_CRC);
}

/**
 * @brief Pack a instrumentation message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param battery_current [cA] 
 * @param motor_current_left [cA] 
 * @param motor_current_right [cA] 
 * @param mppt_current [cA] 
 * @param auxiliary_battery_current [cA] 
 * @param battery_voltage [cV] 
 * @param auxiliary_battery_voltage [cV] 
 * @param irradiance [W/m^2] 
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_instrumentation_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               int16_t battery_current, int16_t motor_current_left, int16_t motor_current_right, int16_t mppt_current, int16_t auxiliary_battery_current, uint16_t battery_voltage, uint16_t auxiliary_battery_voltage, uint16_t irradiance, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_INSTRUMENTATION_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_int16_t(buf, 4, battery_current);
    _mav_put_int16_t(buf, 6, motor_current_left);
    _mav_put_int16_t(buf, 8, motor_current_right);
    _mav_put_int16_t(buf, 10, mppt_current);
    _mav_put_int16_t(buf, 12, auxiliary_battery_current);
    _mav_put_uint16_t(buf, 14, battery_voltage);
    _mav_put_uint16_t(buf, 16, auxiliary_battery_voltage);
    _mav_put_uint16_t(buf, 18, irradiance);
    _mav_put_uint16_t(buf, 20, timestamp_milliseconds);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_INSTRUMENTATION_LEN);
#else
    mavlink_instrumentation_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.battery_current = battery_current;
    packet.motor_current_left = motor_current_left;
    packet.motor_current_right = motor_current_right;
    packet.mppt_current = mppt_current;
    packet.auxiliary_battery_current = auxiliary_battery_current;
    packet.battery_voltage = battery_voltage;
    packet.auxiliary_battery_voltage = auxiliary_battery_voltage;
    packet.irradiance = irradiance;
    packet.timestamp_milliseconds = timestamp_milliseconds;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_INSTRUMENTATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_INSTRUMENTATION;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_INSTRUMENTATION_MIN_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_INSTRUMENTATION_MIN_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_LEN);
#endif
}

/**
 * @brief Pack a instrumentation message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param battery_current [cA] 
 * @param motor_current_left [cA] 
 * @param motor_current_right [cA] 
 * @param mppt_current [cA] 
 * @param auxiliary_battery_current [cA] 
 * @param battery_voltage [cV] 
 * @param auxiliary_battery_voltage [cV] 
 * @param irradiance [W/m^2] 
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_instrumentation_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int16_t battery_current,int16_t motor_current_left,int16_t motor_current_right,int16_t mppt_current,int16_t auxiliary_battery_current,uint16_t battery_voltage,uint16_t auxiliary_battery_voltage,uint16_t irradiance,uint32_t timestamp_seconds,uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_INSTRUMENTATION_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_int16_t(buf, 4, battery_current);
    _mav_put_int16_t(buf, 6, motor_current_left);
    _mav_put_int16_t(buf, 8, motor_current_right);
    _mav_put_int16_t(buf, 10, mppt_current);
    _mav_put_int16_t(buf, 12, auxiliary_battery_current);
    _mav_put_uint16_t(buf, 14, battery_voltage);
    _mav_put_uint16_t(buf, 16, auxiliary_battery_voltage);
    _mav_put_uint16_t(buf, 18, irradiance);
    _mav_put_uint16_t(buf, 20, timestamp_milliseconds);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_INSTRUMENTATION_LEN);
#else
    mavlink_instrumentation_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.battery_current = battery_current;
    packet.motor_current_left = motor_current_left;
    packet.motor_current_right = motor_current_right;
    packet.mppt_current = mppt_current;
    packet.auxiliary_battery_current = auxiliary_battery_current;
    packet.battery_voltage = battery_voltage;
    packet.auxiliary_battery_voltage = auxiliary_battery_voltage;
    packet.irradiance = irradiance;
    packet.timestamp_milliseconds = timestamp_milliseconds;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_INSTRUMENTATION_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_INSTRUMENTATION;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_INSTRUMENTATION_MIN_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_CRC);
}

/**
 * @brief Encode a instrumentation struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param instrumentation C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_instrumentation_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_instrumentation_t* instrumentation)
{
    return mavlink_msg_instrumentation_pack(system_id, component_id, msg, instrumentation->battery_current, instrumentation->motor_current_left, instrumentation->motor_current_right, instrumentation->mppt_current, instrumentation->auxiliary_battery_current, instrumentation->battery_voltage, instrumentation->auxiliary_battery_voltage, instrumentation->irradiance, instrumentation->timestamp_seconds, instrumentation->timestamp_milliseconds);
}

/**
 * @brief Encode a instrumentation struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param instrumentation C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_instrumentation_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_instrumentation_t* instrumentation)
{
    return mavlink_msg_instrumentation_pack_chan(system_id, component_id, chan, msg, instrumentation->battery_current, instrumentation->motor_current_left, instrumentation->motor_current_right, instrumentation->mppt_current, instrumentation->auxiliary_battery_current, instrumentation->battery_voltage, instrumentation->auxiliary_battery_voltage, instrumentation->irradiance, instrumentation->timestamp_seconds, instrumentation->timestamp_milliseconds);
}

/**
 * @brief Encode a instrumentation struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param instrumentation C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_instrumentation_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_instrumentation_t* instrumentation)
{
    return mavlink_msg_instrumentation_pack_status(system_id, component_id, _status, msg,  instrumentation->battery_current, instrumentation->motor_current_left, instrumentation->motor_current_right, instrumentation->mppt_current, instrumentation->auxiliary_battery_current, instrumentation->battery_voltage, instrumentation->auxiliary_battery_voltage, instrumentation->irradiance, instrumentation->timestamp_seconds, instrumentation->timestamp_milliseconds);
}

/**
 * @brief Send a instrumentation message
 * @param chan MAVLink channel to send the message
 *
 * @param battery_current [cA] 
 * @param motor_current_left [cA] 
 * @param motor_current_right [cA] 
 * @param mppt_current [cA] 
 * @param auxiliary_battery_current [cA] 
 * @param battery_voltage [cV] 
 * @param auxiliary_battery_voltage [cV] 
 * @param irradiance [W/m^2] 
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_instrumentation_send(mavlink_channel_t chan, int16_t battery_current, int16_t motor_current_left, int16_t motor_current_right, int16_t mppt_current, int16_t auxiliary_battery_current, uint16_t battery_voltage, uint16_t auxiliary_battery_voltage, uint16_t irradiance, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_INSTRUMENTATION_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_int16_t(buf, 4, battery_current);
    _mav_put_int16_t(buf, 6, motor_current_left);
    _mav_put_int16_t(buf, 8, motor_current_right);
    _mav_put_int16_t(buf, 10, mppt_current);
    _mav_put_int16_t(buf, 12, auxiliary_battery_current);
    _mav_put_uint16_t(buf, 14, battery_voltage);
    _mav_put_uint16_t(buf, 16, auxiliary_battery_voltage);
    _mav_put_uint16_t(buf, 18, irradiance);
    _mav_put_uint16_t(buf, 20, timestamp_milliseconds);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INSTRUMENTATION, buf, MAVLINK_MSG_ID_INSTRUMENTATION_MIN_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_CRC);
#else
    mavlink_instrumentation_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.battery_current = battery_current;
    packet.motor_current_left = motor_current_left;
    packet.motor_current_right = motor_current_right;
    packet.mppt_current = mppt_current;
    packet.auxiliary_battery_current = auxiliary_battery_current;
    packet.battery_voltage = battery_voltage;
    packet.auxiliary_battery_voltage = auxiliary_battery_voltage;
    packet.irradiance = irradiance;
    packet.timestamp_milliseconds = timestamp_milliseconds;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INSTRUMENTATION, (const char *)&packet, MAVLINK_MSG_ID_INSTRUMENTATION_MIN_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_CRC);
#endif
}

/**
 * @brief Send a instrumentation message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_instrumentation_send_struct(mavlink_channel_t chan, const mavlink_instrumentation_t* instrumentation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_instrumentation_send(chan, instrumentation->battery_current, instrumentation->motor_current_left, instrumentation->motor_current_right, instrumentation->mppt_current, instrumentation->auxiliary_battery_current, instrumentation->battery_voltage, instrumentation->auxiliary_battery_voltage, instrumentation->irradiance, instrumentation->timestamp_seconds, instrumentation->timestamp_milliseconds);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INSTRUMENTATION, (const char *)instrumentation, MAVLINK_MSG_ID_INSTRUMENTATION_MIN_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_CRC);
#endif
}

#if MAVLINK_MSG_ID_INSTRUMENTATION_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_instrumentation_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int16_t battery_current, int16_t motor_current_left, int16_t motor_current_right, int16_t mppt_current, int16_t auxiliary_battery_current, uint16_t battery_voltage, uint16_t auxiliary_battery_voltage, uint16_t irradiance, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_int16_t(buf, 4, battery_current);
    _mav_put_int16_t(buf, 6, motor_current_left);
    _mav_put_int16_t(buf, 8, motor_current_right);
    _mav_put_int16_t(buf, 10, mppt_current);
    _mav_put_int16_t(buf, 12, auxiliary_battery_current);
    _mav_put_uint16_t(buf, 14, battery_voltage);
    _mav_put_uint16_t(buf, 16, auxiliary_battery_voltage);
    _mav_put_uint16_t(buf, 18, irradiance);
    _mav_put_uint16_t(buf, 20, timestamp_milliseconds);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INSTRUMENTATION, buf, MAVLINK_MSG_ID_INSTRUMENTATION_MIN_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_CRC);
#else
    mavlink_instrumentation_t *packet = (mavlink_instrumentation_t *)msgbuf;
    packet->timestamp_seconds = timestamp_seconds;
    packet->battery_current = battery_current;
    packet->motor_current_left = motor_current_left;
    packet->motor_current_right = motor_current_right;
    packet->mppt_current = mppt_current;
    packet->auxiliary_battery_current = auxiliary_battery_current;
    packet->battery_voltage = battery_voltage;
    packet->auxiliary_battery_voltage = auxiliary_battery_voltage;
    packet->irradiance = irradiance;
    packet->timestamp_milliseconds = timestamp_milliseconds;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_INSTRUMENTATION, (const char *)packet, MAVLINK_MSG_ID_INSTRUMENTATION_MIN_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_LEN, MAVLINK_MSG_ID_INSTRUMENTATION_CRC);
#endif
}
#endif

#endif

// MESSAGE INSTRUMENTATION UNPACKING


/**
 * @brief Get field battery_current from instrumentation message
 *
 * @return [cA] 
 */
static inline int16_t mavlink_msg_instrumentation_get_battery_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  4);
}

/**
 * @brief Get field motor_current_left from instrumentation message
 *
 * @return [cA] 
 */
static inline int16_t mavlink_msg_instrumentation_get_motor_current_left(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  6);
}

/**
 * @brief Get field motor_current_right from instrumentation message
 *
 * @return [cA] 
 */
static inline int16_t mavlink_msg_instrumentation_get_motor_current_right(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  8);
}

/**
 * @brief Get field mppt_current from instrumentation message
 *
 * @return [cA] 
 */
static inline int16_t mavlink_msg_instrumentation_get_mppt_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  10);
}

/**
 * @brief Get field auxiliary_battery_current from instrumentation message
 *
 * @return [cA] 
 */
static inline int16_t mavlink_msg_instrumentation_get_auxiliary_battery_current(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int16_t(msg,  12);
}

/**
 * @brief Get field battery_voltage from instrumentation message
 *
 * @return [cV] 
 */
static inline uint16_t mavlink_msg_instrumentation_get_battery_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Get field auxiliary_battery_voltage from instrumentation message
 *
 * @return [cV] 
 */
static inline uint16_t mavlink_msg_instrumentation_get_auxiliary_battery_voltage(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  16);
}

/**
 * @brief Get field irradiance from instrumentation message
 *
 * @return [W/m^2] 
 */
static inline uint16_t mavlink_msg_instrumentation_get_irradiance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  18);
}

/**
 * @brief Get field timestamp_seconds from instrumentation message
 *
 * @return  Seconds since Unix time
 */
static inline uint32_t mavlink_msg_instrumentation_get_timestamp_seconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field timestamp_milliseconds from instrumentation message
 *
 * @return  Milliseconds within Unix time
 */
static inline uint16_t mavlink_msg_instrumentation_get_timestamp_milliseconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  20);
}

/**
 * @brief Decode a instrumentation message into a struct
 *
 * @param msg The message to decode
 * @param instrumentation C-struct to decode the message contents into
 */
static inline void mavlink_msg_instrumentation_decode(const mavlink_message_t* msg, mavlink_instrumentation_t* instrumentation)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    instrumentation->timestamp_seconds = mavlink_msg_instrumentation_get_timestamp_seconds(msg);
    instrumentation->battery_current = mavlink_msg_instrumentation_get_battery_current(msg);
    instrumentation->motor_current_left = mavlink_msg_instrumentation_get_motor_current_left(msg);
    instrumentation->motor_current_right = mavlink_msg_instrumentation_get_motor_current_right(msg);
    instrumentation->mppt_current = mavlink_msg_instrumentation_get_mppt_current(msg);
    instrumentation->auxiliary_battery_current = mavlink_msg_instrumentation_get_auxiliary_battery_current(msg);
    instrumentation->battery_voltage = mavlink_msg_instrumentation_get_battery_voltage(msg);
    instrumentation->auxiliary_battery_voltage = mavlink_msg_instrumentation_get_auxiliary_battery_voltage(msg);
    instrumentation->irradiance = mavlink_msg_instrumentation_get_irradiance(msg);
    instrumentation->timestamp_milliseconds = mavlink_msg_instrumentation_get_timestamp_milliseconds(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_INSTRUMENTATION_LEN? msg->len : MAVLINK_MSG_ID_INSTRUMENTATION_LEN;
        memset(instrumentation, 0, MAVLINK_MSG_ID_INSTRUMENTATION_LEN);
    memcpy(instrumentation, _MAV_PAYLOAD(msg), len);
#endif
}
