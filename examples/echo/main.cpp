#include <Zola/Zola.hpp>

using namespace Zola;

int main(int argc, char*argv[]){
    decltype(auto) bot = Bot::init("7047048031:AAEbb5yTcq5Gd86ecYjnsUg2Qore3pgAAzg");
    bot.getEventHandler().getMessageHandler().addAny([&](const Objects::Message& msg){
        if(msg.text){
            bot.getAPI().sendMessage(msg.text.value(), msg.chat.id);
        } else if(msg.sticker){
            bot.getAPI().sendSticker(msg.sticker->file_id, msg.chat.id);
        } else if(msg.video){
            bot.getAPI().sendVideo(msg.video->file_id, msg.chat.id, msg.caption);
        } else if(msg.photo){
            bot.getAPI().sendPhoto(msg.photo.value().front().file_id, msg.chat.id, msg.caption);
        } else if(msg.voice){
            bot.getAPI().sendVoice(msg.voice->file_id, msg.chat.id, msg.caption);
        }
    });
    try {
        bot.run();
    } catch (const std::exception& ex){
        std::cerr << ex.what();
        return 1;
    }
    return 0;
}