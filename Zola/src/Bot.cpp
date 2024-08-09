#include "Zola/Bot.hpp"

//! Bot initialization
Zola::Bot& Zola::Bot::init() {
    static Bot bot;
    return bot;
}

//! Private constructor
Zola::Bot::Bot() {
    curl_global_init(CURL_GLOBAL_ALL);
}

//! Public destructor
Zola::Bot::~Bot() {
    curl_global_cleanup();
}

//! Return a bot token
const std::string &Zola::Bot::getToken() const {
    return token;
}

//! Run a bot using a bot token
template<is_string T>
void Zola::Bot::run(T&& _token) {
    token = std::forward<T>(_token);
}