#include <iostream>
#include <Zola/Zola.hpp>

using namespace Zola;

int main(int argc, char*argv[]){
    decltype(auto) bot = Zola::Bot::init("YOUR TOKEN");
    bot.getEventHandler().getMessageHandler().addAny([](const Objects::Message& msg){
        std::cout << "Message: "<< msg.text.value_or("") << std::endl;
    });
    bot.getEventHandler().getCommandHandler().addAny([](const Objects::Message& msg){
        std::cout << "Command: "<< msg.text.value_or("") << std::endl;
    });
    try {
        bot.run();
    } catch (const std::exception& ex){
        std::cout << ex.what() << "\n";
        return 1;
    }
    return 0;
}