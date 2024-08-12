/*!
    \file
    \brief Class for working with network
    \author Xeim
    \version 0.1
    \data 12.08.24

    Class for making requests to the url with the libcurl
 */

#ifndef ZOLA_URL_HPP
#define ZOLA_URL_HPP

#include <string>
#include <vector>
#include <format>
#include <curl/curl.h>

namespace Zola::Network {
    class URL {
    public:
        using parameter = std::pair<std::string, std::string>;
        using parameters = std::vector<parameter>;

        explicit URL(std::string url);
        ~URL();
        URL(const URL& url) = delete;
        URL(URL&& url) = delete;
        URL& operator=(const URL& r) = delete;
        URL& operator=(URL&& r) = delete;

    public:
        std::string makeRequest(parameters params);
        [[nodiscard]]const std::string& getURL() const;
        void setURL (std::string url);
    private:
        static size_t write_callback(char* ptr, size_t size, size_t n, void* data);

    private:
        std::string url;
        std::string buffer;
        CURL* handle = nullptr;
    };
}

#endif //ZOLA_URL_HPP
