#include <Zola/Objects/ChatMemberBanned.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMemberBanned::ChatMemberBanned() {
	status = Status::kicked;
}

ChatMemberBanned::ChatMemberBanned(const json &data) {
	status = Status::kicked;
	user = User(data["user"]);
	until_date = data["until_date"];
}

json ChatMemberBanned::toJson() const {
	json data;
	data["status"] = "kicked";
	data["user"] = user.toJson();
	data["until_date"] = until_date;
	return data;
}


