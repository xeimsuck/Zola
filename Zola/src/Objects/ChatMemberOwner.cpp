#include <Zola/Objects/ChatMemberOwner.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMemberOwner::ChatMemberOwner() {
	status = OWNER_STATUS;
}

ChatMemberOwner::ChatMemberOwner(const json& data) {
	status = OWNER_STATUS;
	user = User(data["user"]);
	is_anonymous = data["is_anonymous"];
	if(data.contains("custom_title")) custom_title = data["custom_title"];
}

json ChatMemberOwner::toJson() const {
	json data;
	data["status"] = status;
	data["user"] = user.toJson();
	data["is_anonymous"] = is_anonymous;
	if(custom_title) data["custom_title"] = custom_title.value();
	return data;
}
