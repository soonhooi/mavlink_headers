// MESSAGE WATCHDOG_PROCESS_INFO PACKING

#define MAVLINK_MSG_ID_WATCHDOG_PROCESS_INFO 181

typedef struct __mavlink_watchdog_process_info_t
{
 int32_t timeout; ///< Timeout (seconds)
 uint16_t watchdog_id; ///< Watchdog ID
 uint16_t process_id; ///< Process ID
 char name[100]; ///< Process name
 char arguments[147]; ///< Process arguments
} mavlink_watchdog_process_info_t;

#define MAVLINK_MSG_ID_WATCHDOG_PROCESS_INFO_LEN 255
#define MAVLINK_MSG_ID_181_LEN 255

#define MAVLINK_MSG_WATCHDOG_PROCESS_INFO_FIELD_NAME_LEN 100
#define MAVLINK_MSG_WATCHDOG_PROCESS_INFO_FIELD_ARGUMENTS_LEN 147

#define MAVLINK_MESSAGE_INFO_WATCHDOG_PROCESS_INFO { \
	"WATCHDOG_PROCESS_INFO", \
	5, \
	{  { "timeout", MAVLINK_TYPE_INT32_T, 0, 0, offsetof(mavlink_watchdog_process_info_t, timeout) }, \
         { "watchdog_id", MAVLINK_TYPE_UINT16_T, 0, 4, offsetof(mavlink_watchdog_process_info_t, watchdog_id) }, \
         { "process_id", MAVLINK_TYPE_UINT16_T, 0, 6, offsetof(mavlink_watchdog_process_info_t, process_id) }, \
         { "name", MAVLINK_TYPE_CHAR, 100, 8, offsetof(mavlink_watchdog_process_info_t, name) }, \
         { "arguments", MAVLINK_TYPE_CHAR, 147, 108, offsetof(mavlink_watchdog_process_info_t, arguments) }, \
         } \
}


/**
 * @brief Pack a watchdog_process_info message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param watchdog_id Watchdog ID
 * @param process_id Process ID
 * @param name Process name
 * @param arguments Process arguments
 * @param timeout Timeout (seconds)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_watchdog_process_info_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
						       uint16_t watchdog_id, uint16_t process_id, const char *name, const char *arguments, int32_t timeout)
{
	msg->msgid = MAVLINK_MSG_ID_WATCHDOG_PROCESS_INFO;

	put_int32_t_by_index(msg, 0, timeout); // Timeout (seconds)
	put_uint16_t_by_index(msg, 4, watchdog_id); // Watchdog ID
	put_uint16_t_by_index(msg, 6, process_id); // Process ID
	put_char_array_by_index(msg, 8, name, 100); // Process name
	put_char_array_by_index(msg, 108, arguments, 147); // Process arguments

	return mavlink_finalize_message(msg, system_id, component_id, 255, 16);
}

/**
 * @brief Pack a watchdog_process_info message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param watchdog_id Watchdog ID
 * @param process_id Process ID
 * @param name Process name
 * @param arguments Process arguments
 * @param timeout Timeout (seconds)
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_watchdog_process_info_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
							   mavlink_message_t* msg,
						           uint16_t watchdog_id,uint16_t process_id,const char *name,const char *arguments,int32_t timeout)
{
	msg->msgid = MAVLINK_MSG_ID_WATCHDOG_PROCESS_INFO;

	put_int32_t_by_index(msg, 0, timeout); // Timeout (seconds)
	put_uint16_t_by_index(msg, 4, watchdog_id); // Watchdog ID
	put_uint16_t_by_index(msg, 6, process_id); // Process ID
	put_char_array_by_index(msg, 8, name, 100); // Process name
	put_char_array_by_index(msg, 108, arguments, 147); // Process arguments

	return mavlink_finalize_message_chan(msg, system_id, component_id, chan, 255, 16);
}

#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

/**
 * @brief Pack a watchdog_process_info message on a channel and send
 * @param chan The MAVLink channel this message was sent over
 * @param msg The MAVLink message to compress the data into
 * @param watchdog_id Watchdog ID
 * @param process_id Process ID
 * @param name Process name
 * @param arguments Process arguments
 * @param timeout Timeout (seconds)
 */
static inline void mavlink_msg_watchdog_process_info_pack_chan_send(mavlink_channel_t chan,
							   mavlink_message_t* msg,
						           uint16_t watchdog_id,uint16_t process_id,const char *name,const char *arguments,int32_t timeout)
{
	msg->msgid = MAVLINK_MSG_ID_WATCHDOG_PROCESS_INFO;

	put_int32_t_by_index(msg, 0, timeout); // Timeout (seconds)
	put_uint16_t_by_index(msg, 4, watchdog_id); // Watchdog ID
	put_uint16_t_by_index(msg, 6, process_id); // Process ID
	put_char_array_by_index(msg, 8, name, 100); // Process name
	put_char_array_by_index(msg, 108, arguments, 147); // Process arguments

	mavlink_finalize_message_chan_send(msg, chan, 255, 16);
}
#endif // MAVLINK_USE_CONVENIENCE_FUNCTIONS


/**
 * @brief Encode a watchdog_process_info struct into a message
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param watchdog_process_info C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_watchdog_process_info_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_watchdog_process_info_t* watchdog_process_info)
{
	return mavlink_msg_watchdog_process_info_pack(system_id, component_id, msg, watchdog_process_info->watchdog_id, watchdog_process_info->process_id, watchdog_process_info->name, watchdog_process_info->arguments, watchdog_process_info->timeout);
}

/**
 * @brief Send a watchdog_process_info message
 * @param chan MAVLink channel to send the message
 *
 * @param watchdog_id Watchdog ID
 * @param process_id Process ID
 * @param name Process name
 * @param arguments Process arguments
 * @param timeout Timeout (seconds)
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_watchdog_process_info_send(mavlink_channel_t chan, uint16_t watchdog_id, uint16_t process_id, const char *name, const char *arguments, int32_t timeout)
{
	MAVLINK_ALIGNED_MESSAGE(msg, 255);
	mavlink_msg_watchdog_process_info_pack_chan_send(chan, msg, watchdog_id, process_id, name, arguments, timeout);
}

#endif

// MESSAGE WATCHDOG_PROCESS_INFO UNPACKING


/**
 * @brief Get field watchdog_id from watchdog_process_info message
 *
 * @return Watchdog ID
 */
static inline uint16_t mavlink_msg_watchdog_process_info_get_watchdog_id(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint16_t(msg,  4);
}

/**
 * @brief Get field process_id from watchdog_process_info message
 *
 * @return Process ID
 */
static inline uint16_t mavlink_msg_watchdog_process_info_get_process_id(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_uint16_t(msg,  6);
}

/**
 * @brief Get field name from watchdog_process_info message
 *
 * @return Process name
 */
static inline uint16_t mavlink_msg_watchdog_process_info_get_name(const mavlink_message_t* msg, char *name)
{
	return MAVLINK_MSG_RETURN_char_array(msg, name, 100,  8);
}

/**
 * @brief Get field arguments from watchdog_process_info message
 *
 * @return Process arguments
 */
static inline uint16_t mavlink_msg_watchdog_process_info_get_arguments(const mavlink_message_t* msg, char *arguments)
{
	return MAVLINK_MSG_RETURN_char_array(msg, arguments, 147,  108);
}

/**
 * @brief Get field timeout from watchdog_process_info message
 *
 * @return Timeout (seconds)
 */
static inline int32_t mavlink_msg_watchdog_process_info_get_timeout(const mavlink_message_t* msg)
{
	return MAVLINK_MSG_RETURN_int32_t(msg,  0);
}

/**
 * @brief Decode a watchdog_process_info message into a struct
 *
 * @param msg The message to decode
 * @param watchdog_process_info C-struct to decode the message contents into
 */
static inline void mavlink_msg_watchdog_process_info_decode(const mavlink_message_t* msg, mavlink_watchdog_process_info_t* watchdog_process_info)
{
#if MAVLINK_NEED_BYTE_SWAP
	watchdog_process_info->timeout = mavlink_msg_watchdog_process_info_get_timeout(msg);
	watchdog_process_info->watchdog_id = mavlink_msg_watchdog_process_info_get_watchdog_id(msg);
	watchdog_process_info->process_id = mavlink_msg_watchdog_process_info_get_process_id(msg);
	mavlink_msg_watchdog_process_info_get_name(msg, watchdog_process_info->name);
	mavlink_msg_watchdog_process_info_get_arguments(msg, watchdog_process_info->arguments);
#else
	memcpy(watchdog_process_info, MAVLINK_PAYLOAD(msg), 255);
#endif
}
