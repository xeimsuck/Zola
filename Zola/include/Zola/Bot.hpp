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

#include <nlohmann/json.hpp>

#include "EventHandler.hpp"
#include "API.hpp"

template<typename T>
concept is_string = std::convertible_to<T, std::string>;

namespace Zola {
    class Bot {
    public:
        ~Bot() = default;
        Bot(const Bot& bot) = delete;
        Bot(Bot&& bot) = delete;
        Bot& operator=(const Bot& r) = delete;
        Bot& operator=(Bot&& r) = delete;
    private:
        explicit Bot(std::string token);

    public:
        static Bot& init(std::string token);
        void run();
        [[nodiscard]] const std::string& getToken() const;
        [[nodiscard]] Zola::EventHandler& getEventHandler();
        [[nodiscard]] Zola::API& getAPI();

    private:
        const std::string token;
        EventHandler eventHandler;
        API api;
    };
}

#endif //ZOLA_BOT_HPP
