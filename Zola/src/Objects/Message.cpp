#include <Zola/Objects/Message.hpp>

Zola::Objects::Message::Message(const nlohmann::json& data) : chat(data["chat"]) {
    message_id = data["message_id"];
    date = data["date"];
    if(data.contains("text")){
        text = data["text"];
    }
    if(data.contains("from")){
        from = User(data["from"]);
    }
    if(data.contains("forward_from")){
        forward_from = User(data["forward_from"]);
    }
    if(data.contains("forward_date")){
        forward_date = data["forward_date"];
    }
}