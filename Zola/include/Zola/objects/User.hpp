/*!
    \file
    \brief User object
    \author Xeim
    \version 0.1
    \data 09.08.24

    This struct contains information about user
 */

#ifndef ZOLA_OBJECTS_USER_HPP
#define ZOLA_OBJECTS_USER_HPP

#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace Zola{
    namespace Objects {
        struct User {
            explicit User(const nlohmann::json& data);
            int id;
            bool is_bot;
            std::string first_name;
            std::optional<std::string> last_name;
            std::optional<std::string> username;
        };
    }
}

#endif //ZOLA_OBJECTS_USER_HPP
