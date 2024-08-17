/*!
	@file
	@brief ChatMemberLeft object.
	@author Xeim
	@version 0.2
	@data 17.08.24

	Represents a chat member that isn't currently a member of the chat, but may join it themselves.
 */

#ifndef ZOLA_OBJECTS_CHATMEMBERLEFT_HPP
#define ZOLA_OBJECTS_CHATMEMBERLEFT_HPP

#include "ChatMember.hpp"

namespace Zola::Objects {
	struct ChatMemberLeft final : ChatMember{
		/*!
		 * @brief The value for the status attribute, always "left".
		 */
		static constexpr std::string LEFT_STATUS = "left";

		ChatMemberLeft();

		/*!
		 * Parse json format.
		 * @param data Json data.
		 */
		explicit ChatMemberLeft(const nlohmann::json& data);

		/*!
		 * @brief Default override destructor.
		 */
		~ChatMemberLeft() override = default;

		/*!
		 * @brief Parse ChatMemberLeftto json format.
		 */
		[[nodiscard]] nlohmann::json toJson() const override;
	};
}

#endif //ZOLA_OBJECTS_CHATMEMBERLEFT_HPP
