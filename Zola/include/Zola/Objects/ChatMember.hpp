/*!
	@file This object contains information about one member of a chat.
	@brief BotDescription object
	@author Xeim
	@version 0.2
	@data 17.08.24

	It is base class for ChatMemberOwner, ChatMemberAdministrator, ChatMemberMember,
	ChatMemberRestricted, ChatMemberLeft and ChatMemberBanned classes
 */

#ifndef ZOLA_OBJECTS_CHATMEMBER_HPP
#define ZOLA_OBJECTS_CHATMEMBER_HPP

#include <string>
#include <nlohmann/json.hpp>
#include "User.hpp"

namespace Zola::Objects {
	struct ChatMember {
		/*!
		 * @brief Represent all statuses
		 */
		enum class Status {
			error, kicked, left, member, restricted, administrator, creator
		};

		/*!
		 * @brief Default constructor
		 */
		ChatMember() = default;

		/*!
		 * @brief Default virtual destructor
		 */
		virtual ~ChatMember() = default;

		/*!
		 * @brief Cast to json.
		 */
		explicit operator nlohmann::json() const;

		/*!
		 * @brief Parse BotDescription to json format.
		 */
		[[nodiscard]] virtual nlohmann::json toJson() const;

		/*!
		 * @brief The member's status in the chat.
		 */
		Status status = Status::error;

		/*!
		 * @brief Information about the user.
		 */
		User user;
    };
}

#endif //ZOLA_OBJECTS_CHATMEMBER_HPP
