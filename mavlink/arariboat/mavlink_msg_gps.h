#pragma once
// MESSAGE GPS PACKING

#define MAVLINK_MSG_ID_GPS 3


typedef struct __mavlink_gps_t {
 int32_t latitude; /*< [degE7] */
 int32_t longitude; /*< [degE7] */
 uint32_t timestamp_seconds; /*<  Seconds since Unix time*/
 uint16_t speed; /*< [cm/s] */
 uint16_t timestamp_milliseconds; /*<  Milliseconds within Unix time*/
 uint8_t course; /*< [deg] Direction of movement(not heading)*/
 uint8_t heading; /*< [deg] Direction of the bow (source not from GPS, but from IMU)*/
 uint8_t satellites_visible; /*<  */
 uint8_t hdop; /*<  Horizontal dilution of precision. Represents quality of GPS constellation. Values close to 1 are best. Above 5 is poor*/
} mavlink_gps_t;

#define MAVLINK_MSG_ID_GPS_LEN 20
#define MAVLINK_MSG_ID_GPS_MIN_LEN 20
#define MAVLINK_MSG_ID_3_LEN 20
#define MAVLINK_MSG_ID_3_MIN_LEN 20

#define MAVLINK_MSG_ID_GPS_CRC 37
#define MAVLINK_MSG_ID_3_CRC 37



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_GPS { \
    3, \
    "GPS", \
    9, \
    {  { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_gps_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_gps_t, longitude) }, \
         { "speed", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_gps_t, speed) }, \
         { "course", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_gps_t, course) }, \
         { "heading", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_gps_t, heading) }, \
         { "satellites_visible", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_gps_t, satellites_visible) }, \
         { "hdop", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_gps_t, hdop) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_gps_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_gps_t, timestamp_milliseconds) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_GPS { \
    "GPS", \
    9, \
    {  { "latitude", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_gps_t, latitude) }, \
         { "longitude", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_gps_t, longitude) }, \
         { "speed", NULL, MAVLINK_TYPE_UINT16_T, 0, 12, offsetof(mavlink_gps_t, speed) }, \
         { "course", NULL, MAVLINK_TYPE_UINT8_T, 0, 16, offsetof(mavlink_gps_t, course) }, \
         { "heading", NULL, MAVLINK_TYPE_UINT8_T, 0, 17, offsetof(mavlink_gps_t, heading) }, \
         { "satellites_visible", NULL, MAVLINK_TYPE_UINT8_T, 0, 18, offsetof(mavlink_gps_t, satellites_visible) }, \
         { "hdop", NULL, MAVLINK_TYPE_UINT8_T, 0, 19, offsetof(mavlink_gps_t, hdop) }, \
         { "timestamp_seconds", NULL, MAVLINK_TYPE_UINT32_T, 0, 8, offsetof(mavlink_gps_t, timestamp_seconds) }, \
         { "timestamp_milliseconds", NULL, MAVLINK_TYPE_UINT16_T, 0, 14, offsetof(mavlink_gps_t, timestamp_milliseconds) }, \
         } \
}
#endif

/**
 * @brief Pack a gps message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param latitude [degE7] 
 * @param longitude [degE7] 
 * @param speed [cm/s] 
 * @param course [deg] Direction of movement(not heading)
 * @param heading [deg] Direction of the bow (source not from GPS, but from IMU)
 * @param satellites_visible  
 * @param hdop  Horizontal dilution of precision. Represents quality of GPS constellation. Values close to 1 are best. Above 5 is poor
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               int32_t latitude, int32_t longitude, uint16_t speed, uint8_t course, uint8_t heading, uint8_t satellites_visible, uint8_t hdop, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPS_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_uint32_t(buf, 8, timestamp_seconds);
    _mav_put_uint16_t(buf, 12, speed);
    _mav_put_uint16_t(buf, 14, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 16, course);
    _mav_put_uint8_t(buf, 17, heading);
    _mav_put_uint8_t(buf, 18, satellites_visible);
    _mav_put_uint8_t(buf, 19, hdop);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_LEN);
#else
    mavlink_gps_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.timestamp_seconds = timestamp_seconds;
    packet.speed = speed;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.course = course;
    packet.heading = heading;
    packet.satellites_visible = satellites_visible;
    packet.hdop = hdop;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GPS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_GPS_MIN_LEN, MAVLINK_MSG_ID_GPS_LEN, MAVLINK_MSG_ID_GPS_CRC);
}

/**
 * @brief Pack a gps message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 *
 * @param latitude [degE7] 
 * @param longitude [degE7] 
 * @param speed [cm/s] 
 * @param course [deg] Direction of movement(not heading)
 * @param heading [deg] Direction of the bow (source not from GPS, but from IMU)
 * @param satellites_visible  
 * @param hdop  Horizontal dilution of precision. Represents quality of GPS constellation. Values close to 1 are best. Above 5 is poor
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_pack_status(uint8_t system_id, uint8_t component_id, mavlink_status_t *_status, mavlink_message_t* msg,
                               int32_t latitude, int32_t longitude, uint16_t speed, uint8_t course, uint8_t heading, uint8_t satellites_visible, uint8_t hdop, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPS_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_uint32_t(buf, 8, timestamp_seconds);
    _mav_put_uint16_t(buf, 12, speed);
    _mav_put_uint16_t(buf, 14, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 16, course);
    _mav_put_uint8_t(buf, 17, heading);
    _mav_put_uint8_t(buf, 18, satellites_visible);
    _mav_put_uint8_t(buf, 19, hdop);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_LEN);
#else
    mavlink_gps_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.timestamp_seconds = timestamp_seconds;
    packet.speed = speed;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.course = course;
    packet.heading = heading;
    packet.satellites_visible = satellites_visible;
    packet.hdop = hdop;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GPS;
#if MAVLINK_CRC_EXTRA
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_GPS_MIN_LEN, MAVLINK_MSG_ID_GPS_LEN, MAVLINK_MSG_ID_GPS_CRC);
#else
    return mavlink_finalize_message_buffer(msg, system_id, component_id, _status, MAVLINK_MSG_ID_GPS_MIN_LEN, MAVLINK_MSG_ID_GPS_LEN);
#endif
}

/**
 * @brief Pack a gps message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param latitude [degE7] 
 * @param longitude [degE7] 
 * @param speed [cm/s] 
 * @param course [deg] Direction of movement(not heading)
 * @param heading [deg] Direction of the bow (source not from GPS, but from IMU)
 * @param satellites_visible  
 * @param hdop  Horizontal dilution of precision. Represents quality of GPS constellation. Values close to 1 are best. Above 5 is poor
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_gps_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   int32_t latitude,int32_t longitude,uint16_t speed,uint8_t course,uint8_t heading,uint8_t satellites_visible,uint8_t hdop,uint32_t timestamp_seconds,uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPS_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_uint32_t(buf, 8, timestamp_seconds);
    _mav_put_uint16_t(buf, 12, speed);
    _mav_put_uint16_t(buf, 14, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 16, course);
    _mav_put_uint8_t(buf, 17, heading);
    _mav_put_uint8_t(buf, 18, satellites_visible);
    _mav_put_uint8_t(buf, 19, hdop);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_GPS_LEN);
#else
    mavlink_gps_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.timestamp_seconds = timestamp_seconds;
    packet.speed = speed;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.course = course;
    packet.heading = heading;
    packet.satellites_visible = satellites_visible;
    packet.hdop = hdop;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_GPS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_GPS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_GPS_MIN_LEN, MAVLINK_MSG_ID_GPS_LEN, MAVLINK_MSG_ID_GPS_CRC);
}

/**
 * @brief Encode a gps struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param gps C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_gps_t* gps)
{
    return mavlink_msg_gps_pack(system_id, component_id, msg, gps->latitude, gps->longitude, gps->speed, gps->course, gps->heading, gps->satellites_visible, gps->hdop, gps->timestamp_seconds, gps->timestamp_milliseconds);
}

/**
 * @brief Encode a gps struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param gps C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_gps_t* gps)
{
    return mavlink_msg_gps_pack_chan(system_id, component_id, chan, msg, gps->latitude, gps->longitude, gps->speed, gps->course, gps->heading, gps->satellites_visible, gps->hdop, gps->timestamp_seconds, gps->timestamp_milliseconds);
}

/**
 * @brief Encode a gps struct with provided status structure
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param status MAVLink status structure
 * @param msg The MAVLink message to compress the data into
 * @param gps C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_gps_encode_status(uint8_t system_id, uint8_t component_id, mavlink_status_t* _status, mavlink_message_t* msg, const mavlink_gps_t* gps)
{
    return mavlink_msg_gps_pack_status(system_id, component_id, _status, msg,  gps->latitude, gps->longitude, gps->speed, gps->course, gps->heading, gps->satellites_visible, gps->hdop, gps->timestamp_seconds, gps->timestamp_milliseconds);
}

/**
 * @brief Send a gps message
 * @param chan MAVLink channel to send the message
 *
 * @param latitude [degE7] 
 * @param longitude [degE7] 
 * @param speed [cm/s] 
 * @param course [deg] Direction of movement(not heading)
 * @param heading [deg] Direction of the bow (source not from GPS, but from IMU)
 * @param satellites_visible  
 * @param hdop  Horizontal dilution of precision. Represents quality of GPS constellation. Values close to 1 are best. Above 5 is poor
 * @param timestamp_seconds  Seconds since Unix time
 * @param timestamp_milliseconds  Milliseconds within Unix time
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_gps_send(mavlink_channel_t chan, int32_t latitude, int32_t longitude, uint16_t speed, uint8_t course, uint8_t heading, uint8_t satellites_visible, uint8_t hdop, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_GPS_LEN];
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_uint32_t(buf, 8, timestamp_seconds);
    _mav_put_uint16_t(buf, 12, speed);
    _mav_put_uint16_t(buf, 14, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 16, course);
    _mav_put_uint8_t(buf, 17, heading);
    _mav_put_uint8_t(buf, 18, satellites_visible);
    _mav_put_uint8_t(buf, 19, hdop);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS, buf, MAVLINK_MSG_ID_GPS_MIN_LEN, MAVLINK_MSG_ID_GPS_LEN, MAVLINK_MSG_ID_GPS_CRC);
#else
    mavlink_gps_t packet;
    packet.latitude = latitude;
    packet.longitude = longitude;
    packet.timestamp_seconds = timestamp_seconds;
    packet.speed = speed;
    packet.timestamp_milliseconds = timestamp_milliseconds;
    packet.course = course;
    packet.heading = heading;
    packet.satellites_visible = satellites_visible;
    packet.hdop = hdop;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS, (const char *)&packet, MAVLINK_MSG_ID_GPS_MIN_LEN, MAVLINK_MSG_ID_GPS_LEN, MAVLINK_MSG_ID_GPS_CRC);
#endif
}

/**
 * @brief Send a gps message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_gps_send_struct(mavlink_channel_t chan, const mavlink_gps_t* gps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_gps_send(chan, gps->latitude, gps->longitude, gps->speed, gps->course, gps->heading, gps->satellites_visible, gps->hdop, gps->timestamp_seconds, gps->timestamp_milliseconds);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS, (const char *)gps, MAVLINK_MSG_ID_GPS_MIN_LEN, MAVLINK_MSG_ID_GPS_LEN, MAVLINK_MSG_ID_GPS_CRC);
#endif
}

#if MAVLINK_MSG_ID_GPS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_gps_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  int32_t latitude, int32_t longitude, uint16_t speed, uint8_t course, uint8_t heading, uint8_t satellites_visible, uint8_t hdop, uint32_t timestamp_seconds, uint16_t timestamp_milliseconds)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_int32_t(buf, 0, latitude);
    _mav_put_int32_t(buf, 4, longitude);
    _mav_put_uint32_t(buf, 8, timestamp_seconds);
    _mav_put_uint16_t(buf, 12, speed);
    _mav_put_uint16_t(buf, 14, timestamp_milliseconds);
    _mav_put_uint8_t(buf, 16, course);
    _mav_put_uint8_t(buf, 17, heading);
    _mav_put_uint8_t(buf, 18, satellites_visible);
    _mav_put_uint8_t(buf, 19, hdop);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS, buf, MAVLINK_MSG_ID_GPS_MIN_LEN, MAVLINK_MSG_ID_GPS_LEN, MAVLINK_MSG_ID_GPS_CRC);
#else
    mavlink_gps_t *packet = (mavlink_gps_t *)msgbuf;
    packet->latitude = latitude;
    packet->longitude = longitude;
    packet->timestamp_seconds = timestamp_seconds;
    packet->speed = speed;
    packet->timestamp_milliseconds = timestamp_milliseconds;
    packet->course = course;
    packet->heading = heading;
    packet->satellites_visible = satellites_visible;
    packet->hdop = hdop;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_GPS, (const char *)packet, MAVLINK_MSG_ID_GPS_MIN_LEN, MAVLINK_MSG_ID_GPS_LEN, MAVLINK_MSG_ID_GPS_CRC);
#endif
}
#endif

#endif

// MESSAGE GPS UNPACKING


/**
 * @brief Get field latitude from gps message
 *
 * @return [degE7] 
 */
static inline int32_t mavlink_msg_gps_get_latitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field longitude from gps message
 *
 * @return [degE7] 
 */
static inline int32_t mavlink_msg_gps_get_longitude(const mavlink_message_t* msg)
{
    return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field speed from gps message
 *
 * @return [cm/s] 
 */
static inline uint16_t mavlink_msg_gps_get_speed(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  12);
}

/**
 * @brief Get field course from gps message
 *
 * @return [deg] Direction of movement(not heading)
 */
static inline uint8_t mavlink_msg_gps_get_course(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  16);
}

/**
 * @brief Get field heading from gps message
 *
 * @return [deg] Direction of the bow (source not from GPS, but from IMU)
 */
static inline uint8_t mavlink_msg_gps_get_heading(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  17);
}

/**
 * @brief Get field satellites_visible from gps message
 *
 * @return  
 */
static inline uint8_t mavlink_msg_gps_get_satellites_visible(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  18);
}

/**
 * @brief Get field hdop from gps message
 *
 * @return  Horizontal dilution of precision. Represents quality of GPS constellation. Values close to 1 are best. Above 5 is poor
 */
static inline uint8_t mavlink_msg_gps_get_hdop(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  19);
}

/**
 * @brief Get field timestamp_seconds from gps message
 *
 * @return  Seconds since Unix time
 */
static inline uint32_t mavlink_msg_gps_get_timestamp_seconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint32_t(msg,  8);
}

/**
 * @brief Get field timestamp_milliseconds from gps message
 *
 * @return  Milliseconds within Unix time
 */
static inline uint16_t mavlink_msg_gps_get_timestamp_milliseconds(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint16_t(msg,  14);
}

/**
 * @brief Decode a gps message into a struct
 *
 * @param msg The message to decode
 * @param gps C-struct to decode the message contents into
 */
static inline void mavlink_msg_gps_decode(const mavlink_message_t* msg, mavlink_gps_t* gps)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    gps->latitude = mavlink_msg_gps_get_latitude(msg);
    gps->longitude = mavlink_msg_gps_get_longitude(msg);
    gps->timestamp_seconds = mavlink_msg_gps_get_timestamp_seconds(msg);
    gps->speed = mavlink_msg_gps_get_speed(msg);
    gps->timestamp_milliseconds = mavlink_msg_gps_get_timestamp_milliseconds(msg);
    gps->course = mavlink_msg_gps_get_course(msg);
    gps->heading = mavlink_msg_gps_get_heading(msg);
    gps->satellites_visible = mavlink_msg_gps_get_satellites_visible(msg);
    gps->hdop = mavlink_msg_gps_get_hdop(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_GPS_LEN? msg->len : MAVLINK_MSG_ID_GPS_LEN;
        memset(gps, 0, MAVLINK_MSG_ID_GPS_LEN);
    memcpy(gps, _MAV_PAYLOAD(msg), len);
#endif
}
