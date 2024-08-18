#include <Zola/Objects/Message.hpp>

Zola::Objects::Message::Message(const nlohmann::json& data) {
    message_id = data["message_id"];
    date = data["date"];
    chat = Chat(data["chat"]);
    if(data.contains("text")){
        text = data["text"];
    }
    if(data.contains("sticker")){
        sticker = Sticker(data["sticker"]);
    } else if(data.contains("video")){
        video = Video(data["video"]);
    } else if(data.contains("voice")){
        voice = Voice(data["voice"]);
    } else if(data.contains("document")) {
        document = Document(data["document"]);
    }else if(data.contains("photo")){
        photo = std::make_optional<std::vector<PhotoSize>>();
        for(decltype(auto) photoSize : data["photo"]){
            photo->emplace_back(photoSize);
        }
    }
    if(data.contains("sender_chat")){
        sender_chat = Chat(data["sender_chat"]);
    }
    if(data.contains("caption")){
        caption = data["caption"];
    }
    if(data.contains("from")){
        from = User(data["from"]);
    }
    if(data.contains("web_app_data")){
        web_app_data = WebAppInfo(data["web_app_data"]);
    }
    if(data.contains("reply_markup")){
        if(data["reply_markup"].contains("inline_keyboard")){
            reply_markup = InlineKeyboardMarkup(data["reply_markup"]["inline_keyboard"]);
        }
    }
}