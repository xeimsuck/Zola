#include <Zola/Objects/ChatMember.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMember::operator json() const {
	return toJson();
}

json ChatMember::toJson() const {
	json data;
	data["status"] = status;
	data["user"] = user.toJson();
	return data;
}
