/*!
@file
	@brief BotDescription object
	@author Xeim
	@version 0.2
	@data 14.08.24

This object represents the bot's description.
 */


#ifndef ZOLA_OBJCETS_BOTDESCRIPTION_HPP
#define ZOLA_OBJCETS_BOTDESCRIPTION_HPP

#include <string>
#include <nlohmann/json.hpp>

namespace Zola::Objects {
	struct BotDescription {
		/*!
		 * @brief Default constructor.
		 */
		BotDescription() = default;

		/*!
		 * @brief Parse json.
		 * @param data Json BotDescription.
		 */
		explicit BotDescription(const nlohmann::json& data);

		/*!
		 * @brief Cast to json.
		 */
		explicit operator nlohmann::json() const;

		/*!
		 * @brief Parse BotDescription to json format.
		 */
		[[nodiscard]]nlohmann::json toJson() const;

		/*!
		 * @brief The bot's description.
		 */
		std::string description;
	};
}

#endif //ZOLA_OBJCETS_BOTDESCRIPTION_HPP
