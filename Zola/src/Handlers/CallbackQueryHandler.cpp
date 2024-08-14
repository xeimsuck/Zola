#include <Zola/Handlers/CallbackQueryHandler.hpp>

using namespace Zola;
using namespace Zola::Handlers;
using Handler = CallbackQueryHandler::Handler;

void CallbackQueryHandler::operator()(const Objects::CallbackQuery &callbackQuery) {
    call(callbackQuery);
}

Handler &CallbackQueryHandler::operator[](const std::string &data) {
    return handlers[data];
}

void CallbackQueryHandler::call(const Objects::CallbackQuery &callbackQuery) {
    if(anyHandler) anyHandler(callbackQuery);
    if(!callbackQuery.data) return;
    if(handlers.contains(callbackQuery.data.value())){
        handlers[callbackQuery.data.value()](callbackQuery);
    } else if(unknownHandler) {
        unknownHandler(callbackQuery);
    }
}

void CallbackQueryHandler::add(const std::string& data, CallbackQueryHandler::Handler handler) {
    handlers[data] = std::move(handler);
}

void CallbackQueryHandler::addUnknown(CallbackQueryHandler::Handler handler) {
    unknownHandler = std::move(handler);
}

void CallbackQueryHandler::addAny(CallbackQueryHandler::Handler handler) {
    anyHandler = std::move(handler);
}