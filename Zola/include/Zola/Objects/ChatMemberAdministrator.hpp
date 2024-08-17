/*!
@file
	@brief ChatMemberAdministrator object.
	@author Xeim
	@version 0.2
	@data 17.08.24

	Represents a chat member that has some additional privileges
 */

#ifndef ZOLA_OBJECTS_CHATMEMBERADMINISTRATOR_HPP
#define ZOLA_OBJECTS_CHATMEMBERADMINISTRATOR_HPP

#include <string>
#include <optional>
#include "ChatMember.hpp"

namespace Zola::Objects {
	struct ChatMemberAdministrator final : ChatMember {
		/*!
		 * @brief The value for the status attribute, always "administrator".
		 */
		static constexpr std::string ADMINISTRATOR_STATUS = "administrator";

		ChatMemberAdministrator();

		/*!
		 * Parse json format.
		 * @param data Json data.
		 */
		explicit ChatMemberAdministrator(const nlohmann::json& data);

		/*!
		 * @brief Default override destructor
		 */
		~ChatMemberAdministrator() override = default;

		/*!
		 * @brief Parse ChatMemberAdministrator to json format.
		 */
		[[nodiscard]] nlohmann::json toJson() const override;

		/*!
		 * @brief True, if the user's presence in the chat is hidden.
		 */
		bool is_anonymous = false;

		/*!
		 * @brief True, if the bot is allowed to edit administrator privileges of that user.
		 */
		bool can_be_edited = false;

		/*!
		 * @brief True, if the administrator can access the
		 * chat event log, get boost list, see hidden supergroup
		 * and channel members, report spam messages and ignore slow mode.
		 */
		bool can_manage_chat = false;

		/*!
		 * @brief True, if the administrator can delete messages of other users.
		 */
		bool can_delete_messages = false;

		/*!
		 * @brief True, if the administrator can manage video chats.
		 */
		bool can_manage_video_chats = false;

		/*!
		 * @brief True, if the administrator can restrict, ban or
		 * unban chat members, or access supergroup statistics.
		 */
		bool can_restrict_messages = false;

		/*!
		 * @brief True, if the administrator can add new administrators
		 * with a subset of their own privileges or demote administrators
		 * that they have promoted, directly or indirectly.
		 */
		bool can_promote_members = false;

		/*!
		 * @brief True, if the user is allowed to change the chat title, photo and other settings.
		 */
		bool can_change_info = false;

		/*!
		 * @brief True, if the user is allowed to invite new users to the chat.
		 */
		bool can_invite_users = false;

		/*!
		 * @brief True, if the administrator can post stories to the chat.
		 */
		bool can_post_stories = false;

		/*!
		 * @brief True, if the administrator can edit stories posted by
		 * other users, post stories to the chat page, pin chat stories,
		 * and access the chat's story archive.
		 */
		bool can_edit_stories = false;

		/*!
		 * @brief True, if the administrator can delete stories posted by other users.
		 */
		bool can_delete_stories = false;

		/*!
		 * @brief True, if the administrator can post messages in the channel,
		 * or access channel statistics; for channels only.
		 */
		std::optional<bool> can_post_messages = std::nullopt;

		/*!
		 * @brief True, if the administrator can edit messages of other
		 * users and can pin messages; for channels only.
		 */
		std::optional<bool> can_edit_messages = std::nullopt;

		/*!
		 * @brief True, if the administrator can edit messages of other
		 * users and can pin messages; for channels only.
		 */
		std::optional<bool> can_pin_messages = std::nullopt;

		/*!
		 * @brief True, if the user is allowed to create, rename,
		 * close, and reopen forum topics; for supergroups only.
		 */
		std::optional<bool> can_manage_topics = std::nullopt;

		/*!
		 * @brief Custom title for this user.
		 */
		std::optional<std::string> custom_title = std::nullopt;
	};
}

#endif //ZOLA_OBJECTS_CHATMEMBERADMINISTRATOR_HPP
