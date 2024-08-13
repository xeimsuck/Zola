/*!
    \file
    \brief Class for working with Telegram API
    \author Xeim
    \version 0.1
    \data 12.08.24

    Class that handles messages (also commands and edited messages)
 */

#ifndef ZOLA_API_HPP
#define ZOLA_API_HPP

#include <vector>
#include <string>
#include <format>
#include <curl/curl.h>

namespace Zola {
    class API {
    public:
        using parameter = std::pair<std::string, std::string>;
        using parameters = std::vector<parameter>;

        explicit API(const std::string& token);
        ~API();
        API(const API& url) = delete;
        API(API&& url) = delete;
        API& operator=(const API& r) = delete;
        API& operator=(API&& r) = delete;

    public:
        std::string getUpdates(long offset=0);
        void sendMessage(const std::string& text, long chat_id);
        void sendSticker(const std::string& sticker, long chat_id);
        void sendVideo(const std::string& video, long chat_id, const std::optional<std::string>& caption);
        void sendPhoto(const std::string& photo, long chat_id, const std::optional<std::string>& caption);
        void sendVoice(const std::string& voice, long chat_id, const std::optional<std::string>& caption);
    private:
        static size_t write_callback(char* ptr, size_t size, size_t n, void* data);
        static std::string fillSpaces(const std::string& str);

    private:
        const std::string url;
        std::string buffer;
        CURL* handle = nullptr;
    };
}

#endif //ZOLA_API_HPP
