/*!
    \file
    \brief Chat object
    \author Xeim
    \version 0.1
    \data 09.08.24

    This struct contains information about chat
 */

#ifndef ZOLA_OBJECTS_CHAT_HPP
#define ZOLA_OBJECTS_CHAT_HPP

#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace Zola{
    namespace Objects {
        struct Chat {
            explicit Chat(const nlohmann::json& data);
            int id;
            std::optional<std::string> title;
            std::optional<std::string> username;
            std::optional<std::string> first_name;
            std::optional<std::string> last_name;
            std::optional<bool> all_members_are_administrators;
            // TODO: add chat parameter - type (private, public..)
        };
    }
}

#endif //ZOLA_OBJECTS_CHAT_HPP
