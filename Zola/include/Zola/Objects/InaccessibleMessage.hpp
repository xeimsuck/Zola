/*!
    @file
    @brief InaccessibleMessage object
    @author Xeim
    @version 0.2
    @data 13.08.24

    This object describes a message that was deleted or is otherwise inaccessible to the bot.
 */

#ifndef ZOLA_OBJECTS_INACCESSIBLEMESSAGE_HPP
#define ZOLA_OBJECTS_INACCESSIBLEMESSAGE_HPP

#include <optional>
#include <string>
#include <nlohmann/json.hpp>
#include "Chat.hpp"

namespace Zola::Objects {
    struct InaccessibleMessage {
        /*!
         * @brief Default constructor
         */
        InaccessibleMessage() = default;

        explicit InaccessibleMessage(const nlohmann::json& data);

        /*!
         * @brief Cast to json
         */
        explicit operator nlohmann::json() const;

        /*!
         * @brief Parse InaccessibleMessage to json format
         */
        nlohmann::json toJson() const;

        /*!
         * @brief Chat the message belonged to
         */
        Chat chat;

        /*!
         * @brief 	Unique message identifier inside the chat
         */
        int message_id = 0;

        /*!
         * @brief Always 0. The field can be used to differentiate
         * regular and inaccessible messages.
         */
        int date = 0;
    };
}

#endif //ZOLA_OBJECTS_INACCESSIBLEMESSAGE_HPP
