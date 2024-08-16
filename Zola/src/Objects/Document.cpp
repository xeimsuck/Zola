#include <Zola/Objects/Document.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

Document::Document(const nlohmann::json &data) {
	file_id = data["file_id"];
	file_unique_id = data["file_unique_id"];
	if(data.contains("thumbnail")) {
		thumbnail = PhotoSize(data["thumbnail"]);
	}
	if(data.contains("file_name")) {
		file_name = data["file_name"];
	}
	if(data.contains("mime_type")) {
		mime_type = data["mime_type"];
	}
	if(data.contains("file_size")) {
		file_size = data["file_size"];
	}
}

Document::operator json() const {
	return toJson();
}

nlohmann::json Document::toJson() const {
	json parsedJson;
	parsedJson["file_id"] = file_id;
	parsedJson["file_unique_id"] = file_unique_id;
	if(file_name) {
		parsedJson["file_name"] = file_name.value();
	}
	if(thumbnail) {
		parsedJson["thumbnail"] = thumbnail->toJson();
	}
	if(mime_type) {
		parsedJson["mime_type"] = mime_type.value();
	}
	if(file_size) {
		parsedJson["file_size"] = file_size.value();
	}
	return parsedJson;
}

