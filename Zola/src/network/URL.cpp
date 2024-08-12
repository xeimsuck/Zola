#include <Zola/network/URL.hpp>

//! Curl write function callback
size_t Zola::Network::URL::write_callback(char *ptr, size_t size, size_t n, void *data) {
    auto user_data = reinterpret_cast<std::string*>(data);
    user_data->clear();
    user_data->append(ptr, size*n);
    return size*n;
}

//! Initialization libcurl and attributes
Zola::Network::URL::URL(std::string _url) : url(std::move(_url)) {
    curl_global_init(CURL_GLOBAL_ALL);
    handle = curl_easy_init();
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &buffer);
}

//! Cleanup libcurl
Zola::Network::URL::~URL() {
    curl_easy_cleanup(handle);
    curl_global_cleanup();
}

//! Return current url
const std::string &Zola::Network::URL::getURL() const {
    return url;
}

//! Set new url
void Zola::Network::URL::setURL(std::string _url) {
    url = std::move(_url);
}

//! Make request
std::string Zola::Network::URL::makeRequest(parameters params) {
    std::string req = url + "?";
    for(decltype(auto) param : params){
        req += std::format("{}={}&", param.first, param.second);
    }
    curl_easy_setopt(handle, CURLOPT_URL, req.c_str());
    curl_easy_perform(handle);
    return buffer;
}