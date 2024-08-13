/*!
    @file
    @brief Update object
    @author Xeim
    @version 0.2
    @data 13.08.24
    @warning not finished

    This object represents an incoming update.
    At most one of the optional parameters can be present in any given update.
 */

#ifndef ZOLA_OBJECTS_UPDATE_HPP
#define ZOLA_OBJECTS_UPDATE_HPP

#include <optional>
#include <nlohmann/json.hpp>
#include "Message.hpp"
#include "CallbackQuery.hpp"

namespace Zola::Objects{
    struct Update{
        /*!
         * @brief Parse json.
         * @param data Json update.
         */
        explicit Update(const nlohmann::json& data);

        /*!
         * @brief The update's unique identifier.
         *
         * Update identifiers start from a certain positive number
         * and increase sequentially. This identifier becomes especially
         * handy if you're using webhooks, since it allows you to ignore
         * repeated updates or to restore the correct update sequence,
         * should they get out of order. If there are no new updates for
         * at least a week, then identifier of the next update will be
         * chosen randomly instead of sequentially.
         */
        long update_id;

        /*!
         * @brief New incoming message of any kind - text, photo, sticker, etc.
         */
        std::optional<Message> message;

        /*!
         * @brief New version of a message that is known to the bot and was edited.
         *
         * This update may at times be triggered by changes to message fields
         * that are either unavailable or not actively used by your bot.
         */
        std::optional<Message> edited_message;

        /*!
         * @brief New incoming channel post of any kind - text, photo, sticker, etc.
         */
        std::optional<Message> channel_post;

        /*!
         * @brief New version of a channel post that is known to the bot and was edited.
         *
         * This update may at times be triggered by changes to message fields
         * that are either unavailable or not actively used by your bot.
         */
        std::optional<Message> edited_channel_post;

        /*!
         * @brief New incoming callback query.
         */
        std::optional<CallbackQuery> callback_query;
    };
}

#endif //ZOLA_OBJECTS_UPDATE_HPP
