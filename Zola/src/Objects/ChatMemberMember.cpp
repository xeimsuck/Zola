#include <Zola/Objects/ChatMemberMember.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMemberMember::ChatMemberMember() {
	status = MEMBER_STATUS;
}

ChatMemberMember::ChatMemberMember(const json &data) {
	status = MEMBER_STATUS;
	user = User(data["user"]);
	if(data.contains("until_date")) until_date = data["until_date"];
}

json ChatMemberMember::toJson() const {
	json data;
	data["status"] = status;
	data["user"] = user.toJson();
	if(until_date) data["until_date"] = until_date.value();
	return data;
}