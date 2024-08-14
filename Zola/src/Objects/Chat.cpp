#include <Zola/Objects/Chat.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

Chat::Chat(const json& data){
    id = data["id"];
    type = data["type"];
    if(data.contains("title")){
        title = data["title"];
    }
    if(data.contains("username")){
        username = data["username"];
    }
    if(data.contains("first_name")){
        first_name = data["first_name"];
    }
    if(data.contains("last_name")){
        last_name = data["last_name"];
    }
    if(data.contains("is_forum")){
        is_forum = data["is_forum"];
    }
}

Chat::operator nlohmann::json() const {
    return toJson();
}

nlohmann::json Chat::toJson() const {
    json parsed;
    parsed["id"] = id;
    parsed["type"] = type;
    if(title) parsed["title"] = title.value();
    if(username) parsed["username"] = username.value();
    if(first_name) parsed["first_name"] = first_name.value();
    if(last_name) parsed["last_name"] = last_name.value();
    if(is_forum) parsed["is_forum"] = is_forum.value();
    return parsed;
}