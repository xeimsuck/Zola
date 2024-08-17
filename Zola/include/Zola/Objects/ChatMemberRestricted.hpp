/*!
	@file
	@brief ChatMemberRestricted object.
	@author Xeim
	@version 0.2
	@data 17.08.24

	Represents a chat member that is under certain restrictions in the chat. Supergroups only.
 */


#ifndef ZOLA_OBJECTS_CHATMEMBERRESTRICTED_HPP
#define ZOLA_OBJECTS_CHATMEMBERRESTRICTED_HPP

#include <string>
#include <optional>
#include "ChatMember.hpp"

namespace Zola::Objects {
	struct ChatMemberRestricted final : ChatMember {
		ChatMemberRestricted();

		/*!
		 * Parse json format.
		 * @param data Json data.
		 */
		explicit ChatMemberRestricted (const nlohmann::json& data);

		/*!
		 * @brief Default override destructor.
		 */
		~ChatMemberRestricted () override = default;

		/*!
		 * @brief Parse ChatMemberRestricted to json format.
		 */
		[[nodiscard]] nlohmann::json toJson() const override;

		/*!
		 * @brief True, if the user is a member of the chat at the moment of the request.
		 */
		bool is_member = false;

		/*!
		 * @brief True, if the user is allowed to send text messages,
		 * contacts, giveaways, giveaway winners, invoices, locations and venues.
		 */
		bool can_send_message = false;

		/*!
		 * @brief True, if the user is allowed to send audios.
		 */
		bool can_send_audio = false;

		/*!
		 * @brief True, if the user is allowed to send documents.
		 */
		bool can_send_document = false;

		/*!
		 * @brief True, if the user is allowed to send photos.
		 */
		bool can_send_photos = false;

		/*!
		 * @brief True, if the user is allowed to send videos.
		 */
		bool can_send_video = false;

		/*!
		 * @brief True, if the user is allowed to send video note.
		 */
		bool can_send_video_notes = false;

		/*!
		 * @brief True, if the user is allowed to send voice notes.
		 */
		bool can_send_voice_notes = false;

		/*!
		 * @brief True, if the user is allowed to send polls.
		 */
		bool can_send_polls = false;

		/*!
		 * @brief True, if the user is allowed to send animations, games, stickers and use inline bots.
		 */
		bool can_send_other_messages = false;

		/*!
		 * @brief True, if the user is allowed to add web page previews to their messages.
		 */
		bool can_add_web_page_previews = false;

		/*!
		 * @brief True, if the user is allowed to change the chat title, photo and other settings.
		 */
		bool can_change_info = false;

		/*!
		 * @brief True, if the user is allowed to invite new users to the chat.
		 */
		bool can_invite_users = false;

		/*!
		 * @brief True, if the user is allowed to pin messages.
		 */
		bool can_pin_messages = false;

		/*!
		 * @brief True, if the user is allowed to create forum topics.
		 */
		bool can_manage_topics = false;

		/*!
		 * @brief Date when restrictions will be lifted for this user; Unix time.
		 * If 0, then the user is restricted forever.
		 */
		long until_date = 0;
	};
}

#endif //ZOLA_OBJECTS_CHATMEMBERRESTRICTED_HPP
