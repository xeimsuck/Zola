#include <Zola/Network/Url.hpp>

using namespace Zola;
using namespace Zola::Network;

Url::Url() {
    curl_global_init(CURL_GLOBAL_ALL);
    handle = curl_easy_init();
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &buffer);
}

Url::~Url() {
    curl_easy_cleanup(handle);
    curl_global_cleanup();
}

std::string Url::sendRequest(const std::string &url) {
    curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
    curl_easy_perform(handle);
    return buffer;
}

size_t Url::writeCallback(char *ptr, size_t size, size_t n, void *data) {
    auto user_data = reinterpret_cast<std::string*>(data);
    user_data->clear();
    user_data->append(ptr, size*n);
    return size*n;
}