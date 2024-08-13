#include "Zola/Bot.hpp"

using namespace Zola;
using namespace nlohmann;

/*!
 * Singleton initialization
 * @param _token Bot token
 * @return Singleton bot
 */
Bot& Zola::Bot::init(std::string _token) {
    static Bot bot(std::move(_token));
    return bot;
}

/*!
 * Initialization bot
 * @param _token Bot token
 */
Bot::Bot(std::string _token) :
                token(std::move(_token)),
                api(token) {
}

/*!
 * @return Bot Token
 */
const std::string& Bot::getToken() const {
    return token;
}

/*!
 * @return Bot EventHandler
 */
EventHandler& Bot::getEventHandler() {
    return eventHandler;
}

/*!
 * @return Bot API
 */
API &Bot::getAPI() {
    return api;
}

/*!
 * Run a bot using a token
 * @param delay delay between getUpdates methods
 */
void Bot::run(const int delay) {
    long updateOffset = 0;
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
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}