#include <Zola/Objects/PhotoSize.hpp>

using namespace Zola;

Objects::PhotoSize::PhotoSize(const nlohmann::json &data) {
    file_id = data["file_id"];
    file_unique_id = data["file_unique_id"];
    width = data["width"];
    height = data["height"];
    if(data.contains("file_size")){
        file_size = data["file_size"];
    }
}