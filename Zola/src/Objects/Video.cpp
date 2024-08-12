#include <Zola/Objects/Video.hpp>

using namespace Zola;

/*!
 * Constructor use json data for initialization
 * @param data parsed video
*/
Objects::Video::Video(const nlohmann::json &data) {
    file_id = data["file_id"];
    file_unique_id = data["file_unique_id"];
    width = data["width"];
    height = data["height"];
    duration = data["duration"];
    if(data.contains("file_name")){
        file_name = data["file_name"];
    }
    if(data.contains("mime_type")){
        mime_type = data["mime_type"];
    }
    if(data.contains("file_size")){
        file_size = data["file_size"];
    }
}
