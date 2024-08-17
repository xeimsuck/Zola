#include <Zola/Objects/ChatMember.hpp>
#include <magic_enum.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMember::operator json() const {
	return toJson();
}

json ChatMember::toJson() const {
	json data;
	data["status"] = magic_enum::enum_name(status);
	data["user"] = user.toJson();
	return data;
}
