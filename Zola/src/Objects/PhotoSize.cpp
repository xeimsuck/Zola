#include <Zola/Objects/PhotoSize.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

PhotoSize::PhotoSize(const json &data) {
    file_id = data["file_id"];
    file_unique_id = data["file_unique_id"];
    width = data["width"];
    height = data["height"];
    if(data.contains("file_size")){
        file_size = data["file_size"];
    }
}

PhotoSize::operator json() const {
    return toJson();
}

nlohmann::json PhotoSize::toJson() const {
    json parsedData;
    parsedData["file_id"] = file_id;
    parsedData["file_unique_id"] = file_unique_id;
    parsedData["width"] = width;
    parsedData["height"] = height;
    if(file_size) parsedData["file_size"] = file_size.value();
    return parsedData;
}

