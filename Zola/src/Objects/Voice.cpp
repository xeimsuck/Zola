#include <Zola/Objects/Voice.hpp>

using namespace Zola;

Objects::Voice::Voice(const nlohmann::json &data) {
    file_id = data["file_id"];
    file_unique_id = data["file_unique_id"];
    duration = data["duration"];
    mime_type = data["mime_type"];
    if(data.contains("file_size")){
        file_size = data["file_size"];
    }
}