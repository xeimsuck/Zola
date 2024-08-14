#include <Zola/Objects/WebAppInfo.hpp>

using namespace Zola;
using namespace Zola::Objects;
using namespace nlohmann;

WebAppInfo::WebAppInfo(const json& data) {
    url = data["url"];
}

WebAppInfo::operator nlohmann::json() const {
    return toJson();
}

json WebAppInfo::toJson() const {
    json parsed;
    parsed["url"] = url;
    return parsed;
}