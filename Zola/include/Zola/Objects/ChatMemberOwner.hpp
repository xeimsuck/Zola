/*!
	@file
	@brief ChatMemberOwner object.
	@author Xeim
	@version 0.2
	@data 17.08.24

	Represents a chat member that owns the chat and has all administrator privileges.
 */

#ifndef ZOLA_OBJECTS_CHATMEMBEROWNER_HPP
#define ZOLA_OBJECTS_CHATMEMBEROWNER_HPP

#include <string>
#include <optional>
#include "ChatMember.hpp"

namespace Zola::Objects {
	struct ChatMemberOwner final : ChatMember {
		/*!
		 * @brief The value for the status attribute, always "creator".
		 */
		static constexpr std::string OWNER_STATUS = "creator";

		ChatMemberOwner();

		/*!
		 * Parse json format.
		 * @param data Json data.
		 */
		explicit ChatMemberOwner(const nlohmann::json& data);

		/*!
		 * @brief Default override destructor.
		 */
		~ChatMemberOwner() override = default;

		/*!
		 * @brief Parse ChatMemberOwner to json format.
		 */
		[[nodiscard]] nlohmann::json toJson() const override;

		/*!
		 * @brief True, if the user's presence in the chat is hidden.
		 */
		bool is_anonymous = false;

		/*!
		 * @brief Custom title for this user.
		 */
		std::optional<std::string> custom_title;
    };
}

#endif //ZOLA_OBJECTS_CHATMEMBEROWNER_HPP
