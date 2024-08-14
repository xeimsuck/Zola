#include <Zola/Objects/LoginUrl.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

LoginUrl::LoginUrl(const json& data) {
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

LoginUrl::operator nlohmann::json() const {
    return toJson();
}

json LoginUrl::toJson() const {
    json parsed;
    parsed["url"] = url;
    if(forward_text) parsed["forward_text"] = forward_text.value();
    if(bot_username) parsed["bot_username"] = bot_username.value();
    if(request_write_access) parsed["request_write_access"] = request_write_access.value();
    return parsed;
}