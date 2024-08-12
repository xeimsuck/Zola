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

#include <iostream>
#include <functional>
#include "Objects/Update.hpp"
#include "Objects/Error.hpp"
#include <Zola/Handlers/MessageHandler.hpp>

namespace Zola {
    class EventHandler {
    public:
        void updateHandler(const Objects::Update& update);
        void errorHandler(const Objects::Error& error);
        Handlers::MessageHandler& getMessageHandler();
        Handlers::MessageHandler& getCommandHandler();
        Handlers::MessageHandler& getEditedMessageHandler();
    private:
        Handlers::MessageHandler messageHandler;
        Handlers::MessageHandler commandHandler;
        Handlers::MessageHandler editedMessageHandler;
    };
}

#endif //ZOLA_EVENTHANDLER_HPP
