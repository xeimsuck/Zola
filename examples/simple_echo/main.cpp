#include <Zola/Zola.hpp>

using namespace Zola;

int main(int argc, char*argv[]){
    decltype(auto) bot = Bot::init("7047048031:AAEbb5yTcq5Gd86ecYjnsUg2Qore3pgAAzg");
    bot.getEventHandler().getMessageHandler().addAny([&](const Objects::Message& msg){
        bot.getAPI().sendMessage(msg.text.value_or("It is not message"), msg.chat.id);
    });
    try {
        bot.run();
    } catch (const std::exception& ex){
        std::cerr << ex.what();
        return 1;
    }
    return 0;
}