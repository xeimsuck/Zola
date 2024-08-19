#include <Zola/Zola.hpp>

using namespace Zola;
using namespace Zola::Handlers;
using namespace Zola::Objects;

int main(int argc, char*argv[]){
    auto& bot = Bot::init("7270679735:AAGsHK_SG9wqAWX3AvsRhLF_24yG_ZYkn5E");
    auto& event = bot.getEventHandler();
    auto& api = bot.getAPI();

    InlineKeyboardButton pingButton;
    pingButton.text = "Ping";
    pingButton.callback_data = "PingPressed";
    InlineKeyboardMarkup markup(std::vector<std::vector<InlineKeyboardButton>>{{pingButton}});

    event.getCommandHandler().add("/start", [&](const Message& command, const std::vector<std::string>& params){
        api.sendMessage("Hi! Press a button to ping a server.", command.from->id, markup);
    });
    event.getCallbackQueryHandler().add("PingPressed", [&](const CallbackQuery& cq){
       api.answerCallbackQuery(cq.id, "Pinger Bot", true);
    });


    try {
        bot.run();
    } catch (const std::exception& ex){
        std::cerr << ex.what();
        return 1;
    }
    return 0;
}