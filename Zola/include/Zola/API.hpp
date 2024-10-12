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
#include "Objects/BotName.hpp"
#include "Objects/BotDescription.hpp"
#include "Objects/ChatMember.hpp"
#include "Objects/Error.hpp"
#include "Objects/InputMedia.hpp"
#include "Objects/Message.hpp"

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
                         const std::optional<Objects::InlineKeyboardMarkup>& reply_markup = std::nullopt,
                         const std::optional<std::string>& parse_mode = std::nullopt,
                         const std::optional<bool>& disable_notification = std::nullopt,
                         const std::optional<bool>& protect_content = std::nullopt,
                         const std::optional<std::string>& message_effect_id = std::nullopt);
    	void sendMessage(const Objects::Message& msg);
        void sendSticker(const std::string& sticker,
                         long chat_id);
        void sendVideo(const std::string& video,
                       long chat_id,
                       const std::optional<std::string>& caption = std::nullopt,
                       const std::optional<Objects::InlineKeyboardMarkup>& reply_markup = std::nullopt);
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
        std::optional<Objects::Error> editMessageText(const std::string& text,
                         const std::optional<std::string>& chat_id = std::nullopt,
                         const std::optional<long>& message_id = std::nullopt,
                         const std::optional<Objects::InlineKeyboardMarkup>& reply_markup = std::nullopt,
                         const std::optional<std::string>& inline_message_id = std::nullopt,
                         const std::optional<std::string>& business_connection_id = std::nullopt,
                         const std::optional<std::string>& parse_mod = std::nullopt);
    	std::optional<Objects::Error> editMessageMedia(const Objects::InputMedia& media,
    					 const std::optional<std::string>& chat_id = std::nullopt,
						 const std::optional<long>& message_id = std::nullopt,
						 const std::optional<Objects::InlineKeyboardMarkup>& reply_markup = std::nullopt,
						 const std::optional<std::string>& inline_message_id = std::nullopt,
						 const std::optional<std::string>& business_connection_id = std::nullopt);

    	std::optional<Objects::Error> deleteMessage(long chat_id, long message_id);
    	std::optional<Objects::Error> deleteMessage(const std::string& chat_id, long message_id);
    	bool setMyName(const std::optional<std::string>& name = std::nullopt,
					   const std::optional<std::string>& language_code = std::nullopt);
    	bool setMyName(const Objects::BotName& botName,
					   const std::optional<std::string>& language_code = std::nullopt);
    	Objects::BotName getMyName(const std::optional<std::string>& language_code = std::nullopt);
    	bool setMyDescription(const std::optional<std::string>& description = std::nullopt,
					   const std::optional<std::string>& language_code = std::nullopt);
    	bool setMyDescription(const Objects::BotDescription& botDescription,
					   const std::optional<std::string>& language_code = std::nullopt);
    	Objects::BotDescription getMyDescription(const std::optional<std::string>& language_code = std::nullopt);
    	std::shared_ptr<Objects::ChatMember> getChatMember(long chat_id, long user_id);
    	std::shared_ptr<Objects::ChatMember> getChatMember(const std::string& chat_id, long user_id);
    	Objects::ChatMember::Status getChatMemberStatus(long chat_id, long user_id);
    	Objects::ChatMember::Status getChatMemberStatus(const std::string& chat_id, long user_id);
    private:
        static std::string correctParameter(const std::string& str);
        static std::string parseParameters(const parameters& params);

    private:
        const std::string tgUrl;
        Network::Url net;
    };
}

#endif //ZOLA_API_HPP
