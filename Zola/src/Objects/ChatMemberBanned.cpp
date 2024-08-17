#include <Zola/Objects/ChatMemberBanned.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMemberBanned::ChatMemberBanned() {
	status = BANNED_STATUS;
}

ChatMemberBanned::ChatMemberBanned(const json &data) {
	status = BANNED_STATUS;
	user = User(data["user"]);
	until_date = data["until_date"];
}

json ChatMemberBanned::toJson() const {
	json data;
	data["status"] = status;
	data["user"] = user.toJson();
	data["until_date"] = until_date;
	return data;
}


