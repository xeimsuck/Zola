#include <Zola/Objects/WebAppInfo.hpp>

using namespace Zola;

Objects::WebAppInfo::WebAppInfo(const nlohmann::json &data) {
    url = data["url"];
}