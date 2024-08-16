#include <Zola/Objects/BotDescription.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

BotDescription::BotDescription(const json &data) {
    description = data["description"];
}

BotDescription::operator json() const {
    return toJson();
}

json BotDescription::toJson() const {
    json data;
    data["description"] = description;
    return data;
}