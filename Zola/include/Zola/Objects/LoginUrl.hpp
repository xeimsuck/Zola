/*!
    @file
    @brief LoginUrl object.
    @author Xeim
    @version 0.2
    @data 13.08.24

    This object represents a parameter of the inline keyboard button used
    to automatically authorize a user. Serves as a great replacement for the
    Telegram Login Widget when the user is coming from Telegram. All the user
    needs to do is tap/click a button and confirm that they want to log in.
 */

#ifndef ZOLA_OBJECTS_LOGINURL_HPP
#define ZOLA_OBJECTS_LOGINURL_HPP

#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace Zola::Objects {
    struct LoginUrl {
        /*!
        * @brief Default constructor.
        */
        LoginUrl() = default;

        /*!
         * @brief Parse json
         * @param data Json LogicUrl
         */
        LoginUrl(const nlohmann::json& data);


        /*!
         * @brief An HTTPS URL to be opened with user authorization data.
         *
         * An HTTPS URL to be opened with user authorization data added to
         * the query string when the button is pressed. If the user refuses
         * to provide authorization data, the original URL without information
         * about the user will be opened.
         */
        std::string url;

        /*!
         * @brief New text of the button in forwarded messages.
         */
        std::optional<std::string> forward_text;

        /*!
         * @brief Username of a bot, which will be used for user authorization.
         *
         * The url's domain must be the same as the domain linked with the bot.
         */
        std::optional<std::string> bot_username;

        /*!
         * @brief Pass True to request the permission for your bot to send messages to the user.
         */
        std::optional<bool> request_write_access;
    };
}

#endif //ZOLA_OBJECTS_LOGINURL_HPP
