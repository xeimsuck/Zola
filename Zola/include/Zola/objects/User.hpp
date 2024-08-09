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

namespace Zola{
    namespace Objects {
        struct User {
            int id=0;
            std::string first_name;
            std::optional<std::string> last_name;
            std::optional<std::string> username;
        };
    }
}

#endif //ZOLA_OBJECTS_USER_HPP
