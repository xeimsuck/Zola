#include <Zola/Objects/ChatMemberOwner.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMemberOwner::ChatMemberOwner() {
	status = Status::creator;
}

ChatMemberOwner::ChatMemberOwner(const json& data) {
	status = Status::creator;
	user = User(data["user"]);
	is_anonymous = data["is_anonymous"];
	if(data.contains("custom_title")) custom_title = data["custom_title"];
}

json ChatMemberOwner::toJson() const {
	json data;
	data["status"] = "creator";
	data["user"] = user.toJson();
	data["is_anonymous"] = is_anonymous;
	if(custom_title) data["custom_title"] = custom_title.value();
	return data;
}
