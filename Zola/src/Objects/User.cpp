#include <Zola/Objects/User.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

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
    if(data.contains("language_code")){
        language_code = data["language_code"];
    }
    if(data.contains("is_premium")){
        is_premium = data["is_premium"];
    }
    if(data.contains("added_to_attachment_menu")){
        added_to_attachment_menu = data["added_to_attachment_menu"];
    }
    if(data.contains("can_join_groups")){
        can_join_groups = data["can_join_groups"];
    }
    if(data.contains("can_read_all_group_messages")){
        can_read_all_group_messages = data["can_read_all_group_messages"];
    }
    if(data.contains("supports_inline_queries")){
        supports_inline_queries = data["supports_inline_queries"];
    }
    if(data.contains("can_connect_to_business")){
        can_connect_to_business = data["can_connect_to_business"];
    }
    if(data.contains("has_main_web_app")){
        has_main_web_app = data["has_main_web_app"];
    }
}

User::operator json() const {
    return toJson();
}

json User::toJson() const {
    json data;
    data["id"] = id;
    data["first_name"] = first_name;
    data["is_bot"] = is_bot;
    if(last_name) data["last_name"] = last_name.value();
    if(username) data["username"] = username.value();
    if(language_code) data["language_code"] = language_code.value();
    if(is_premium) data["is_premium"] = is_premium.value();
    if(added_to_attachment_menu) data["added_to_attachment_menu"] = added_to_attachment_menu.value();
    if(can_join_groups) data["can_join_groups"] = can_join_groups.value();
    if(can_read_all_group_messages) data["can_read_all_group_messages"] = can_read_all_group_messages.value();
    if(supports_inline_queries) data["supports_inline_queries"] = supports_inline_queries.value();
    if(can_connect_to_business) data["can_connect_to_business"] = can_connect_to_business.value();
    if(has_main_web_app) data["has_main_web_app"] = has_main_web_app.value();
    return data;
}

