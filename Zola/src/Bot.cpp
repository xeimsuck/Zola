#include "Zola/detail/Bot.hpp"

//! Constructor using a bot token
template<is_string T>
Zola::Bot::Bot(T&& _token) : token(std::forward<T>(_token)){
}