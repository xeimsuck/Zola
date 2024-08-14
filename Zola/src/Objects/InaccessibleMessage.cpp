#include <Zola/Objects/InaccessibleMessage.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

InaccessibleMessage::InaccessibleMessage(const json &data) {
    chat = Chat(data["chat"]);
    message_id = data["message_id"];
    date = data["date"];
}

InaccessibleMessage::operator json() const {
    return toJson();
}

json InaccessibleMessage::toJson() const {
    json parsed;
    parsed["chat"] = chat.toJson();
    parsed["message_id"] = message_id;
    parsed["date"] = date;
    return parsed;
}