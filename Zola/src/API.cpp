#include <Zola/API.hpp>

//! Constructor
Zola::API::API(const std::string& token) : url(std::format("https://api.telegram.org/bot{}", token)) {
    curl_global_init(CURL_GLOBAL_ALL);
    handle = curl_easy_init();
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &buffer);
}

Zola::API::~API() {
    curl_easy_cleanup(handle);
    curl_global_cleanup();
}

//! Curl write function callback
size_t Zola::API::write_callback(char *ptr, size_t size, size_t n, void *data) {
    auto user_data = reinterpret_cast<std::string*>(data);
    user_data->clear();
    user_data->append(ptr, size*n);
    return size*n;
}

//! Return getUpdates method
std::string Zola::API::getUpdates(int offset) {
    std::string getUpdateURL = url + std::format("/getUpdates?offset={}", offset);
    curl_easy_setopt(handle, CURLOPT_URL, getUpdateURL.c_str());
    curl_easy_perform(handle);
    return buffer;
}