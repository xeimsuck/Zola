/*!
    @file
    @brief CallbackQuery object
    @author Xeim
    @version 0.2
    @data 13.08.24

    This object represents an incoming callback query from a callback button
    in an inline keyboard. If the button that originated the query was attached
    to a message sent by the bot, the field message will be present. If the button
    was attached to a message sent via the bot (in inline mode), the field inline_message_id
    will be present. Exactly one of the fields data or game_short_name will be present.
 */

#ifndef ZOLA_OBJECTS_CALLBACKQUERY_HPP
#define ZOLA_OBJECTS_CALLBACKQUERY_HPP

#include <optional>
#include <string>
#include <nlohmann/json.hpp>
#include "User.hpp"
#include "Message.hpp"
#include "InaccessibleMessage.hpp"

namespace Zola::Objects {
    struct CallbackQuery {
        /*!
         * @brief Default constructor.
         */
        CallbackQuery() = default;

        /*!
         * @brief Parse json.
         * @param data Json CallbackQuery
         */
        explicit CallbackQuery(const nlohmann::json& data);

        /*!
         * @brief Unique identifier for this query.
         */
        std::string id;

        /*!
         * @brief Global identifier, uniquely corresponding to the chat to which the message with the callback button was sent.
         */
        std::string chat_instance;

        /*!
         * @brief Sender.
         */
        User from;

        /*!
         * @brief Identifier of the message sent via the bot in inline mode, that originated the query.
         */
        std::optional<std::string> inline_message_id;

        /*!
         * @brief Data associated with the callback button.
         *
         * Be aware that the message originated the query can contain no callback buttons with this data.
         */
        std::optional<std::string> data;

        /*!
         * @brief Short name of a Game to be returned, serves as the unique identifier for the game.
         */
        std::optional<std::string> game_short_name;


        /*!
         * @brief Message sent by the bot with the callback button that originated the query.
         * May be InaccessibleMessage
         */
        std::optional<Message> message;
    };
}

#endif //ZOLA_OBJECTS_CALLBACKQUERY_HPP
