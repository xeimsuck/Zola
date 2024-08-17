/*!
	@file
	@brief ChatMemberBanned object.
	@author Xeim
	@version 0.2
	@data 17.08.24

	Represents a chat member that was banned in the chat and can't return to the chat or view chat messages.
 */

#ifndef ZOLA_OBJECTS_CHATMEMBERBANNED_HPP
#define ZOLA_OBJECTS_CHATMEMBERBANNED_HPP

#include "ChatMember.hpp"

namespace Zola::Objects {
	struct ChatMemberBanned final : ChatMember{
		/*!
		 * @brief The value for the status attribute, always "kicked".
		 */
		static constexpr std::string BANNED_STATUS = "kicked";

		ChatMemberBanned();

		/*!
		 * Parse json format.
		 * @param data Json data.
		 */
		explicit ChatMemberBanned(const nlohmann::json& data);

		/*!
		 * @brief Default override destructor.
		 */
		~ChatMemberBanned() override = default;

		/*!
		 * @brief Parse ChatMemberBanned to json format.
		 */
		[[nodiscard]] nlohmann::json toJson() const override;

		/*!
		 * @brief Date when restrictions will be lifted for this user;
		 * Unix time. If 0, then the user is banned forever.
		 */
		long until_date = 0;
	};
}

#endif //ZOLA_OBJECTS_CHATMEMBERBANNED_HPP
