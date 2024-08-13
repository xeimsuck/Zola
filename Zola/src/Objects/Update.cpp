#include <Zola/Objects/Update.hpp>

Zola::Objects::Update::Update(const nlohmann::json& data) {
    update_id = data["update_id"];
    if(data.contains("message")){
        message = Message(data["message"]);
    } else if(data.contains("edited_message")){
        edited_message = Message( data["edited_message"]);
    } else if(data.contains("channel_post")){
        channel_post = Message( data["channel_post"]);
    } else if(data.contains("edited_channel_post")){
        edited_channel_post = Message( data["edited_channel_post"]);
    } else if(data.contains("callback_query")){
        callback_query = CallbackQuery(data["callback_query"]);
    }
}