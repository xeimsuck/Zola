#include <Zola/Objects/InlineKeyboardButton.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

InlineKeyboardButton::InlineKeyboardButton(const json& data) {
    text = data["text"];
    if(data.contains("url")){
        url = data["url"];
    }
    if(data.contains("callback_data")){
        callback_data = data["callback_data"];
    }
    if(data.contains("web_app")){
        web_app = WebAppInfo(data["web_app"]);
    }
    if(data.contains("login_url")){
        login_url = LoginUrl(data["login_url"]);
    }
    if(data.contains("switch_inline_query")){
        switch_inline_query = data["switch_inline_query"];
    }
    if(data.contains("switch_inline_query_current_chat")){
        switch_inline_query_current_chat = data["switch_inline_query_current_chat"];
    }
    if(data.contains("pay")){
        pay = data["pay"];
    }
}

InlineKeyboardButton::operator nlohmann::json() const {
    return toJson();
}

json InlineKeyboardButton::toJson() const{
    json unparsed;
    unparsed["text"] = text;
    if(callback_data) unparsed["callback_data"] = callback_data.value();
    if(web_app) unparsed["web_app"] = web_app.value().toJson();
    if(login_url) unparsed["login_url"] = login_url.value().toJson();
    if(switch_inline_query) unparsed["switch_inline_query"] = switch_inline_query.value();
    if(switch_inline_query_current_chat) unparsed["switch_inline_query_current_chat"] = switch_inline_query_current_chat.value();
    if(pay) unparsed["pay"] = pay.value();
    return unparsed;
}