#include <Zola/Objects/Sticker.hpp>

Zola::Objects::Sticker::Sticker(const nlohmann::json &data) {
    width = data["width"];
    height = data["height"];
    is_animated = data["is_animated"];
    is_video = data["is_video"];
    file_id = data["file_id"];
    file_unique_id = data["file_unique_id"];
    if(data["type"]=="regular"){
        type = Type::regular;
    } else if(data["type"]=="mask"){
        type = Type::mask;
    } else {
        type = Type::custom_emoji;
    }
    if(data.contains("emoji")){
        emoji = data["emoji"];
    }
    if(data.contains("set_name")){
        set_name = data["set_name"];
    }
    if(data.contains("file_size")){
        file_size = data["file_size"];
    }
}