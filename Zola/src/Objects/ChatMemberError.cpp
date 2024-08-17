#include <Zola/Objects/ChatMemberError.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMemberError::ChatMemberError() {
	status = ERROR_STATUS;
}

ChatMemberError::ChatMemberError(const long error_code, const std::string &description) {
	status = ERROR_STATUS;
	this->error_code = error_code;
	this->description = description;
}


json ChatMemberError::toJson() const {
	json data;
	data["status"] = status;
	return data;
}

