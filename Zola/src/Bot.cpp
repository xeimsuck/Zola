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
                url(std::format("https://api.telegram.org/bot{}/getUpdates", token)) {
}

//! Return a bot token
const std::string& Zola::Bot::getToken() const {
    return token;
}

//! Return a event handler
Zola::EventHandler& Zola::Bot::getEventHandler() {
    return eventHandler;
}

//! Run a bot using a bot token
void Zola::Bot::run() {
    int updateOffset = 0;
    while (true){
        auto updates = json::parse(
                url.makeRequest({
                    {"offset", std::to_string(updateOffset)}
                })
        );
        if(!updates["ok"]){
            eventHandler.ErrorHandler(Objects::Error(updates["error_code"], updates["description"]));
        }
        std::for_each(updates["result"].begin(), updates["result"].end(), [&](const auto& unparsedUpdate){
            Objects::Update update(unparsedUpdate);
            updateOffset = update.update_id+1;
            eventHandler.UpdateHandler(update);
        });
        sleep(1);
    }
}