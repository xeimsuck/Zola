/*!
    @file
    @brief Class for sending requests to the Internet.
    @author Xeim
    @version 0.2
    @data 15.08.24
 */

#ifndef ZOLA_NETWORK_URL_HPP
#define ZOLA_NETWORK_URL_HPP

#include <string>
#include <curl/curl.h>

namespace Zola::Network {
    class Url {
    public:
        /*!
         * @brief Constructor
         */
        Url();

        /*!
         * @brief Destructor
         */
        ~Url();

        /*!
         * @brief Send request for an url
         * @param Url Http-Url
         * @return Server response
         */
        std::string sendRequest(const std::string& url);
    private:
        /*!
         * Curl write function callback
         * @param ptr content
         * @param size size of content
         * @param n idk
         * @param data buffer
         * @return count of writen bytes
         */
        static size_t writeCallback(const char* ptr, size_t size, size_t n, std::string *data);

    private:
        std::string buffer;
        CURL* handle = nullptr;
        static bool requestSent;
    };
}

#endif //ZOLA_NETWORK_URL_HPP
