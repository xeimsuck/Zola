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
#include "Chat.hpp"
#include "User.hpp"

namespace Zola{
    namespace Objects {
        struct Message {
            int message_id=0;
            std::optional<std::string> from;
            int date;
            Chat chat;
            std::optional<User> forward_from;
            std::optional<int> forward_date;
            //TODO: optional param - reply_to_message
            std::optional<std::string> text;

        };
    }
}

#endif //ZOLA_OBJECTS_MESSAGE_HPP
