#include <iostream>
#include "Zola/Bot.hpp"

int main(int argc, char*argv[]){
    decltype(auto) bot = Zola::Bot::init();
    try {
        bot.run("7270679735:AAGsHK_SG9wqAWX3AvsRhLF_24yG_ZYkn5E");
    } catch (std::exception ex){
        std::cout << ex.what() << "\n";
        return 1;
    }
    return 0;
}