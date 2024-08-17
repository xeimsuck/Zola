#include <Zola/Objects/ChatMemberLeft.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMemberLeft::ChatMemberLeft() {
	status = LEFT_STATUS;
}

ChatMemberLeft::ChatMemberLeft(const json &data) {
	status = LEFT_STATUS;
	user = User(data["user"]);
}

json ChatMemberLeft::toJson() const {
	json data;
	data["status"] = status;
	data["user"] = user.toJson();
	return data;
}