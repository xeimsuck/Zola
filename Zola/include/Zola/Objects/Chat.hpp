/*!
    @file
    @brief Chat object
    @author Xeim
    @version 0.2
    @data 14.08.24

    This object represents a chat.
 */

#ifndef ZOLA_OBJECTS_CHAT_HPP
#define ZOLA_OBJECTS_CHAT_HPP

#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace Zola::Objects {
    struct Chat {
        /*!
         * @brief Default constructor
         */
        Chat() = default;

        /*!
         * @brief Parse json.
         * @param data Json CallbackQuery
         */
        explicit Chat(const nlohmann::json& data);

        /*!
         * Cast to json
         */
        explicit operator nlohmann::json() const;

        /*!
         * @brief Parse InaccessibleMessage to json format
         */
        [[nodiscard]]nlohmann::json toJson() const;

        /*!
         * @brief Unique identifier for this chat.
         *
         * This number may have more than 32 significant bits and
         * some programming languages may have difficulty/silent
         * defects in interpreting it. But it has at most 52
         * significant bits, so a signed 64-bit integer or
         * double-precision float type are safe for storing
         * this identifier.
         */
        long id = 0;

        /*!
         * @brief Type of the chat, can be either “private”, “group”, “supergroup” or “channel”.
         */
        std::string type;

        /*!
         * Title, for supergroups, channels and group chats.
         */
        std::optional<std::string> title;

        /*!
         * @brief Username, for private chats, supergroups and channels if available.
         */
        std::optional<std::string> username;

        /*!
         * @brief First name of the other party in a private chat.
         */
        std::optional<std::string> first_name;

        /*!
         * @brief Last name of the other party in a private chat.
         */
        std::optional<std::string> last_name;

        /*!
         * @brief True, if the supergroup chat is a forum.
         */
        std::optional<bool> is_forum;
    };
}

#endif //ZOLA_OBJECTS_CHAT_HPP
