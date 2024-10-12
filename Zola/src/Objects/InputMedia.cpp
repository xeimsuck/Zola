#include <Zola/Objects/InputMedia.hpp>
#include <magic_enum.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

InputMedia::operator json() const {
    return toJson();
}

json InputMedia::toJson() const {
    json data;
    data["type"] = magic_enum::enum_name(type);
    data["media"] = media;
    if(caption) data["caption"] = caption.value();
    if(parse_mode) data["parse_node"] = parse_mode.value();
    return data;
}
