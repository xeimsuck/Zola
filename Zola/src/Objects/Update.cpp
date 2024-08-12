#include <Zola/Objects/Update.hpp>

//! Update object constructor
Zola::Objects::Update::Update(const nlohmann::json& data) {
    update_id = data["update_id"];
    if(data.contains("message")){
        message = Message(data["message"]);
    }
}