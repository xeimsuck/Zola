#include <Zola/Objects/CallbackQuery.hpp>

using namespace Zola;

Objects::CallbackQuery::CallbackQuery(const nlohmann::json &data) {
    id = data["id"];
    from = User(data["from"]);
    chat_instance = data["chat_instance"];
    if(data.contains("inline_message_id")){
        inline_message_id = data["inline_message_id"];
    }
    if(data.contains("data")){
        data = data["data"];
    }
    if(data.contains("game_short_name")){
        game_short_name = data["game_short_name"];
    }
}