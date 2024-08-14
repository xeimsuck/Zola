/*!
    @file
    @brief WebAppInfo object
    @author Xeim
    @version 0.2
    @data 13.08.24

    Describes a Web App.
 */

#ifndef ZOLA_OBJECTS_WEBAPPINFO_HPP
#define ZOLA_OBJECTS_WEBAPPINFO_HPP

#include <string>
#include <nlohmann/json.hpp>

namespace Zola::Objects {
    struct WebAppInfo {
        /*!
         * @brief Default constructor
         */
        WebAppInfo() = default;

        /*!
         * @brief Parse json
         * @param data Json WebAppInfo
         */
        explicit WebAppInfo(const nlohmann::json& data);

        /*!
         * @brief Cast to json
         */
        explicit operator nlohmann::json() const;

        /*!
         * Parse WebAppInfo to json format
         * @return json
         */
        nlohmann::json toJson() const;

        /*!
         * @brief An HTTPS URL of a Web App to be opened with additional data as specified in Initializing Web Apps
         */
        std::string url;
    };
}

#endif //ZOLA_OBJECTS_WEBAPPINFO_HPP
