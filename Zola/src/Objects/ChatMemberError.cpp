#include <Zola/Objects/ChatMemberError.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

ChatMemberError::ChatMemberError() {
	status = Status::error;
}

ChatMemberError::ChatMemberError(const long error_code, const std::string &description) {
	status = Status::error;
	this->error_code = error_code;
	this->description = description;
}


json ChatMemberError::toJson() const {
	json data;
	data["status"] = "error";
	return data;
}

