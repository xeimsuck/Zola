#include <Zola/Zola.hpp>

using namespace Zola;

int main(int argc, char*argv[]){
    decltype(auto) bot = Bot::init("YOUR_BOT_TOKEN");
    bot.getEventHandler().getMessageHandler().addAny([&](const Objects::Message& msg){
        bot.getAPI().sendMessage("text", msg.chat.id);
    });
    try {
        bot.run();
    } catch (const std::exception& ex){
        std::cerr << ex.what();
        return 1;
    }
    return 0;
}