#include <Zola/Handlers/MessageHandler.hpp>

using namespace Zola;
using namespace Zola::Handlers;

void MessageHandler::operator()(const Objects::Message &message) {
    call(message);
}

MessageHandler::Handler &MessageHandler::operator[](const std::string &text) {
    return handlers[text];
}

void MessageHandler::call(const Objects::Message& message){
    if(anyHandler) anyHandler(message);
    if(message.text.has_value() && handlers.contains(message.text.value())){
        handlers[message.text.value()](message);
    } else if(unknownHandler){
        unknownHandler(message);
    }
}

void MessageHandler::add(const std::string &message, MessageHandler::Handler handler) {
    handlers[message] = std::move(handler);
}

void MessageHandler::addUnknown(MessageHandler::Handler handler) {
    unknownHandler = std::move(handler);
}

void MessageHandler::addAny(MessageHandler::Handler handler) {
    anyHandler = std::move(handler);
}