#include <Zola/Objects/InlineKeyboardMarkup.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

InlineKeyboardMarkup::InlineKeyboardMarkup(const json &data) {
    for(decltype(auto) row : data){
        inline_keyboard.emplace_back();
        for(decltype(auto) button : row){
            inline_keyboard.back().emplace_back(button);
        }
    }
}

InlineKeyboardMarkup::operator nlohmann::json() const {
    return toJson();
}

json InlineKeyboardMarkup::toJson() const {
    json parsed;
    for(decltype(auto) row : inline_keyboard){
        parsed["inline_keyboard"].emplace_back();
        for(decltype(auto) button : row){
            parsed["inline_keyboard"].back().push_back(button.toJson());
        }
    }
    return parsed;
}