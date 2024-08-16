/*!
    @file
    @brief Class for working with Telegram API
    @author Xeim
    @version 0.2
    @data 15.08.24

    Class that handles messages (also commands and edited messages)
 */

#ifndef ZOLA_API_HPP
#define ZOLA_API_HPP

#include <vector>
#include <string>
#include <format>
#include "Network/Url.hpp"
#include "Objects/InlineKeyboardMarkup.hpp"

namespace Zola {
    class API {
    public:
        using parameter = std::pair<std::string, std::string>;
        using parameters = std::vector<parameter>;

        explicit API(const std::string& token);
        API(const API&) = delete;
        API(API&&) = delete;
        API& operator=(const API&) = delete;
        API& operator=(API&&) = delete;

    public:
        std::string getUpdates(long offset=0);
        void sendMessage(const std::string& text,
                         long chat_id,
                         const std::optional<Objects::InlineKeyboardMarkup>& reply_markup = std::nullopt);
        void sendSticker(const std::string& sticker,
                         long chat_id);
        void sendVideo(const std::string& video,
                       long chat_id,
                       const std::optional<std::string>& caption = std::nullopt);
        void sendPhoto(const std::string& photo,
                       long chat_id,
                       const std::optional<std::string>& caption = std::nullopt);
        void sendVoice(const std::string& voice,
                       long chat_id,
                       const std::optional<std::string>& caption = std::nullopt);
        void sendDocument(const std::string& document,
                         long chat_id,
                         const std::optional<Objects::InlineKeyboardMarkup>& reply_markup = std::nullopt,
                         const std::optional<std::string>& business_connection_id = std::nullopt,
                         const std::optional<int>& message_thread_id = std::nullopt,
                         const std::optional<std::string>& thumbnail = std::nullopt,
                         const std::optional<std::string>& caption = std::nullopt,
                         const std::optional<std::string>& parse_mod = std::nullopt,
                         const std::optional<bool>& disable_content_type_detection= std::nullopt,
                         const std::optional<bool>& disable_notification = std::nullopt,
                         const std::optional<bool>& protect_content = std::nullopt,
                         const std::optional<std::string>& message_effect_id = std::nullopt);
        void answerCallbackQuery(const std::string& callback_query_id,
                                 const std::optional<std::string>& text = std::nullopt,
                                 const std::optional<bool>& show_alert = std::nullopt,
                                 const std::optional<std::string>& url = std::nullopt,
                                 const std::optional<int>& cache_time = std::nullopt);
        void editMessage(const std::string& text,
                         const std::optional<std::string>& chat_id = std::nullopt,
                         const std::optional<long>& message_id = std::nullopt,
                         const std::optional<Objects::InlineKeyboardMarkup>& reply_markup = std::nullopt,
                         const std::optional<std::string>& inline_message_id = std::nullopt,
                         const std::optional<std::string>& business_connection_id = std::nullopt,
                         const std::optional<std::string>& parse_mod = std::nullopt);
    private:
        static std::string correctParameter(const std::string& str);
        static std::string parseParameters(const parameters& params);

    private:
        const std::string tgUrl;
        Network::Url net;
    };
}

#endif //ZOLA_API_HPP
