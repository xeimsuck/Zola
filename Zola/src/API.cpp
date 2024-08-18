#include <iostream>
#include <magic_enum.hpp>
#include <Zola/API.hpp>
#include <Zola/Objects/ChatMemberAdministrator.hpp>
#include <Zola/Objects/ChatMemberBanned.hpp>
#include <Zola/Objects/ChatMemberError.hpp>
#include <Zola/Objects/ChatMemberLeft.hpp>
#include <Zola/Objects/ChatMemberMember.hpp>
#include <Zola/Objects/ChatMemberOwner.hpp>
#include <Zola/Objects/ChatMemberRestricted.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;
using namespace magic_enum;
using std::optional, std::nullopt;

/*!
 * Constructor :D
 * @param token Bot token
 */
API::API(const std::string& token) : tgUrl(std::format("https://api.telegram.org/bot{}", token)) {
}

/*!
 * Set %20 instead of spaces
 * @param str
 * @return result
 */
std::string API::correctParameter(const std::string &str) {
    std::string result;
    for(auto c : str){
        if(c==' ') result += "%20";
        else if(c=='&') result += "%26";
    	else if(c=='\n') result += "%0A";
    	else if(c=='\r') result+= "%0D";
        else result.push_back(c);
    }
    return result;
}

/*!
 * Parse parameters into string
 * @param params Parameters
 * @return Parsed parameters
 */
std::string API::parseParameters(const Zola::API::parameters& params) {
    std::string result="?";
    for(decltype(auto) param : params){
        result+=std::format("{}={}&", param.first, correctParameter(param.second));
    }
    return result;
}


/*!
 * @brief Use this method to receive incoming updates.
 * @param offset Identifier of the first update to be returned.
 * @return An array of Update objects.
 */
std::string API::getUpdates(long offset) {
    parameters params;
    params.emplace_back("offset", std::to_string(offset));

    std::string getUpdateURL = tgUrl + "/getUpdates" + parseParameters(params);

    return net.sendRequest(getUpdateURL);
}

/*!
 * @brief Use this method to send text messages.
 * @param text Text of the message to be sent, 1-4096 characters after entities parsing.
 * @param chat_id Unique identifier for the target chat or username of the target channel.
 *
 * On success, the sent Message is returned
 */
void API::sendMessage(const std::string& text,
                      long chat_id,
                      const std::optional<Objects::InlineKeyboardMarkup>& reply_markup) {
    parameters params;
    params.emplace_back("text", text);
    params.emplace_back("chat_id", std::to_string(chat_id));
    if(reply_markup) params.emplace_back("reply_markup", to_string(reply_markup->toJson()));

    std::string sendMessageURL = tgUrl + "/sendMessage" + parseParameters(params);

    net.sendRequest(sendMessageURL);
}

/*!
 * @brief Use this method to send static .WEBP, animated .TGS, or video .WEBM stickers.
 * @param sticker Sticker to send. Pass a file_id or a http url
 * @param chat_id Unique identifier for the target chat or username of the target channel.
 *
 * On success, the sent Message is returned.
 */
void API::sendSticker(const std::string& sticker, long chat_id) {
    parameters params;
    params.emplace_back("sticker", sticker);
    params.emplace_back("chat_id", std::to_string(chat_id));

    std::string sendStickerURL = tgUrl + "/sendSticker" + parseParameters(params);

    net.sendRequest(sendStickerURL);
}

/*!
 * @brief Use this method to send video files
 * @param video file_id or http url
 * @param chat_id ID of chat
 * @param caption Video message caption
 * @param reply_markup
 *
 * Telegram clients support MPEG4 videos (other
 * formats may be sent as Document). On success,
 * the sent Message is returned. Bots can currently
 * send video files of up to 50 MB in size, this
 * limit may be changed in
 */
void API::sendVideo(const std::string &video, long chat_id,
                    const std::optional<std::string>& caption) {
    parameters params;
    params.emplace_back("video", video);
    params.emplace_back("chat_id", std::to_string(chat_id));
    if(caption) params.emplace_back("caption", caption.value());

    std::string sendVideoURL = tgUrl + "/sendVideo" + parseParameters(params);

    net.sendRequest(sendVideoURL);
}

/*!
 * @brief Use this method to send photos
 * @param photo file_id or http url
 * @param chat_id ID of chat
 * @param caption Photo message caption
 *
 * On success, the sent Message is returned.
 */
void API::sendPhoto(const std::string &photo, long chat_id, const std::optional<std::string> &caption) {
    parameters params;
    params.emplace_back("photo", photo);
    params.emplace_back("chat_id", std::to_string(chat_id));
    if(caption) params.emplace_back("caption", caption.value());

    std::string sendPhotoURL = tgUrl + "/sendPhoto" + parseParameters(params);

    net.sendRequest(sendPhotoURL);
}

/*!
 * @brief Use this method to send audio files, if you want Telegram
 * clients to display the file as a playable voice message.
 * @param voice file_id or http url
 * @param chat_id ID of chat
 * @param caption Voice message caption
 *
 * For this to work, your audio must be in an .OGG file encoded
 * with OPUS, or in .MP3 format, or in .M4A format (other formats
 * may be sent as Audio or Document). On success, the sent Message
 * is returned. Bots can currently send voice messages of up to 50
 * MB in size, this limit may be changed in the future.
 */
void API::sendVoice(const std::string &voice, long chat_id, const std::optional<std::string> &caption) {
    parameters params;
    params.emplace_back("voice", voice);
    params.emplace_back("chat_id", std::to_string(chat_id));
    if(caption) params.emplace_back("caption", caption.value());

    std::string sendPhotoURL = tgUrl + "/sendVoice" + parseParameters(params);

    net.sendRequest(sendPhotoURL);
}


/*!
 * @brief Use this method to send general files.
 * @param document File to send. Pass a file_id or http url.
 * @param chat_id Unique identifier for the target chat
 * or username of the target channel.
 * @param business_connection_id Unique identifier of the business
 * connection on behalf of which the message will be sent.
 * @param message_thread_id Unique identifier for the target
 * message thread (topic) of the forum.
 * @param thumbnail Thumbnail of the file sent.
 * @param caption Document caption.
 * @param parse_mod Mode for parsing entities in the document caption.
 * @param disable_content_type_detection Disables automatic server-side
 * content type detection for files uploaded using multipart/form-data.
 * @param disable_notification Sends the message silently. Users will
 * receive a notification with no sound.
 * @param protect_content Protects the contents of the sent message
 * from forwarding and saving.
 * @param message_effect_id Unique identifier of the message effect
 * to be added to the message; for private chats only.
 * @param reply_markup Additional interface options (so far only InlineKeyboardMarkup).
 * @warning Has not caption_entities and reply_parameters parameters.
 *
 * On success, the sent Message is returned. Bots can
 * currently send files of any type of up to 50 MB in size,
 * this limit may be changed in the future.
 */
void API::sendDocument(const std::string &document,
						const long chat_id,
						const std::optional<Objects::InlineKeyboardMarkup> &reply_markup,
						const std::optional<std::string>&business_connection_id,
						const std::optional<int> &message_thread_id,
						const std::optional<std::string> &thumbnail,
						const std::optional<std::string> &caption,
						const std::optional<std::string> &parse_mod,
						const std::optional<bool> &disable_content_type_detection,
						const std::optional<bool> &disable_notification,
						const std::optional<bool> &protect_content,
						const std::optional<std::string> &message_effect_id) {
	parameters params;
	params.emplace_back("document", document);
	params.emplace_back("chat_id", std::to_string(chat_id));
	if(reply_markup) params.emplace_back("reply_markup", nlohmann::to_string(reply_markup->toJson()));
	if(business_connection_id) params.emplace_back("business_connection_id", business_connection_id.value());
	if(message_thread_id) params.emplace_back("message_thread_id", std::to_string(message_thread_id.value()));
	if(thumbnail) params.emplace_back("thumbnail", thumbnail.value());
	if(caption) params.emplace_back("caption", caption.value());
	if(parse_mod) params.emplace_back("parse_mod", parse_mod.value());
	if(disable_content_type_detection) params.emplace_back("disable_content_type_detection", disable_content_type_detection ? "true":"false");
	if(disable_notification) params.emplace_back("disable_notification", disable_notification?"true":"false");
	if(protect_content) params.emplace_back("protect_content", protect_content?"true":"false");
	if(message_effect_id) params.emplace_back("message_effect_id", message_effect_id.value());

	const std::string sendDocumentUrl = tgUrl + "/sendDocument" + parseParameters(params);

	net.sendRequest(sendDocumentUrl);
}


/*!
 * @brief Use this method to send answers to callback queries sent from inline keyboards.
 * @param callback_query_id Unique identifier for the query to be answered.
 * @param text Text of the notification.
 * @param show_alert If True, an alert will be shown by the client instead of a notification.
 * @param url URL that will be opened by the user's client.
 * @param cache_time The maximum amount of time in seconds that the result of the
 * callback query may be cached client-side
 *
 * The answer will be displayed to the user as a notification
 * at the top of the chat screen or as an alert. On success, True is returned.
 */
void API::answerCallbackQuery(const std::string &callback_query_id, const std::optional<std::string> &text,
                              const std::optional<bool> &show_alert, const std::optional<std::string> &url,
                              const std::optional<int> &cache_time) {
    parameters params;
    params.emplace_back("callback_query_id", callback_query_id);
    if(text) params.emplace_back("text", text.value());
    if(show_alert) params.emplace_back("show_alert", show_alert.value()?"true":"false");
    if(url) params.emplace_back("url", url.value());
    if(cache_time) params.emplace_back("cache_time", std::to_string(cache_time.value()));

    std::string answerCallbackQueryURL = tgUrl + "/answerCallbackQuery" + parseParameters(params);

    net.sendRequest(answerCallbackQueryURL);
}

/*!
 * @brief Use this method to edit text and game messages.
 * @param text New text of the message, 1-4096 characters after entities parsing
 * @param chat_id Required if inline_message_id is not specified.
 * Unique identifier for the target chat or username of the target channel.
 * @param message_id Required if inline_message_id is not specified.
 * Identifier of the message to edit
 * @param reply_markup Inline keyboard
 * @param inline_message_id Required if chat_id and message_id are
 * not specified. Identifier of the inline message
 * @param business_connection_id Unique identifier of the business
 * connection on behalf of which the message to be edited was sent
 * @param parse_mod Mode for parsing entities in the message text.
 * @warning has not "entities" and "link_preview_options" arguments
 *
 * On success, if the edited message is not an inline message,
 * the edited Message is returned, otherwise True is returned.
 * Note that business messages that were not sent by the bot and do
 * not contain an inline keyboard can only be edited within 48 hours
 * from the time they were sent.
 */
void API::editMessage(const std::string &text, const std::optional<std::string> &chat_id,
                      const std::optional<long> &message_id,
                      const std::optional<Objects::InlineKeyboardMarkup> &reply_markup,
                      const std::optional<std::string> &inline_message_id,
                      const std::optional<std::string> &business_connection_id,
                      const std::optional<std::string> &parse_mod) {
    parameters params;
    params.emplace_back("text", text);
    if(chat_id) params.emplace_back("chat_id", chat_id.value());
    if(message_id) params.emplace_back("message_id", std::to_string(message_id.value()));
    if(reply_markup) params.emplace_back("reply_markup", to_string(reply_markup->toJson()));
    if(inline_message_id) params.emplace_back("inline_message_id", inline_message_id.value());
    if(business_connection_id) params.emplace_back("business_connection_id", business_connection_id.value());

    std::string editMessageUrl = tgUrl + "/editMessage" + parseParameters(params);

    net.sendRequest(editMessageUrl);
}


/*!
 * @brief Use this method to change the bot's name. Returns True on success.
 * @param name New bot name; 0-64 characters. Pass an
 * empty string to remove the dedicated name for the given language.
 * @param language_code A two-letter ISO 639-1 language code. If empty,
 * the name will be shown to all users for whose language there is no dedicated name.
 * @return True on success
 */
bool API::setMyName(const std::optional<std::string> &name,
					const std::optional<std::string>& language_code) {
	parameters params;
	if(name) params.emplace_back("name", name.value());
	if(language_code) params.emplace_back("language_code", language_code.value());

	const std::string setMyNameUrl = tgUrl + "/setMyName" + parseParameters(params);

	return json::parse(net.sendRequest(setMyNameUrl))["ok"];
}


/*!
 * @brief Use this method to change the bot's name. Returns True on success.
 * @param botName New bot name.
 * @param language_code A two-letter ISO 639-1 language code. If empty,
 * the name will be shown to all users for whose language there is no dedicated name.
 * @return True on success
 */
bool API::setMyName(const Objects::BotName &botName,
					const std::optional<std::string>& language_code) {
	parameters params;
	params.emplace_back("name", botName.name);
	if(language_code) params.emplace_back("language_code", language_code.value());

	const std::string setMyNameUrl = tgUrl + "/setMyName" + parseParameters(params);

	return json::parse(net.sendRequest(setMyNameUrl))["ok"];
}


/*!
 * @brief Use this method to get the current bot name for the given user language.
 * @param language_code A two-letter ISO 639-1 language code or an empty string.
 * @return BotName with default constructor in failure case.
 */
BotName API::getMyName(const std::optional<std::string>& language_code) {
	parameters params;
	if(language_code)params.emplace_back("language_code", language_code.value());

	const std::string getMyNameUrl = tgUrl + "/getMyName" + parseParameters(params);

	auto data = json::parse(net.sendRequest(getMyNameUrl));
	return data["ok"] ? BotName(data["result"]) : BotName();
}


/*!
 * @brief Use this method to change the bot's description, which is shown in the chat with the bot if the chat is empty.
 * @param description New bot description; 0-512 characters.
 * Pass an empty string to remove the dedicated description for the given language.
 * @param language_code A two-letter ISO 639-1 language code.
 * If empty, the description will be applied to all users for whose language there is no dedicated description.
 * @return True on success
 */
bool API::setMyDescription(const std::optional<std::string> &description,
							const std::optional<std::string> &language_code) {
	parameters params;
	if(description) params.emplace_back("description", description.value());
	if(language_code) params.emplace_back("language_code", language_code.value());

	const std::string setMyDescriptionUrl = tgUrl + "/setMyDescription" + parseParameters(params);

	return json::parse(net.sendRequest(setMyDescriptionUrl))["ok"];
}


/*!
 * @brief Use this method to change the bot's description, which is shown in the chat with the bot if the chat is empty.
 * @param botDescription New bot description.
 * @param language_code A two-letter ISO 639-1 language code.
 * If empty, the description will be applied to all users for whose language there is no dedicated description.
 * @return True on success
 */
bool API::setMyDescription(const BotDescription &botDescription,
						   const std::optional<std::string> &language_code) {
	parameters params;
	params.emplace_back("description", botDescription.description);
	if(language_code) params.emplace_back("language_code", language_code.value());

	const std::string setMyDescriptionUrl = tgUrl + "/setMyDescription" + parseParameters(params);

	return json::parse(net.sendRequest(setMyDescriptionUrl))["ok"];
}


/*!
 * @brief Use this method to get the current bot description for the given user language.
 * @param language_code A two-letter ISO 639-1 language code or an empty string.
 * @return BotDescription with default constructor in failure case.
 */
BotDescription API::getMyDescription(const std::optional<std::string> &language_code) {
	parameters params;
	if(language_code) params.emplace_back("language_code", language_code.value());

	const std::string getMyDescriptionUrl = tgUrl + "/getMyDescription" + parseParameters(params);

	auto data = json::parse(net.sendRequest(getMyDescriptionUrl));
	return data["ok"] ? BotDescription(data["result"]) : BotDescription();
}

/*!
 * @brief Use this method to get information about a member of a chat.
 * @param chat_id 	Unique identifier for the target chat.
 * @param user_id 	Unique identifier of the target user.
 * @return A correct ChatMember object on success otherwise ChatMemberError.
 *
 *  The method is only guaranteed to work for other users if the
 *  bot is an administrator in the chat.
 */
std::shared_ptr<ChatMember> API::getChatMember(const long chat_id, const long user_id) {
	return getChatMember(std::to_string(chat_id), user_id);
}

/*!
 * @brief Use this method to get information about a member of a chat.
 * @param chat_id Username of the target supergroup or channel.
 * @param user_id Unique identifier of the target user.
 * @return A correct ChatMember object on success otherwise ChatMemberError.
 *
 * The method is only guaranteed to work for other users if the
 * bot is an administrator in the chat.
 */
std::shared_ptr<ChatMember> API::getChatMember(const std::string& chat_id, const long user_id) {
	parameters params;
	params.emplace_back("chat_id", chat_id);
	params.emplace_back("user_id", std::to_string(user_id));

	const std::string getChatMemberUrl = tgUrl + "/getChatMember" + parseParameters(params);

	auto data = json::parse(net.sendRequest(getChatMemberUrl));
	if(!data["ok"]) return std::make_shared<ChatMemberError>(data["error_code"], data["description"]);
	const std::string status = data["result"]["status"];

	if(status=="creator") return std::make_shared<ChatMemberOwner>(data["result"]);
	if(status=="administrator") return std::make_shared<ChatMemberAdministrator>(data["result"]);
	if(status=="member") return std::make_shared<ChatMemberMember>(data["result"]);
	if(status=="restricted") return std::make_shared<ChatMemberRestricted>(data["result"]);
	if(status=="left") return std::make_shared<ChatMemberLeft>(data["result"]);
	if(status=="kicked") return std::make_shared<ChatMemberBanned>(data["result"]);
	return std::make_shared<ChatMemberError>();
}

/*!
 * @brief Use this method to get status of member in chat.
 * @warning Not TelegramAPI method
 * @param chat_id Unique identifier for the target chat.
 * @param user_id Unique identifier of the target user.
 * @return Status of member in this chat.
 */
ChatMember::Status API::getChatMemberStatus(const long chat_id, const long user_id) {
	return getChatMemberStatus(std::to_string(chat_id), user_id);
}

/*!
 * @brief Use this method to get status of member in chat.
 * @warning Not TelegramAPI method
 * @param chat_id Username of the target supergroup or channel.
 * @param user_id Unique identifier of the target user.
 * @return Status of member in this chat.
 */
ChatMember::Status API::getChatMemberStatus(const std::string &chat_id, const long user_id) {
	parameters params;
	params.emplace_back("chat_id", chat_id);
	params.emplace_back("user_id", std::to_string(user_id));

	const std::string getChatMemberUrl = tgUrl + "/getChatMember" + parseParameters(params);
	auto data = json::parse(net.sendRequest(getChatMemberUrl));

	if(!data["ok"]) return ChatMember::Status::error;
	return enum_cast<ChatMember::Status>((std::string)data["result"]["status"]).value_or(ChatMember::Status::error);
}

/*!
 * @brief Use this method to delete a message.
 * @param chat_id Unique identifier for the target chat.
 * @param message_id Identifier of the message to delete.
 * @return Return Error object on failure.
 */
optional<Error> API::deleteMessage(const long chat_id, const long message_id) {
	return deleteMessage(std::to_string(chat_id), message_id);
}

/*!
 * @brief Use this method to delete a message.
 * @param chat_id Username of the target channel.
 * @param message_id Identifier of the message to delete.
 * @return Return Error object on failure.
 */
optional<Error> API::deleteMessage(const std::string &chat_id, long message_id) {
	parameters params;
	params.emplace_back("chat_id", chat_id);
	params.emplace_back("message_id", std::to_string(message_id));

	const std::string deleteMessageUrl = tgUrl + "/deleteMessage" + parseParameters(params);
	auto data = json::parse(net.sendRequest(deleteMessageUrl));

	optional<Error> error = nullopt;
	if(!data["ok"]) {
		error = Error{.error_code = data["error_code"], .description = data["description"]};
	}
	return error;
}


