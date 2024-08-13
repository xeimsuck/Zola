#include <Zola/Objects/LoginUrl.hpp>

using namespace Zola;

Objects::LoginUrl::LoginUrl(const nlohmann::json &data) {
    url = data["url"];
    if(data.contains("forward_text")){
        forward_text = data["forward_text"];
    }
    if(data.contains("bot_username")){
        bot_username = data["bot_username"];
    }
    if(data.contains("")){
        request_write_access = data["request_write_access"];
    }
}