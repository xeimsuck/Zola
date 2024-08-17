/*!
@file
	@brief ChatMemberMember object.
	@author Xeim
	@version 0.2
	@data 17.08.24

	Represents a chat member that has no additional privileges or restrictions.
 */

#ifndef ZOLA_OBJECTS_CHATMEMBERMEMBER_HPP
#define ZOLA_OBJECTS_CHATMEMBERMEMBER_HPP

#include <string>
#include <optional>
#include "ChatMember.hpp"

namespace Zola::Objects {
	struct ChatMemberMember final : ChatMember {
		/*!
 		 * @brief The value for the status attribute, always "member".
 		 */
		static constexpr std::string MEMBER_STATUS = "member";

		ChatMemberMember();

		/*!
		 * Parse json format.
		 * @param data Json data.
		 */
		explicit ChatMemberMember(const nlohmann::json& data);

		/*!
		 * @brief Default override destructor
		 */
		~ChatMemberMember() override = default;

		/*!
		 * @brief Parse ChatMemberMember to json format.
		 */
		[[nodiscard]] nlohmann::json toJson() const override;

		/*!
		 * @brief Date when the user's subscription will expire; Unix time
		 */
		std::optional<long> until_date;
	};
}

#endif //ZOLA_OBJECTS_CHATMEMBERMEMBER_HPP
