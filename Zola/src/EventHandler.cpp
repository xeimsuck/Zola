#include <Zola/EventHandler.hpp>

using namespace Zola;
using namespace Zola::Handlers;

//! Handle update event
void EventHandler::updateHandler(const Objects::Update &update) {
    if(update.message) {
        const std::string& text = update.message.value().text.value_or(" ");
        if(text.empty() || text.front()!='/') {
            messageHandler(update.message.value());
        } else {
            commandHandler(update.message.value());
        }
    } else if(update.edited_message){
        editedMessageHandler(update.edited_message.value());
    } else if(update.channel_post){
        channelPostHandler(update.channel_post.value());
    } else if(update.edited_channel_post) {
        editedChannelPostHandler(update.edited_channel_post.value());
    } else if(update.callback_query){
        callbackQueryHandler(update.callback_query.value());
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
CommandHandler &EventHandler::getCommandHandler() {
    return commandHandler;
}

//! Return edited message handler
MessageHandler &EventHandler::getEditedMessageHandler() {
    return editedMessageHandler;
}

//! Return channel post handler
MessageHandler &EventHandler::getChannelPostHandler() {
    return channelPostHandler;
}

//! Return edited channel post handler
MessageHandler &EventHandler::getEditedChannelPostHandler() {
    return editedChannelPostHandler;
}

/*!
 * @return Callback query handler
 */
CallbackQueryHandler &EventHandler::getCallbackQueryHandler() {
    return callbackQueryHandler;
}

