#include <iostream>
#include <Zola/Zola.hpp>

using namespace Zola;

int main(int argc, char*argv[]){
    decltype(auto) bot = Zola::Bot::init("YOUR_BOT_TOKEN");
    bot.getEventHandler().getMessageHandler().addAny([&](const Objects::Message& msg){
        if(msg.text.has_value()){
            bot.getAPI().sendMessage(msg.text.value(), msg.chat.id);
        } else if(msg.sticker.has_value()){
            bot.getAPI().sendSticker(msg.sticker->file_id, msg.chat.id);
        }
    });
    try {
        bot.run();
    } catch (const std::exception& ex){
        std::cout << ex.what() << "\n";
        return 1;
    }
    return 0;
}