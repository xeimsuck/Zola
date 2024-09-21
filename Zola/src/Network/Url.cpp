#include <iostream>
#include <ostream>
#include <Zola/Network/Url.hpp>

using namespace Zola;
using namespace Zola::Network;

bool Url::requestSent = false;

Url::Url() {
    curl_global_init(CURL_GLOBAL_ALL);
    handle = curl_easy_init();
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &buffer);
    curl_easy_setopt(handle, CURLOPT_BUFFERSIZE, CURL_MAX_READ_SIZE);
}

Url::~Url() {
    curl_easy_cleanup(handle);
    curl_global_cleanup();
}

std::string Url::sendRequest(const std::string &url) {
    requestSent = true;
    curl_easy_setopt(handle, CURLOPT_URL, url.c_str());
    curl_easy_perform(handle);
    return buffer;
}

size_t Url::writeCallback(const char *ptr, const size_t size, const size_t n, std::string *data) {
    if(requestSent) {
        data->clear();
    }
    *data += std::string(ptr, size*n);
    requestSent = false;
    return size*n;
}