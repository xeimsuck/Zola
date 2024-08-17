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
		ChatMemberError();

		ChatMemberError(long error_code, const std::string& description);

		/*!
		 * @brief Parse ChatMemberError to json format.
		 */
		[[nodiscard]] nlohmann::json toJson() const override;


		/*!
		 * @brief Code of error
		 */
		long error_code = 0;

		/*!
		 * @brief Error description
		 */
		std::string description;
	};
}

#endif //ZOLA_OBJECTS_CHATMEMBERERROR_HPP
