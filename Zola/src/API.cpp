#include <Zola/API.hpp>

using namespace Zola;

/*!
 * Constructor :D
 * @param token Bot token
 */
API::API(const std::string& token) : url(std::format("https://api.telegram.org/bot{}", token)) {
    curl_global_init(CURL_GLOBAL_ALL);
    handle = curl_easy_init();
    curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_callback);
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
size_t API::write_callback(char *ptr, size_t size, size_t n, void *data) {
    auto user_data = reinterpret_cast<std::string*>(data);
    user_data->clear();
    user_data->append(ptr, size*n);
    return size*n;
}


/*!
 * Return all updates with offset bigger than "offset"
 * @param offset
 * @return json unparsed string
 */
std::string API::getUpdates(long offset) {
    std::string getUpdateURL = url + std::format("/getUpdates?offset={}", offset);
    curl_easy_setopt(handle, CURLOPT_URL, getUpdateURL.c_str());
    curl_easy_perform(handle);
    return buffer;
}

/*!
 * Send text message to chat
 * @param text Text message
 * @param chat_id ID of chat
 */
void API::sendMessage(const std::string &text, long chat_id) {
    std::string sendMessageURL = url + std::format("/sendMessage?text={}&chat_id={}", text, chat_id);
    curl_easy_setopt(handle, CURLOPT_URL, sendMessageURL.c_str());
    curl_easy_perform(handle);
}

/*!
 * Send sticker to chat
 * @param sticker ID of sticker (file_id)
 * @param chat_id ID of chat
 */
void API::sendSticker(const std::string& sticker, long chat_id) {
    std::string sendStickerURL = url + std::format("/sendSticker?sticker={}&chat_id={}", sticker, chat_id);
    curl_easy_setopt(handle, CURLOPT_URL, sendStickerURL.c_str());
    curl_easy_perform(handle);
}

/*!
 * Send video to chat
 * @param video file_id or http url
 * @param chat_id ID of chat
 */
void API::sendVideo(const std::string &video, long chat_id, const std::optional<std::string>& caption) {
    std::string sendVideoURL = url + std::format("/sendVideo?video={}&chat_id={}", video, chat_id);
    if(caption.has_value()) sendVideoURL+=std::format("&capture={}", caption.value());
    curl_easy_setopt(handle, CURLOPT_URL, sendVideoURL.c_str());
    curl_easy_perform(handle);
}

void API::sendPhoto(const std::string &photo, long chat_id, const std::optional<std::string> &caption) {
    std::string sendPhotoURL = url + std::format("/sendPhoto?photo={}&chat_id={}", photo, chat_id);
    if(caption.has_value()) sendPhotoURL+=std::format("&capture={}", caption.value());
    curl_easy_setopt(handle, CURLOPT_URL, sendPhotoURL.c_str());
    curl_easy_perform(handle);
}