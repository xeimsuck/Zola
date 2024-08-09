/*!
    \file
    \brief Telegram Bot class
    \author Xeim
    \version 0.1
    \data 08.08.24
    \warning class is not completed

    This singleton class. Use it to create telegram bot.
 */

#ifndef ZOLA_BOT_HPP
#define ZOLA_BOT_HPP

#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

template<typename T>
concept is_string = std::convertible_to<T, std::string>;

namespace Zola {
    class Bot {
    public:
        ~Bot();
        Bot(const Bot& bot) = delete;
        Bot(Bot&& bot) = delete;
        Bot& operator=(const Bot& r) = delete;
        Bot& operator=(Bot&& r) = delete;
    private:
        Bot();

    public:
        static Bot& init();
        [[nodiscard]]const std::string& getToken() const;
        template<is_string T>
        void run(T&& token);

    private:
        const std::string token;
    };
}

#endif //ZOLA_BOT_HPP
