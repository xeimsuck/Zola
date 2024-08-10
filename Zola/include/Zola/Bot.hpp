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

#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>
#include <Zola/objects/Update.hpp>
#include <Zola/objects/Error.hpp>

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
        explicit Bot(std::string token);

    public:
        static Bot& init(std::string token);
        [[nodiscard]]const std::string& getToken() const;
        void run();
    private:
        nlohmann::json getUpdates(int offset=0);
        void updateHandler(const Objects::Update& update);
        void errorHandler(const Objects::Error& error);
        static size_t write_callback(char* ptr, size_t size, size_t n, void* data);

    private:
        const std::string token;
        std::string getUpdatesURL;
        std::string updateBuffer;
        CURL* curlHandle = nullptr;
    };
}

#endif //ZOLA_BOT_HPP
