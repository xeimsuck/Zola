#include "Zola/Bot.hpp"

//! Curl write function callback
size_t Zola::Bot::write_callback(char *ptr, size_t size, size_t nmemb, void *data) {
    auto user_data = reinterpret_cast<std::string*>(data);
    *user_data = ptr;
    return size*nmemb;
}

//! Bot initialization
Zola::Bot& Zola::Bot::init() {
    static Bot bot;
    return bot;
}

//! Private constructor
Zola::Bot::Bot() {
    curl_global_init(CURL_GLOBAL_ALL);
    curlHandle = curl_easy_init();
}

//! Public destructor
Zola::Bot::~Bot() {
    curl_easy_cleanup(curlHandle);
    curl_global_cleanup();
}

//! Return a bot token
const std::string &Zola::Bot::getToken() const {
    return token;
}

//! Run a bot using a bot token
void Zola::Bot::run(const std::string& _token) {
    // local variables setup
    token = _token;
    fullUrl = std::format("https://api.telegram.org/bot{}/getUpdates", _token);
    last_update_id = 0;
    std::string response;

    // curl setopt
    curl_easy_setopt(curlHandle, CURLOPT_URL, fullUrl.c_str());
    curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &response);

    while (true){
        std::cout << "getUpdates request\n";
        curl_easy_perform(curlHandle);
        std::cout << response << "\n";
        sleep(2);
    }
}