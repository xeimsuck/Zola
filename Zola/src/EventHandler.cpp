#include <Zola/EventHandler.hpp>

using namespace Zola;
using namespace Zola::Handlers;

//! Handle update event
void EventHandler::updateHandler(const Objects::Update &update) {
    if(update.message.has_value()) {
        const std::string& text = update.message.value().text.value_or(" ");
        if(text.empty() || text.front()!='/') {
            messageHandler(update.message.value());
        } else {
            commandHandler(update.message.value());
        }
    } else if(update.edited_message.has_value()){
        editedMessageHandler(update.edited_message.value());
    }
}

//! Handle error event
void EventHandler::errorHandler(const Objects::Error &error) {
}

//! Return message handler
MessageHandler &EventHandler::getMessageHandler() {
    return messageHandler;
}

//! Return command handler
MessageHandler &EventHandler::getCommandHandler() {
    return commandHandler;
}

//! Return edited message handler
MessageHandler &EventHandler::getEditedMessageHandler() {
    return editedMessageHandler;
}