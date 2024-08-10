#include "Zola/Bot.hpp"

//! Curl write function callback
size_t Zola::Bot::write_callback(char *ptr, size_t size, size_t n, void *data) {
    auto user_data = reinterpret_cast<std::string*>(data);
    user_data->clear();
    user_data->append(ptr, size*n);
    return size*n;
}

//! Bot initialization
Zola::Bot& Zola::Bot::init(std::string _token) {
    static Bot bot(std::move(_token));
    return bot;
}

//! Private constructor
Zola::Bot::Bot(std::string _token) : token(std::move(_token)) {
    getUpdatesURL = std::format("https://api.telegram.org/bot{}/getUpdates", token);

    curl_global_init(CURL_GLOBAL_ALL);
    curlHandle = curl_easy_init();
    curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &updateBuffer);
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
void Zola::Bot::run() {
    int updateOffset = 0;
    while (true){
        auto updates = getUpdates(updateOffset);
        if(!updates["ok"]){
            errorHandler(Objects::Error(updates["error_code"], updates["description"]));
        }
        std::for_each(updates["result"].begin(), updates["result"].end(), [&](const auto& parsed_update){
            Objects::Update update(parsed_update);
            updateOffset = update.update_id+1;
            updateHandler(update);
        });
        sleep(2);
    }
}

//! Return updates with offset
nlohmann::json Zola::Bot::getUpdates(int offset) {
    std::string fullURL = getUpdatesURL+"?offset="+std::to_string(offset);
    curl_easy_setopt(curlHandle, CURLOPT_URL, fullURL.c_str());

    curl_easy_perform(curlHandle);
    return nlohmann::json::parse(updateBuffer);
}

//! Update handler
void Zola::Bot::updateHandler(const Objects::Update& update) {
    std::cout << "update handler\n";
}

//! Error handler
void Zola::Bot::errorHandler(const Objects::Error& error) {
    throw std::runtime_error(error.description);
}