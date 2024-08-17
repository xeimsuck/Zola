/*!
	@file
	@brief ChatMemberError object.
	@author Xeim
	@version 0.2
	@data 17.08.24

	Represents an object when getChatMember finished with error.
 */

#ifndef ZOLA_OBJECTS_CHATMEMBERERROR_HPP
#define ZOLA_OBJECTS_CHATMEMBERERROR_HPP

#include <string>
#include <optional>
#include "ChatMember.hpp"

namespace Zola::Objects {
	struct ChatMemberError final : ChatMember {
		/*!
		 * @brief The value for the status attribute, always "error".
		 */
		static constexpr std::string ERROR_STATUS = "error";

		ChatMemberError();

		/*!
		 * @brief Parse ChatMemberError to json format.
		 */
		[[nodiscard]] nlohmann::json toJson() const override;
	};
}

#endif //ZOLA_OBJECTS_CHATMEMBERERROR_HPP
