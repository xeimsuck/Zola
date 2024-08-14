#include <Zola/API.hpp>
#include <iostream>

using namespace Zola;

/*!
 * Constructor :D
 * @param token Bot token
 */
API::API(const std::string& token) : tgUrl(std::format("https://api.telegram.org/bot{}", token)) {
    curl_global_init(CURL_GLOBAL_ALL);
    handle = curl_easy_init();
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(handle, CURLOPT_WRITEDATA, &buffer);
}

/*!
 * Destructor :D
 */
API::~API() {
    curl_easy_cleanup(handle);
    curl_global_cleanup();
}

/*!
 * Curl write function callback
 * @param ptr content
 * @param size size of content
 * @param n idk
 * @param data buffer
 * @return count of writen bytes
 */
size_t API::writeCallback(char *ptr, size_t size, size_t n, void *data) {
    auto user_data = reinterpret_cast<std::string*>(data);
    user_data->clear();
    user_data->append(ptr, size*n);
    return size*n;
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

    curl_easy_setopt(handle, CURLOPT_URL, getUpdateURL.c_str());
    curl_easy_perform(handle);
    return buffer;
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

    curl_easy_setopt(handle, CURLOPT_URL, sendMessageURL.c_str());
    curl_easy_perform(handle);
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

    curl_easy_setopt(handle, CURLOPT_URL, sendStickerURL.c_str());
    curl_easy_perform(handle);
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

    curl_easy_setopt(handle, CURLOPT_URL, sendVideoURL.c_str());
    curl_easy_perform(handle);
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

    curl_easy_setopt(handle, CURLOPT_URL, sendPhotoURL.c_str());
    curl_easy_perform(handle);
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

    curl_easy_setopt(handle, CURLOPT_URL, sendPhotoURL.c_str());
    curl_easy_perform(handle);
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

    curl_easy_setopt(handle, CURLOPT_URL, answerCallbackQueryURL.c_str());
    curl_easy_perform(handle);
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
                      const std::optional<std::string> &message_id,
                      const std::optional<Objects::InlineKeyboardMarkup> &reply_markup,
                      const std::optional<std::string> &inline_message_id,
                      const std::optional<std::string> &business_connection_id,
                      const std::optional<std::string> &parse_mod) {
    parameters params;
    params.emplace_back("text", text);
    if(chat_id) params.emplace_back("chat_id", chat_id.value());
    if(message_id) params.emplace_back("message_id", message_id.value());
    if(reply_markup) params.emplace_back("reply_markup", to_string(reply_markup->toJson()));
    if(inline_message_id) params.emplace_back("inline_message_id", inline_message_id.value());
    if(business_connection_id) params.emplace_back("business_connection_id", business_connection_id.value());

    std::string editMessageUrl = tgUrl + "/answerCallbackQuery" + parseParameters(params);

    curl_easy_setopt(handle, CURLOPT_URL, editMessageUrl.c_str());
    curl_easy_perform(handle);
}