#include <Zola/Objects/BotName.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

BotName::BotName(const json &data) {
	name = data["name"];
}

BotName::operator json() const {
	return toJson();
}

json BotName::toJson() const {
	json data;
	data["name"] = name;
	return data;
}