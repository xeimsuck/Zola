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
#include <Zola/Handlers/CallbackQueryHandler.hpp>

namespace Zola {
    class EventHandler {
    public:
        void updateHandler(const Objects::Update& update);
        void errorHandler(const Objects::Error& error);
        Handlers::MessageHandler& getMessageHandler();
        Handlers::MessageHandler& getCommandHandler();
        Handlers::MessageHandler& getEditedMessageHandler();
        Handlers::MessageHandler& getChannelPostHandler();
        Handlers::MessageHandler& getEditedChannelPostHandler();
        Handlers::CallbackQueryHandler& getCallbackQueryHandler();
    private:
        Handlers::MessageHandler messageHandler;
        Handlers::MessageHandler commandHandler;
        Handlers::MessageHandler editedMessageHandler;
        Handlers::MessageHandler channelPostHandler;
        Handlers::MessageHandler editedChannelPostHandler;
        Handlers::CallbackQueryHandler callbackQueryHandler;
    };
}

#endif //ZOLA_EVENTHANDLER_HPP
