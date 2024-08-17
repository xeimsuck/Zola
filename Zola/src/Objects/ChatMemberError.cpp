#include <Zola/Objects/ChatMemberError.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMemberError::ChatMemberError() {
	status = ERROR_STATUS;
}

json ChatMemberError::toJson() const {
	json data;
	data["status"] = status;
	return data;
}

