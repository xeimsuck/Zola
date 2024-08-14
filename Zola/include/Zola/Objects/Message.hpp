/*!
    @file
    @brief Message object
    @author Xeim
    @version 0.1
    @data 14.08.24
    @warning is not finished

    This object represents a message.
 */

#ifndef ZOLA_OBJECTS_MESSAGE_HPP
#define ZOLA_OBJECTS_MESSAGE_HPP

#include <string>
#include <optional>
#include <vector>
#include <nlohmann/json.hpp>
#include "Chat.hpp"
#include "User.hpp"
#include "Sticker.hpp"
#include "Video.hpp"
#include "PhotoSize.hpp"
#include "Voice.hpp"
#include "WebAppInfo.hpp"
#include "InlineKeyboardMarkup.hpp"

namespace Zola::Objects{
    struct Message {
        /*!
         * @brief Default constructor
         */
        Message() = default;

        /*!
         * Parse json format
         */
        explicit Message(const nlohmann::json& data);

        /*!
         * @brief Unique message identifier inside this chat
         */
        long message_id = 0;

        /*!
         * @brief Date the message was sent in Unix time.
         *
         * It is always a positive number, representing a valid date.
         */
        long date = 0;

        /*!
         * @brief Chat the message belongs to
         */
        Chat chat;

        /*!
         * @brief For text messages, the actual UTF-8 text of the message.
         */
        std::optional<std::string> text = std::nullopt;

        /*!
         * @brief Sender of the message, sent on behalf of a chat.
         * For example, the channel itself for channel posts, the
         * supergroup itself for messages from anonymous group
         * administrators, the linked channel for messages automatically
         * forwarded to the discussion group. For backward compatibility,
         * the field from contains a fake sender user in non-channel chats,
         * if the message was sent on behalf of a chat.
         */
        std::optional<Chat> sender_chat;

        /*!
         * @brief Sender of the message.
         *
         *  Empty for messages sent to channels. For backward compatibility,
         *  the field contains a fake sender user in non-channel chats,
         *  if the message was sent on behalf of a chat.
         */
        std::optional<User> from = std::nullopt;

        /*!
         * @brief Message is a sticker, information about the sticker
         */
        std::optional<Sticker> sticker = std::nullopt;

        /*!
         * @brief Message is a video, information about the video.
         */
        std::optional<Video> video = std::nullopt;

        /*!
         * @brief Caption for the animation, audio, document, paid media, photo, video or voice.
         */
        std::optional<std::string> caption = std::nullopt;

        /*!
         * @brief The unique identifier of a media message group this message belongs to.
         */
        std::optional<std::string> media_group_id = std::nullopt;

        /*!
         * @brief Message is a photo, available sizes of the photo.
         */
        std::optional<std::vector<PhotoSize>> photo = std::nullopt;

        /*!
         * @brief Message is a voice message, information about the file.
         */
        std::optional<Voice> voice = std::nullopt;

        /*!
         * @brief Service message: data sent by a Web App
         */
        std::optional<WebAppInfo> web_app_data = std::nullopt;

        /*!
         * @brief Inline keyboard attached to the message.
         *
         * Login_url buttons are represented as ordinary url buttons.
         */
        std::optional<InlineKeyboardMarkup> reply_markup = std::nullopt;
    };
}

#endif //ZOLA_OBJECTS_MESSAGE_HPP
