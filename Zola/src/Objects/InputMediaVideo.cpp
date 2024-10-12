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
}

InputMediaVideo::InputMediaVideo(std::string _media, std::optional<std::string> _caption) {
    type = TYPE::video;
    media = std::move(_media);
    caption = std::move(_caption);
}


json InputMediaVideo::toJson() const {
    json data;
    data["type"] = "video";
    data["media"] = media;
    if(caption) data["caption"] = caption.value();
    return data;
}
