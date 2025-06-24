#pragma once
// MESSAGE EZKONTROL_MCU_METER_DATA_II PACKING

#define MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II 9


typedef struct __mavlink_ezkontrol_mcu_meter_data_ii_t {
 uint32_t timestamp_seconds; /*<  Seconds since Unix time*/
 uint16_t timestamp_milliseconds; /*<  Milliseconds within Unix time*/
 int8_t controller_temperature; /*<  Controller temperature. Actual value = MAVLink value - 40. Unit: degC*/
 int8_t motor_temperature; /*<  Motor temperature. Actual value = MAVLink value - 40. Unit: degC*/
 uint8_t status; /*<  Gear, brake, operation mode and DC contactor.*/
 uint8_t error_flags_byte4; /*<  Error flags from Byte 4.*/
 uint8_t error_flags_byte5; /*<  Error flags from Byte 5.*/
 uint8_t error_flags_byte6; /*<  Error flags from Byte 6.*/
 uint8_t life_signal; /*<  Life signal counter derived from bits 7-4 from byte 7, msg II.*/
 uint8_t instance; /*<  0 for left motor, 1 for right motor*/
} mavlink_ezkontrol_mcu_meter_data_ii_t;

#define MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN 14
#define MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_MIN_LEN 14
#define MAVLINK_MSG_ID_9_LEN 14
#define MAVLINK_MSG_ID_9_MIN_LEN 14

#define MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_CRC 17
#define MAVLINK_MSG_ID_9_CRC 17



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_EZKONTROL_MCU_METER_DATA_II { \
    9, \
    "EZKONTROL_MCU_METER_DATA_II", \
    10, \
    {  { "controller_temperature", NULL, MAVLINK_TYPE_INT8_T, 0, 6, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, controller_temperature) }, \
         { "motor_temperature", NULL, MAVLINK_TYPE_INT8_T, 0, 7, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, motor_temperature) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, status) }, \
         { "error_flags_byte4", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, error_flags_byte4) }, \
         { "error_flags_byte5", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, error_flags_byte5) }, \
         { "error_flags_byte6", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, error_flags_byte6) }, \
         { "life_signal", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, life_signal) }, \
         { "instance", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, instance) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, timestamp_milliseconds) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_EZKONTROL_MCU_METER_DATA_II { \
    "EZKONTROL_MCU_METER_DATA_II", \
    10, \
    {  { "controller_temperature", NULL, MAVLINK_TYPE_INT8_T, 0, 6, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, controller_temperature) }, \
         { "motor_temperature", NULL, MAVLINK_TYPE_INT8_T, 0, 7, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, motor_temperature) }, \
         { "status", NULL, MAVLINK_TYPE_UINT8_T, 0, 8, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, status) }, \
         { "error_flags_byte4", NULL, MAVLINK_TYPE_UINT8_T, 0, 9, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, error_flags_byte4) }, \
         { "error_flags_byte5", NULL, MAVLINK_TYPE_UINT8_T, 0, 10, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, error_flags_byte5) }, \
         { "error_flags_byte6", NULL, MAVLINK_TYPE_UINT8_T, 0, 11, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, error_flags_byte6) }, \
         { "life_signal", NULL, MAVLINK_TYPE_UINT8_T, 0, 12, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, life_signal) }, \
         { "instance", NULL, MAVLINK_TYPE_UINT8_T, 0, 13, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, instance) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 0, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_ezkontrol_mcu_meter_data_ii_t, timestamp_milliseconds) }, \
         } \
}
#endif

/**
 * @brief Pack a ezkontrol_mcu_meter_data_ii message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param controller_temperature  Controller temperature. Actual value = MAVLink value - 40. Unit: degC
 * @param motor_temperature  Motor temperature. Actual value = MAVLink value - 40. Unit: degC
 * @param status  Gear, brake, operation mode and DC contactor.
 * @param error_flags_byte4  Error flags from Byte 4.
 * @param error_flags_byte5  Error flags from Byte 5.
 * @param error_flags_byte6  Error flags from Byte 6.
 * @param life_signal  Life signal counter derived from bits 7-4 from byte 7, msg II.
 * @param instance  0 for left motor, 1 for right motor
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_ii_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int8_t controller_temperature, int8_t motor_temperature, uint8_t status, uint8_t error_flags_byte4, uint8_t error_flags_byte5, uint8_t error_flags_byte6, uint8_t life_signal, uint8_t instance, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, timestamp_milliseconds);
    _mav_put_int8_t(buf, 6, controller_temperature);
    _mav_put_int8_t(buf, 7, motor_temperature);
    _mav_put_uint8_t(buf, 8, status);
    _mav_put_uint8_t(buf, 9, error_flags_byte4);
    _mav_put_uint8_t(buf, 10, error_flags_byte5);
    _mav_put_uint8_t(buf, 11, error_flags_byte6);
    _mav_put_uint8_t(buf, 12, life_signal);
    _mav_put_uint8_t(buf, 13, instance);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN);
#else
    mavlink_ezkontrol_mcu_meter_data_ii_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.controller_temperature = controller_temperature;
    packet.motor_temperature = motor_temperature;
    packet.status = status;
    packet.error_flags_byte4 = error_flags_byte4;
    packet.error_flags_byte5 = error_flags_byte5;
    packet.error_flags_byte6 = error_flags_byte6;
    packet.life_signal = life_signal;
    packet.instance = instance;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_CRC);
}

/**
 * @brief Pack a ezkontrol_mcu_meter_data_ii message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param controller_temperature  Controller temperature. Actual value = MAVLink value - 40. Unit: degC
 * @param motor_temperature  Motor temperature. Actual value = MAVLink value - 40. Unit: degC
 * @param status  Gear, brake, operation mode and DC contactor.
 * @param error_flags_byte4  Error flags from Byte 4.
 * @param error_flags_byte5  Error flags from Byte 5.
 * @param error_flags_byte6  Error flags from Byte 6.
 * @param life_signal  Life signal counter derived from bits 7-4 from byte 7, msg II.
 * @param instance  0 for left motor, 1 for right motor
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_ii_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               int8_t controller_temperature, int8_t motor_temperature, uint8_t status, uint8_t error_flags_byte4, uint8_t error_flags_byte5, uint8_t error_flags_byte6, uint8_t life_signal, uint8_t instance, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, timestamp_milliseconds);
    _mav_put_int8_t(buf, 6, controller_temperature);
    _mav_put_int8_t(buf, 7, motor_temperature);
    _mav_put_uint8_t(buf, 8, status);
    _mav_put_uint8_t(buf, 9, error_flags_byte4);
    _mav_put_uint8_t(buf, 10, error_flags_byte5);
    _mav_put_uint8_t(buf, 11, error_flags_byte6);
    _mav_put_uint8_t(buf, 12, life_signal);
    _mav_put_uint8_t(buf, 13, instance);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN);
#else
    mavlink_ezkontrol_mcu_meter_data_ii_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.controller_temperature = controller_temperature;
    packet.motor_temperature = motor_temperature;
    packet.status = status;
    packet.error_flags_byte4 = error_flags_byte4;
    packet.error_flags_byte5 = error_flags_byte5;
    packet.error_flags_byte6 = error_flags_byte6;
    packet.life_signal = life_signal;
    packet.instance = instance;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN);
#endif
}

/**
 * @brief Pack a ezkontrol_mcu_meter_data_ii message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param controller_temperature  Controller temperature. Actual value = MAVLink value - 40. Unit: degC
 * @param motor_temperature  Motor temperature. Actual value = MAVLink value - 40. Unit: degC
 * @param status  Gear, brake, operation mode and DC contactor.
 * @param error_flags_byte4  Error flags from Byte 4.
 * @param error_flags_byte5  Error flags from Byte 5.
 * @param error_flags_byte6  Error flags from Byte 6.
 * @param life_signal  Life signal counter derived from bits 7-4 from byte 7, msg II.
 * @param instance  0 for left motor, 1 for right motor
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_ii_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int8_t controller_temperature,int8_t motor_temperature,uint8_t status,uint8_t error_flags_byte4,uint8_t error_flags_byte5,uint8_t error_flags_byte6,uint8_t life_signal,uint8_t instance,uint32_t timestamp_seconds,uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, timestamp_milliseconds);
    _mav_put_int8_t(buf, 6, controller_temperature);
    _mav_put_int8_t(buf, 7, motor_temperature);
    _mav_put_uint8_t(buf, 8, status);
    _mav_put_uint8_t(buf, 9, error_flags_byte4);
    _mav_put_uint8_t(buf, 10, error_flags_byte5);
    _mav_put_uint8_t(buf, 11, error_flags_byte6);
    _mav_put_uint8_t(buf, 12, life_signal);
    _mav_put_uint8_t(buf, 13, instance);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN);
#else
    mavlink_ezkontrol_mcu_meter_data_ii_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.controller_temperature = controller_temperature;
    packet.motor_temperature = motor_temperature;
    packet.status = status;
    packet.error_flags_byte4 = error_flags_byte4;
    packet.error_flags_byte5 = error_flags_byte5;
    packet.error_flags_byte6 = error_flags_byte6;
    packet.life_signal = life_signal;
    packet.instance = instance;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_CRC);
}

/**
 * @brief Encode a ezkontrol_mcu_meter_data_ii struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param ezkontrol_mcu_meter_data_ii C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_ii_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_ezkontrol_mcu_meter_data_ii_t* ezkontrol_mcu_meter_data_ii)
{
    return mavlink_msg_ezkontrol_mcu_meter_data_ii_pack(system_id, component_id, msg, ezkontrol_mcu_meter_data_ii->controller_temperature, ezkontrol_mcu_meter_data_ii->motor_temperature, ezkontrol_mcu_meter_data_ii->status, ezkontrol_mcu_meter_data_ii->error_flags_byte4, ezkontrol_mcu_meter_data_ii->error_flags_byte5, ezkontrol_mcu_meter_data_ii->error_flags_byte6, ezkontrol_mcu_meter_data_ii->life_signal, ezkontrol_mcu_meter_data_ii->instance, ezkontrol_mcu_meter_data_ii->timestamp_seconds, ezkontrol_mcu_meter_data_ii->timestamp_milliseconds);
}

/**
 * @brief Encode a ezkontrol_mcu_meter_data_ii struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param ezkontrol_mcu_meter_data_ii C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_ii_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_ezkontrol_mcu_meter_data_ii_t* ezkontrol_mcu_meter_data_ii)
{
    return mavlink_msg_ezkontrol_mcu_meter_data_ii_pack_chan(system_id, component_id, chan, msg, ezkontrol_mcu_meter_data_ii->controller_temperature, ezkontrol_mcu_meter_data_ii->motor_temperature, ezkontrol_mcu_meter_data_ii->status, ezkontrol_mcu_meter_data_ii->error_flags_byte4, ezkontrol_mcu_meter_data_ii->error_flags_byte5, ezkontrol_mcu_meter_data_ii->error_flags_byte6, ezkontrol_mcu_meter_data_ii->life_signal, ezkontrol_mcu_meter_data_ii->instance, ezkontrol_mcu_meter_data_ii->timestamp_seconds, ezkontrol_mcu_meter_data_ii->timestamp_milliseconds);
}

/**
 * @brief Encode a ezkontrol_mcu_meter_data_ii struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param ezkontrol_mcu_meter_data_ii C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_ii_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_ezkontrol_mcu_meter_data_ii_t* ezkontrol_mcu_meter_data_ii)
{
    return mavlink_msg_ezkontrol_mcu_meter_data_ii_pack_status(system_id, component_id, _status, msg,  ezkontrol_mcu_meter_data_ii->controller_temperature, ezkontrol_mcu_meter_data_ii->motor_temperature, ezkontrol_mcu_meter_data_ii->status, ezkontrol_mcu_meter_data_ii->error_flags_byte4, ezkontrol_mcu_meter_data_ii->error_flags_byte5, ezkontrol_mcu_meter_data_ii->error_flags_byte6, ezkontrol_mcu_meter_data_ii->life_signal, ezkontrol_mcu_meter_data_ii->instance, ezkontrol_mcu_meter_data_ii->timestamp_seconds, ezkontrol_mcu_meter_data_ii->timestamp_milliseconds);
}

/**
 * @brief Send a ezkontrol_mcu_meter_data_ii message
 * @param chan MAVLink channel to send the message
 *
 * @param controller_temperature  Controller temperature. Actual value = MAVLink value - 40. Unit: degC
 * @param motor_temperature  Motor temperature. Actual value = MAVLink value - 40. Unit: degC
 * @param status  Gear, brake, operation mode and DC contactor.
 * @param error_flags_byte4  Error flags from Byte 4.
 * @param error_flags_byte5  Error flags from Byte 5.
 * @param error_flags_byte6  Error flags from Byte 6.
 * @param life_signal  Life signal counter derived from bits 7-4 from byte 7, msg II.
 * @param instance  0 for left motor, 1 for right motor
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_ezkontrol_mcu_meter_data_ii_send(mavlink_channel_t chan, int8_t controller_temperature, int8_t motor_temperature, uint8_t status, uint8_t error_flags_byte4, uint8_t error_flags_byte5, uint8_t error_flags_byte6, uint8_t life_signal, uint8_t instance, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN];
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, timestamp_milliseconds);
    _mav_put_int8_t(buf, 6, controller_temperature);
    _mav_put_int8_t(buf, 7, motor_temperature);
    _mav_put_uint8_t(buf, 8, status);
    _mav_put_uint8_t(buf, 9, error_flags_byte4);
    _mav_put_uint8_t(buf, 10, error_flags_byte5);
    _mav_put_uint8_t(buf, 11, error_flags_byte6);
    _mav_put_uint8_t(buf, 12, life_signal);
    _mav_put_uint8_t(buf, 13, instance);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II, buf, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_CRC);
#else
    mavlink_ezkontrol_mcu_meter_data_ii_t packet;
    packet.timestamp_seconds = timestamp_seconds;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.controller_temperature = controller_temperature;
    packet.motor_temperature = motor_temperature;
    packet.status = status;
    packet.error_flags_byte4 = error_flags_byte4;
    packet.error_flags_byte5 = error_flags_byte5;
    packet.error_flags_byte6 = error_flags_byte6;
    packet.life_signal = life_signal;
    packet.instance = instance;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II, (const char *)&packet, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_CRC);
#endif
}

/**
 * @brief Send a ezkontrol_mcu_meter_data_ii message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_ezkontrol_mcu_meter_data_ii_send_struct(mavlink_channel_t chan, const mavlink_ezkontrol_mcu_meter_data_ii_t* ezkontrol_mcu_meter_data_ii)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_ezkontrol_mcu_meter_data_ii_send(chan, ezkontrol_mcu_meter_data_ii->controller_temperature, ezkontrol_mcu_meter_data_ii->motor_temperature, ezkontrol_mcu_meter_data_ii->status, ezkontrol_mcu_meter_data_ii->error_flags_byte4, ezkontrol_mcu_meter_data_ii->error_flags_byte5, ezkontrol_mcu_meter_data_ii->error_flags_byte6, ezkontrol_mcu_meter_data_ii->life_signal, ezkontrol_mcu_meter_data_ii->instance, ezkontrol_mcu_meter_data_ii->timestamp_seconds, ezkontrol_mcu_meter_data_ii->timestamp_milliseconds);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II, (const char *)ezkontrol_mcu_meter_data_ii, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_CRC);
#endif
}

#if MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_ezkontrol_mcu_meter_data_ii_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int8_t controller_temperature, int8_t motor_temperature, uint8_t status, uint8_t error_flags_byte4, uint8_t error_flags_byte5, uint8_t error_flags_byte6, uint8_t life_signal, uint8_t instance, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint32_t(buf, 0, timestamp_seconds);
    _mav_put_uint16_t(buf, 4, timestamp_milliseconds);
    _mav_put_int8_t(buf, 6, controller_temperature);
    _mav_put_int8_t(buf, 7, motor_temperature);
    _mav_put_uint8_t(buf, 8, status);
    _mav_put_uint8_t(buf, 9, error_flags_byte4);
    _mav_put_uint8_t(buf, 10, error_flags_byte5);
    _mav_put_uint8_t(buf, 11, error_flags_byte6);
    _mav_put_uint8_t(buf, 12, life_signal);
    _mav_put_uint8_t(buf, 13, instance);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II, buf, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_CRC);
#else
    mavlink_ezkontrol_mcu_meter_data_ii_t *packet = (mavlink_ezkontrol_mcu_meter_data_ii_t *)msgbuf;
    packet->timestamp_seconds = timestamp_seconds;
    packet->timestamp_milliseconds = timestamp_milliseconds;
    packet->controller_temperature = controller_temperature;
    packet->motor_temperature = motor_temperature;
    packet->status = status;
    packet->error_flags_byte4 = error_flags_byte4;
    packet->error_flags_byte5 = error_flags_byte5;
    packet->error_flags_byte6 = error_flags_byte6;
    packet->life_signal = life_signal;
    packet->instance = instance;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II, (const char *)packet, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_MIN_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_CRC);
#endif
}
#endif

#endif

// MESSAGE EZKONTROL_MCU_METER_DATA_II UNPACKING


/**
 * @brief Get field controller_temperature from ezkontrol_mcu_meter_data_ii message
 *
 * @return  Controller temperature. Actual value = MAVLink value - 40. Unit: degC
 */
static inline int8_t mavlink_msg_ezkontrol_mcu_meter_data_ii_get_controller_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  6);
}

/**
 * @brief Get field motor_temperature from ezkontrol_mcu_meter_data_ii message
 *
 * @return  Motor temperature. Actual value = MAVLink value - 40. Unit: degC
 */
static inline int8_t mavlink_msg_ezkontrol_mcu_meter_data_ii_get_motor_temperature(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int8_t(msg,  7);
}

/**
 * @brief Get field status from ezkontrol_mcu_meter_data_ii message
 *
 * @return  Gear, brake, operation mode and DC contactor.
 */
static inline uint8_t mavlink_msg_ezkontrol_mcu_meter_data_ii_get_status(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  8);
}

/**
 * @brief Get field error_flags_byte4 from ezkontrol_mcu_meter_data_ii message
 *
 * @return  Error flags from Byte 4.
 */
static inline uint8_t mavlink_msg_ezkontrol_mcu_meter_data_ii_get_error_flags_byte4(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  9);
}

/**
 * @brief Get field error_flags_byte5 from ezkontrol_mcu_meter_data_ii message
 *
 * @return  Error flags from Byte 5.
 */
static inline uint8_t mavlink_msg_ezkontrol_mcu_meter_data_ii_get_error_flags_byte5(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  10);
}

/**
 * @brief Get field error_flags_byte6 from ezkontrol_mcu_meter_data_ii message
 *
 * @return  Error flags from Byte 6.
 */
static inline uint8_t mavlink_msg_ezkontrol_mcu_meter_data_ii_get_error_flags_byte6(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  11);
}

/**
 * @brief Get field life_signal from ezkontrol_mcu_meter_data_ii message
 *
 * @return  Life signal counter derived from bits 7-4 from byte 7, msg II.
 */
static inline uint8_t mavlink_msg_ezkontrol_mcu_meter_data_ii_get_life_signal(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  12);
}

/**
 * @brief Get field instance from ezkontrol_mcu_meter_data_ii message
 *
 * @return  0 for left motor, 1 for right motor
 */
static inline uint8_t mavlink_msg_ezkontrol_mcu_meter_data_ii_get_instance(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  13);
}

/**
 * @brief Get field timestamp_seconds from ezkontrol_mcu_meter_data_ii message
 *
 * @return  Seconds since Unix time
 */
static inline uint32_t mavlink_msg_ezkontrol_mcu_meter_data_ii_get_timestamp_seconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  0);
}

/**
 * @brief Get field timestamp_milliseconds from ezkontrol_mcu_meter_data_ii message
 *
 * @return  Milliseconds within Unix time
 */
static inline uint16_t mavlink_msg_ezkontrol_mcu_meter_data_ii_get_timestamp_milliseconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Decode a ezkontrol_mcu_meter_data_ii message into a struct
 *
 * @param msg The message to decode
 * @param ezkontrol_mcu_meter_data_ii C-struct to decode the message contents into
 */
static inline void mavlink_msg_ezkontrol_mcu_meter_data_ii_decode(const mavlink_message_t* msg, mavlink_ezkontrol_mcu_meter_data_ii_t* ezkontrol_mcu_meter_data_ii)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    ezkontrol_mcu_meter_data_ii->timestamp_seconds = mavlink_msg_ezkontrol_mcu_meter_data_ii_get_timestamp_seconds(msg);
    ezkontrol_mcu_meter_data_ii->timestamp_milliseconds = mavlink_msg_ezkontrol_mcu_meter_data_ii_get_timestamp_milliseconds(msg);
    ezkontrol_mcu_meter_data_ii->controller_temperature = mavlink_msg_ezkontrol_mcu_meter_data_ii_get_controller_temperature(msg);
    ezkontrol_mcu_meter_data_ii->motor_temperature = mavlink_msg_ezkontrol_mcu_meter_data_ii_get_motor_temperature(msg);
    ezkontrol_mcu_meter_data_ii->status = mavlink_msg_ezkontrol_mcu_meter_data_ii_get_status(msg);
    ezkontrol_mcu_meter_data_ii->error_flags_byte4 = mavlink_msg_ezkontrol_mcu_meter_data_ii_get_error_flags_byte4(msg);
    ezkontrol_mcu_meter_data_ii->error_flags_byte5 = mavlink_msg_ezkontrol_mcu_meter_data_ii_get_error_flags_byte5(msg);
    ezkontrol_mcu_meter_data_ii->error_flags_byte6 = mavlink_msg_ezkontrol_mcu_meter_data_ii_get_error_flags_byte6(msg);
    ezkontrol_mcu_meter_data_ii->life_signal = mavlink_msg_ezkontrol_mcu_meter_data_ii_get_life_signal(msg);
    ezkontrol_mcu_meter_data_ii->instance = mavlink_msg_ezkontrol_mcu_meter_data_ii_get_instance(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN? msg->len : MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN;
        memset(ezkontrol_mcu_meter_data_ii, 0, MAVLINK_MSG_ID_EZKONTROL_MCU_METER_DATA_II_LEN);
    memcpy(ezkontrol_mcu_meter_data_ii, _MAV_PAYLOAD(msg), len);
#endif
}
