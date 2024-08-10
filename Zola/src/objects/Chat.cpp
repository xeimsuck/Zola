#include <Zola/objects/Chat.hpp>

Zola::Objects::Chat::Chat(const nlohmann::json& data){
    id = data["id"];
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
    if(data.contains("all_members_are_administrators")){
        all_members_are_administrators = data["all_members_are_administrators"];
    }
}