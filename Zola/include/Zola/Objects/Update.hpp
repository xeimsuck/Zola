/*!
    \file
    \brief Update object
    \author Xeim
    \version 0.1
    \data 09.08.24

    This struct contains information about update
 */

#ifndef ZOLA_OBJECTS_UPDATE_HPP
#define ZOLA_OBJECTS_UPDATE_HPP

#include <optional>
#include <nlohmann/json.hpp>
#include "Message.hpp"

namespace Zola::Objects{
    struct Update{
        explicit Update(const nlohmann::json& data);
        long update_id;
        std::optional<Message> message;
        std::optional<Message> edited_message;
    };
}

#endif //ZOLA_OBJECTS_UPDATE_HPP
