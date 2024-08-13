#include <Zola/Objects/InlineKeyboardMarkup.hpp>

using namespace Zola;

Objects::InlineKeyboardMarkup::InlineKeyboardMarkup(const nlohmann::json &data) {
    for(decltype(auto) row : data){
        inline_keyboard.push_back(std::vector<InlineKeyboardButton>());
        for(decltype(auto) button : row){
            inline_keyboard.back().emplace_back(button);
        }
    }
}