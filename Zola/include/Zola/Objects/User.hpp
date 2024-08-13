/*!
    @file
    @brief User object
    @author Xeim
    @version 0.1
    @data 09.08.24

    This object represents a Telegram user or bot.
 */

#ifndef ZOLA_OBJECTS_USER_HPP
#define ZOLA_OBJECTS_USER_HPP

#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace Zola::Objects{
    struct User {
        /*!
         * @brief Default constructor
        */
        User() = default;

        /*!
         * @brief Parse json
         * @param data Json user
         */
        explicit User(const nlohmann::json& data);

        /*!
         * @brief Unique identifier for this user or bot.
         *
         * This number may have more than 32 significant bits and some
         * programming languages may have difficulty/silent defects
         * in interpreting it. But it has at most 52 significant bits,
         * so a 64-bit integer or double-precision float type are safe for
         * storing this identifier.
        */
        long id=0;

        /*!
         * @brief True, if this user is a bot
         */
        bool is_bot=false;

        /*!
         * @brief User's or bot's first name
         */
        std::string first_name;

        /*!
         * @brief User's or bot's last name
         */
        std::optional<std::string> last_name;

        /*!
         * @brief User's or bot's username
         */
        std::optional<std::string> username;

        /*!
         * @brief IETF language tag of the user's language
         */
        std::optional<std::string> language_code;

        /*!
         *  @brief True, if this user is a Telegram Premium user
         */
        std::optional<bool> is_premium;

        /*!
         * @brief True, if this user added the bot to the attachment menu
         */
        std::optional<bool> added_to_attachment_menu;

        /*!
         * @brief True, if the bot can be invited to groups.
         */
        std::optional<bool> can_join_groups;

        /*!
         * @brief True, if privacy mode is disabled for the bot.
         */
        std::optional<bool> can_read_all_group_messages;

        /*!
         * @brief True, if the bot supports inline queries.
         */
        std::optional<bool> supports_inline_queries;

        /*!
         * @brief True, if the bot can be connected to a Telegram Business account to receive its messages.
         */
        std::optional<bool> can_connect_to_business;

        /*!
         * @brief True, if the bot has a main Web App.
         */
        std::optional<bool> has_main_web_app;
    };
}

#endif //ZOLA_OBJECTS_USER_HPP
