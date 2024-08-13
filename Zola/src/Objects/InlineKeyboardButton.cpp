#include <Zola/Objects/InlineKeyboardButton.hpp>

using namespace Zola;

Objects::InlineKeyboardButton::InlineKeyboardButton(const nlohmann::json &data) {
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