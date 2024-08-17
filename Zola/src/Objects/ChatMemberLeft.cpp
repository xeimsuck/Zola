#include <Zola/Objects/ChatMemberLeft.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMemberLeft::ChatMemberLeft() {
	status = Status::left;
}

ChatMemberLeft::ChatMemberLeft(const json &data) {
	status = Status::left;
	user = User(data["user"]);
}

json ChatMemberLeft::toJson() const {
	json data;
	data["status"] = "left";
	data["user"] = user.toJson();
	return data;
}