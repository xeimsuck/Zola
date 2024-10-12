#include <Zola/Objects/InputMediaVideo.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

InputMediaVideo::InputMediaVideo() {
    type = TYPE::video;
}

InputMediaVideo::InputMediaVideo(const json &data) {
    type = TYPE::video;
    media = data["media"];
    if(data.contains("caption")) caption = data["caption"];
    if(data.contains("parse_mode")) caption = data["parse_mode"];
}

InputMediaVideo::InputMediaVideo(std::string _media, std::optional<std::string> _caption, std::optional<std::string> _parse_mode) {
    type = TYPE::video;
    media = std::move(_media);
    caption = std::move(_caption);
    parse_mode = std::move(_parse_mode);
}


json InputMediaVideo::toJson() const {
    json data;
    data["type"] = "video";
    data["media"] = media;
    if(caption) data["caption"] = caption.value();
    if(parse_mode) data["parse_mode"] = parse_mode.value();
    return data;
}
