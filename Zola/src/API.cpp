#include <Zola/API.hpp>
#include <iostream>

using namespace Zola;

/*!
 * Constructor :D
 * @param token Bot token
 */
API::API(const std::string& token) : url(std::format("https://api.telegram.org/bot{}", token)) {
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
 * Return all updates with offset bigger than "offset"
 * @param offset offset
 * @return Json unparsed string
 */
std::string API::getUpdates(long offset) {
    parameters params;
    params.emplace_back("offset", std::to_string(offset));

    std::string getUpdateURL = url+"/getUpdates"+parseParameters(params);

    curl_easy_setopt(handle, CURLOPT_URL, getUpdateURL.c_str());
    curl_easy_perform(handle);
    return buffer;
}

/*!
 * Send text message to chat
 * @param text Text message
 * @param chat_id ID of chat
 */
void API::sendMessage(const std::string& text,
                      long chat_id,
                      const std::optional<Objects::InlineKeyboardMarkup>& reply_markup) {
    parameters params;
    params.emplace_back("text", text);
    params.emplace_back("chat_id", std::to_string(chat_id));
    if(reply_markup) params.emplace_back("reply_markup", to_string(reply_markup->toJson()));

    std::string sendMessageURL = url + "/sendMessage" + parseParameters(params);

    curl_easy_setopt(handle, CURLOPT_URL, sendMessageURL.c_str());
    curl_easy_perform(handle);
}

/*!
 * Send sticker to chat
 * @param sticker ID of sticker (file_id)
 * @param chat_id ID of chat
 */
void API::sendSticker(const std::string& sticker, long chat_id) {
    parameters params;
    params.emplace_back("sticker", sticker);
    params.emplace_back("chat_id", std::to_string(chat_id));

    std::string sendStickerURL = url + "/sendSticker" + parseParameters(params);

    curl_easy_setopt(handle, CURLOPT_URL, sendStickerURL.c_str());
    curl_easy_perform(handle);
}

/*!
 * Send video to chat
 * @param video file_id or http url
 * @param chat_id ID of chat
 * @param caption Video message caption
 * @param reply_markup
 */
void API::sendVideo(const std::string &video, long chat_id,
                    const std::optional<std::string>& caption) {
    parameters params;
    params.emplace_back("video", video);
    params.emplace_back("chat_id", std::to_string(chat_id));
    if(caption) params.emplace_back("caption", caption.value());

    std::string sendVideoURL = url + "/sendVideo" + parseParameters(params);

    curl_easy_setopt(handle, CURLOPT_URL, sendVideoURL.c_str());
    curl_easy_perform(handle);
}

/*!
 *  Send photo to chat
 * @param photo file_id or http url
 * @param chat_id ID of chat
 * @param caption Photo message caption
 */
void API::sendPhoto(const std::string &photo, long chat_id, const std::optional<std::string> &caption) {
    parameters params;
    params.emplace_back("photo", photo);
    params.emplace_back("chat_id", std::to_string(chat_id));
    if(caption) params.emplace_back("caption", caption.value());

    std::string sendPhotoURL = url + "/sendPhoto" + parseParameters(params);

    curl_easy_setopt(handle, CURLOPT_URL, sendPhotoURL.c_str());
    curl_easy_perform(handle);
}

/*!
 * Send voice to chat
 * @param voice file_id or http url
 * @param chat_id ID of chat
 * @param caption Voice message caption
 */
void API::sendVoice(const std::string &voice, long chat_id, const std::optional<std::string> &caption) {
    parameters params;
    params.emplace_back("voice", voice);
    params.emplace_back("chat_id", std::to_string(chat_id));
    if(caption) params.emplace_back("caption", caption.value());

    std::string sendPhotoURL = url + "/sendVoice" + parseParameters(params);

    curl_easy_setopt(handle, CURLOPT_URL, sendPhotoURL.c_str());
    curl_easy_perform(handle);
}