/*!
    \file
    \brief Event handler
    \author Xeim
    \version 0.1
    \data 12.08.24

    Class that handles events
 */

#ifndef ZOLA_EVENTHANDLER_HPP
#define ZOLA_EVENTHANDLER_HPP

#include "objects/Update.hpp"
#include "objects/Error.hpp"
#include "objects/Message.hpp"
#include "objects/User.hpp"
#include "objects/Chat.hpp"

namespace Zola {
    class EventHandler {
    public:
        void UpdateHandler(const Objects::Update& update);
        void ErrorHandler(const Objects::Error& error);
    };
}

#endif //ZOLA_EVENTHANDLER_HPP
