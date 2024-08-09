#include <iostream>
#include "Zola/Bot.hpp"

int main(int argc, char*argv[]){
    Zola::Bot bot("7270679735:AAGsHK_SG9wqAWX3AvsRhLF_24yG_ZYkn5E");
    try {
        bot.run();
    } catch (std::exception ex){
        std::cout << ex.what() << "\n";
        return 1;
    }
    return 0;
}