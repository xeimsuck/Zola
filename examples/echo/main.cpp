#include <iostream>
#include <Zola/Zola.hpp>

int main(int argc, char*argv[]){
    decltype(auto) bot = Zola::Bot::init();
    try {
        bot.run("7047048031:AAEbb5yTcq5Gd86ecYjnsUg2Qore3pgAAzg");
    } catch (const std::exception& ex){
        std::cout << ex.what() << "\n";
        return 1;
    }
    return 0;
}