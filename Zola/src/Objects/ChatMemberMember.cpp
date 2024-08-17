#include <Zola/Objects/ChatMemberMember.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMemberMember::ChatMemberMember() {
	status = Status::member;
}

ChatMemberMember::ChatMemberMember(const json &data) {
	status = Status::member;
	user = User(data["user"]);
	if(data.contains("until_date")) until_date = data["until_date"];
}

json ChatMemberMember::toJson() const {
	json data;
	data["status"] = "member";
	data["user"] = user.toJson();
	if(until_date) data["until_date"] = until_date.value();
	return data;
}