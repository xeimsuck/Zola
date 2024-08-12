#include "Zola/Bot.hpp"

using namespace nlohmann;

//! Bot initialization
Zola::Bot& Zola::Bot::init(std::string _token) {
    static Bot bot(std::move(_token));
    return bot;
}

//! Private constructor
Zola::Bot::Bot(std::string _token) :
                token(std::move(_token)),
                api(token) {
}

//! Return a bot token
const std::string& Zola::Bot::getToken() const {
    return token;
}

//! Return a event handler
Zola::EventHandler& Zola::Bot::getEventHandler() {
    return eventHandler;
}

//! Return a api
Zola::API &Zola::Bot::getAPI() {
    return api;
}

//! Run a bot using a bot token
void Zola::Bot::run() {
    int updateOffset = 0;
    while (true){
        auto updates = json::parse(api.getUpdates(updateOffset));
        if(!updates["ok"]){
            eventHandler.errorHandler(Objects::Error(updates["error_code"], updates["description"]));
        }
        std::for_each(updates["result"].begin(), updates["result"].end(), [&](const auto& unparsedUpdate){
            Objects::Update update(unparsedUpdate);
            updateOffset = update.update_id+1;
            eventHandler.updateHandler(update);
        });
        sleep(1);
    }
}