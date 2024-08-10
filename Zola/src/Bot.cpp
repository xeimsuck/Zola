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
    std::string data;
    int last_update_id = 0;

    // curl setopt
    curl_easy_setopt(curlHandle, CURLOPT_URL, fullUrl.c_str());
    curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &data);

    while (true){
        curl_easy_perform(curlHandle);
        nlohmann::json updates = nlohmann::json::parse(data);
        if(!updates["ok"]){
            Objects::Error error(updates["error_code"], updates["description"]);
            errorHandler(error);
        }
        std::for_each(updates["result"].begin(), updates["result"].end(), [&](const auto& parsed_update){
            Objects::Update update(parsed_update);
            last_update_id = update.update_id;
            updateHandler(update);
        });
        sleep(2);
    }
}

//! Update handler
void Zola::Bot::updateHandler(const Objects::Update& update) {
    std::cout << "update handler\n";
}

//! Error handler
void Zola::Bot::errorHandler(const Objects::Error& error) {
    std::cout << std::format("ERROR ({}): {}\n", error.error_code, error.description);
    throw std::runtime_error(error.description);
}