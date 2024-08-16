/*!
	@file
	@brief BotName object
	@author Xeim
	@version 0.2
	@data 14.08.24

	This object represents the bot's name.
 */


#ifndef ZOLA_OBJCETS_BOTNAME_HPP
#define ZOLA_OBJCETS_BOTNAME_HPP

#include <string>
#include <nlohmann/json.hpp>

namespace Zola::Objects {
	struct BotName {
		/*!
		 * @brief Default constructor.
		 */
		BotName() = default;

		/*!
		 * @brief Parse json.
		 * @param data Json BotName.
		 */
		explicit BotName(const nlohmann::json& data);

		/*!
		 * @brief Cast to json.
		 */
		explicit operator nlohmann::json() const;

		/*!
		 * @brief Parse BotName to json format.
		 */
		[[nodiscard]]nlohmann::json toJson() const;

		/*!
		 * @brief The bot's name.
		 */
		std::string name;
	};
}

#endif //ZOLA_OBJCETS_BOTNAME_HPP
