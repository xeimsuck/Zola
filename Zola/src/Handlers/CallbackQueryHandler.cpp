#include <Zola/Handlers/CallbackQueryHandler.hpp>

using namespace Zola;
using namespace Zola::Handlers;
using Handler = CallbackQueryHandler::Handler;

void CallbackQueryHandler::operator()(const Objects::CallbackQuery &callbackQuery) {
    call(callbackQuery);
}

Handler &CallbackQueryHandler::operator[](const std::string &id) {
    return handlers[id];
}

void CallbackQueryHandler::call(const Objects::CallbackQuery &callbackQuery) {
    if(anyHandler) anyHandler(callbackQuery);
    if(handlers.contains(callbackQuery.id)){
        handlers[callbackQuery.id](callbackQuery);
    } else if(unknownHandler) {
        unknownHandler(callbackQuery);
    }
}

void CallbackQueryHandler::add(const std::string &message, CallbackQueryHandler::Handler handler) {
    handlers[message] = std::move(handler);
}

void CallbackQueryHandler::addUnknown(CallbackQueryHandler::Handler handler) {
    unknownHandler = std::move(handler);
}

void CallbackQueryHandler::addAny(CallbackQueryHandler::Handler handler) {
    anyHandler = std::move(handler);
}