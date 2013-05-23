// MESSAGE AU_UAV PACKING

#define MAVLINK_MSG_ID_AU_UAV 199

typedef struct __mavlink_au_uav_t
{
 int32_t au_lat; ///< Current latitude
 int32_t au_lng; ///< Current longitude
 int32_t au_alt; ///< Current altitude
 int32_t au_target_lat; ///< Target latitude
 int32_t au_target_lng; ///< Target longitude
 int32_t au_target_alt; ///< Target altitude
 int32_t au_ground_speed; ///< Current ground speed
 int32_t au_target_bearing; ///< Desired bearing to wp in degrees
 int32_t au_distance; ///< Distance to target waypoint
 uint8_t au_target_wp_index; ///< Target waypoint index
} mavlink_au_uav_t;

#define MAVLINK_MSG_ID_AU_UAV_LEN 37
#define MAVLINK_MSG_ID_199_LEN 37



#define MAVLINK_MESSAGE_INFO_AU_UAV { \
	"AU_UAV", \
	10, \
	{  { "au_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_au_uav_t, au_lat) }, \
         { "au_lng", NULL, MAVLINK_TYPE_INT32_T, 0, 4, offsetof(mavlink_au_uav_t, au_lng) }, \
         { "au_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 8, offsetof(mavlink_au_uav_t, au_alt) }, \
         { "au_target_lat", NULL, MAVLINK_TYPE_INT32_T, 0, 12, offsetof(mavlink_au_uav_t, au_target_lat) }, \
         { "au_target_lng", NULL, MAVLINK_TYPE_INT32_T, 0, 16, offsetof(mavlink_au_uav_t, au_target_lng) }, \
         { "au_target_alt", NULL, MAVLINK_TYPE_INT32_T, 0, 20, offsetof(mavlink_au_uav_t, au_target_alt) }, \
         { "au_ground_speed", NULL, MAVLINK_TYPE_INT32_T, 0, 24, offsetof(mavlink_au_uav_t, au_ground_speed) }, \
         { "au_target_bearing", NULL, MAVLINK_TYPE_INT32_T, 0, 28, offsetof(mavlink_au_uav_t, au_target_bearing) }, \
         { "au_distance", NULL, MAVLINK_TYPE_INT32_T, 0, 32, offsetof(mavlink_au_uav_t, au_distance) }, \
         { "au_target_wp_index", NULL, MAVLINK_TYPE_UINT8_T, 0, 36, offsetof(mavlink_au_uav_t, au_target_wp_index) }, \
         } \
}


/**
 * @brief Pack a au_uav message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param au_lat Current latitude
 * @param au_lng Current longitude
 * @param au_alt Current altitude
 * @param au_target_lat Target latitude
 * @param au_target_lng Target longitude
 * @param au_target_alt Target altitude
 * @param au_ground_speed Current ground speed
 * @param au_target_bearing Desired bearing to wp in degrees
 * @param au_distance Distance to target waypoint
 * @param au_target_wp_index Target waypoint index
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_au_uav_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       int32_t au_lat, int32_t au_lng, int32_t au_alt, int32_t au_target_lat, int32_t au_target_lng, int32_t au_target_alt, int32_t au_ground_speed, int32_t au_target_bearing, int32_t au_distance, uint8_t au_target_wp_index)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[37];
	_mav_put_int32_t(buf, 0, au_lat);
	_mav_put_int32_t(buf, 4, au_lng);
	_mav_put_int32_t(buf, 8, au_alt);
	_mav_put_int32_t(buf, 12, au_target_lat);
	_mav_put_int32_t(buf, 16, au_target_lng);
	_mav_put_int32_t(buf, 20, au_target_alt);
	_mav_put_int32_t(buf, 24, au_ground_speed);
	_mav_put_int32_t(buf, 28, au_target_bearing);
	_mav_put_int32_t(buf, 32, au_distance);
	_mav_put_uint8_t(buf, 36, au_target_wp_index);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 37);
#else
	mavlink_au_uav_t packet;
	packet.au_lat = au_lat;
	packet.au_lng = au_lng;
	packet.au_alt = au_alt;
	packet.au_target_lat = au_target_lat;
	packet.au_target_lng = au_target_lng;
	packet.au_target_alt = au_target_alt;
	packet.au_ground_speed = au_ground_speed;
	packet.au_target_bearing = au_target_bearing;
	packet.au_distance = au_distance;
	packet.au_target_wp_index = au_target_wp_index;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 37);
#endif

	msg->msgid = MAVLINK_MSG_ID_AU_UAV;
	return mavlink_finalize_message(msg, system_id, component_id, 37, 58);
}

/**
 * @brief Pack a au_uav message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param au_lat Current latitude
 * @param au_lng Current longitude
 * @param au_alt Current altitude
 * @param au_target_lat Target latitude
 * @param au_target_lng Target longitude
 * @param au_target_alt Target altitude
 * @param au_ground_speed Current ground speed
 * @param au_target_bearing Desired bearing to wp in degrees
 * @param au_distance Distance to target waypoint
 * @param au_target_wp_index Target waypoint index
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_au_uav_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           int32_t au_lat,int32_t au_lng,int32_t au_alt,int32_t au_target_lat,int32_t au_target_lng,int32_t au_target_alt,int32_t au_ground_speed,int32_t au_target_bearing,int32_t au_distance,uint8_t au_target_wp_index)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[37];
	_mav_put_int32_t(buf, 0, au_lat);
	_mav_put_int32_t(buf, 4, au_lng);
	_mav_put_int32_t(buf, 8, au_alt);
	_mav_put_int32_t(buf, 12, au_target_lat);
	_mav_put_int32_t(buf, 16, au_target_lng);
	_mav_put_int32_t(buf, 20, au_target_alt);
	_mav_put_int32_t(buf, 24, au_ground_speed);
	_mav_put_int32_t(buf, 28, au_target_bearing);
	_mav_put_int32_t(buf, 32, au_distance);
	_mav_put_uint8_t(buf, 36, au_target_wp_index);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, 37);
#else
	mavlink_au_uav_t packet;
	packet.au_lat = au_lat;
	packet.au_lng = au_lng;
	packet.au_alt = au_alt;
	packet.au_target_lat = au_target_lat;
	packet.au_target_lng = au_target_lng;
	packet.au_target_alt = au_target_alt;
	packet.au_ground_speed = au_ground_speed;
	packet.au_target_bearing = au_target_bearing;
	packet.au_distance = au_distance;
	packet.au_target_wp_index = au_target_wp_index;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, 37);
#endif

	msg->msgid = MAVLINK_MSG_ID_AU_UAV;
	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 37, 58);
}

/**
 * @brief Encode a au_uav struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param au_uav C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_au_uav_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_au_uav_t* au_uav)
{
	return mavlink_msg_au_uav_pack(system_id, component_id, msg, au_uav->au_lat, au_uav->au_lng, au_uav->au_alt, au_uav->au_target_lat, au_uav->au_target_lng, au_uav->au_target_alt, au_uav->au_ground_speed, au_uav->au_target_bearing, au_uav->au_distance, au_uav->au_target_wp_index);
}

/**
 * @brief Send a au_uav message
 * @param chan MAVLink channel to send the message
 *
 * @param au_lat Current latitude
 * @param au_lng Current longitude
 * @param au_alt Current altitude
 * @param au_target_lat Target latitude
 * @param au_target_lng Target longitude
 * @param au_target_alt Target altitude
 * @param au_ground_speed Current ground speed
 * @param au_target_bearing Desired bearing to wp in degrees
 * @param au_distance Distance to target waypoint
 * @param au_target_wp_index Target waypoint index
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_au_uav_send(mavlink_channel_t chan, int32_t au_lat, int32_t au_lng, int32_t au_alt, int32_t au_target_lat, int32_t au_target_lng, int32_t au_target_alt, int32_t au_ground_speed, int32_t au_target_bearing, int32_t au_distance, uint8_t au_target_wp_index)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
	char buf[37];
	_mav_put_int32_t(buf, 0, au_lat);
	_mav_put_int32_t(buf, 4, au_lng);
	_mav_put_int32_t(buf, 8, au_alt);
	_mav_put_int32_t(buf, 12, au_target_lat);
	_mav_put_int32_t(buf, 16, au_target_lng);
	_mav_put_int32_t(buf, 20, au_target_alt);
	_mav_put_int32_t(buf, 24, au_ground_speed);
	_mav_put_int32_t(buf, 28, au_target_bearing);
	_mav_put_int32_t(buf, 32, au_distance);
	_mav_put_uint8_t(buf, 36, au_target_wp_index);

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AU_UAV, buf, 37, 58);
#else
	mavlink_au_uav_t packet;
	packet.au_lat = au_lat;
	packet.au_lng = au_lng;
	packet.au_alt = au_alt;
	packet.au_target_lat = au_target_lat;
	packet.au_target_lng = au_target_lng;
	packet.au_target_alt = au_target_alt;
	packet.au_ground_speed = au_ground_speed;
	packet.au_target_bearing = au_target_bearing;
	packet.au_distance = au_distance;
	packet.au_target_wp_index = au_target_wp_index;

	_mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_AU_UAV, (const char *)&packet, 37, 58);
#endif
}

#endif

// MESSAGE AU_UAV UNPACKING


/**
 * @brief Get field au_lat from au_uav message
 *
 * @return Current latitude
 */
static inline int32_t mavlink_msg_au_uav_get_au_lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  0);
}

/**
 * @brief Get field au_lng from au_uav message
 *
 * @return Current longitude
 */
static inline int32_t mavlink_msg_au_uav_get_au_lng(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  4);
}

/**
 * @brief Get field au_alt from au_uav message
 *
 * @return Current altitude
 */
static inline int32_t mavlink_msg_au_uav_get_au_alt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  8);
}

/**
 * @brief Get field au_target_lat from au_uav message
 *
 * @return Target latitude
 */
static inline int32_t mavlink_msg_au_uav_get_au_target_lat(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  12);
}

/**
 * @brief Get field au_target_lng from au_uav message
 *
 * @return Target longitude
 */
static inline int32_t mavlink_msg_au_uav_get_au_target_lng(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  16);
}

/**
 * @brief Get field au_target_alt from au_uav message
 *
 * @return Target altitude
 */
static inline int32_t mavlink_msg_au_uav_get_au_target_alt(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  20);
}

/**
 * @brief Get field au_ground_speed from au_uav message
 *
 * @return Current ground speed
 */
static inline int32_t mavlink_msg_au_uav_get_au_ground_speed(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  24);
}

/**
 * @brief Get field au_target_bearing from au_uav message
 *
 * @return Desired bearing to wp in degrees
 */
static inline int32_t mavlink_msg_au_uav_get_au_target_bearing(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  28);
}

/**
 * @brief Get field au_distance from au_uav message
 *
 * @return Distance to target waypoint
 */
static inline int32_t mavlink_msg_au_uav_get_au_distance(const mavlink_message_t* msg)
{
	return _MAV_RETURN_int32_t(msg,  32);
}

/**
 * @brief Get field au_target_wp_index from au_uav message
 *
 * @return Target waypoint index
 */
static inline uint8_t mavlink_msg_au_uav_get_au_target_wp_index(const mavlink_message_t* msg)
{
	return _MAV_RETURN_uint8_t(msg,  36);
}

/**
 * @brief Decode a au_uav message into a struct
 *
 * @param msg The message to decode
 * @param au_uav C-struct to decode the message contents into
 */
static inline void mavlink_msg_au_uav_decode(const mavlink_message_t* msg, mavlink_au_uav_t* au_uav)
{
#if MAVLINK_NEED_BYTE_SWAP
	au_uav->au_lat = mavlink_msg_au_uav_get_au_lat(msg);
	au_uav->au_lng = mavlink_msg_au_uav_get_au_lng(msg);
	au_uav->au_alt = mavlink_msg_au_uav_get_au_alt(msg);
	au_uav->au_target_lat = mavlink_msg_au_uav_get_au_target_lat(msg);
	au_uav->au_target_lng = mavlink_msg_au_uav_get_au_target_lng(msg);
	au_uav->au_target_alt = mavlink_msg_au_uav_get_au_target_alt(msg);
	au_uav->au_ground_speed = mavlink_msg_au_uav_get_au_ground_speed(msg);
	au_uav->au_target_bearing = mavlink_msg_au_uav_get_au_target_bearing(msg);
	au_uav->au_distance = mavlink_msg_au_uav_get_au_distance(msg);
	au_uav->au_target_wp_index = mavlink_msg_au_uav_get_au_target_wp_index(msg);
#else
	memcpy(au_uav, _MAV_PAYLOAD(msg), 37);
#endif
}
