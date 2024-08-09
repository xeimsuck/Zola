#include "Zola/Bot.hpp"

//! Constructor using a bot token
template<is_string T>
Zola::Bot::Bot(T&& _token) : token(std::forward<T>(_token)){
}

//! Return a bot token
const std::string &Zola::Bot::getToken() const {
    return token;
}

//! Run a bot
void Zola::Bot::run() {
    curl_global_init(CURL_GLOBAL_ALL);
    curlHandle = curl_easy_init();
    
}