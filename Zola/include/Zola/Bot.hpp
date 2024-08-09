/*!
    \file
    \brief Telegram Bot class
    \author Xeim
    \version 0.1
    \data 08.08.24
    \warning class is not completed

    This class is the key one in the entire library. Use it to create telegram bot.
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
        template<is_string T>
        explicit Bot(T&& token);
        [[nodiscard]]const std::string& getToken() const;
        void run();
    private:
        const std::string token;
        CURL* curlHandle = nullptr;
    };
}

#endif //ZOLA_BOT_HPP
