/*!
    \file
    \brief Error object
    \author Xeim
    \version 0.1
    \data 10.08.24

    This struct contains information about error
 */

#ifndef ZOLA_OBJECTS_ERROR_HPP
#define ZOLA_OBJECTS_ERROR_HPP

#include <string>

namespace Zola::Objects{
    struct Error {
        int error_code;
        std::string description;
    };
}


#endif //ZOLA_OBJECTS_ERROR_HPP
