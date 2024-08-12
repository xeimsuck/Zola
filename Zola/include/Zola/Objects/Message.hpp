/*!
    \file
    \brief Message object
    \author Xeim
    \version 0.1
    \data 09.08.24
    \warning is not finished

    This struct contains information about message
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

namespace Zola::Objects{
    struct Message {
        //! Constructor parse json message
        explicit Message(const nlohmann::json& data);

        //! ID of message in this chat
        long message_id;

        //! Date when message was sent in unix format
        long date;

        //! Chat in which this message was sent
        Chat chat;

        //! String content of message
        std::optional<std::string> text;

        //! User who sent this message
        std::optional<User> from;

        //! User whose message was forwarded
        std::optional<User> forward_from;

        //! Date of message which was forwarded
        std::optional<int> forward_date;

        //! Message is a sticker, information about the sticker
        std::optional<Sticker> sticker;

        //! Message is a video, information about the video
        std::optional<Video> video;

        //! Caption for the animation, audio, document, paid media, photo, video or voice
        std::optional<std::string> caption;

        //! The unique identifier of a media message group this message belongs to
        std::optional<std::string> media_group_id;

        //! Message is a photo, available sizes of the photo
        std::optional<std::vector<PhotoSize>> photo;

        //TODO: optional param - reply_to_message
    };
}

#endif //ZOLA_OBJECTS_MESSAGE_HPP
