#include <Zola/Objects/User.hpp>

//! User object constructor
Zola::Objects::User::User(const nlohmann::json& data){
    id = data["id"];
    is_bot = data["is_bot"];
    first_name = data["first_name"];
    if(data.contains("username")){
        username = data["username"];
    }
    if(data.contains("last_name")){
        last_name = data["last_name"];
    }
}