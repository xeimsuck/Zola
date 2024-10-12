/*!
    @file
    @brief InputMediaVideo object.
    @author Xeim
    @version 0.2
    @data 13.08.24

    Represents a video to be sent.
 */

#include <string>
#include <optional>
#include <nlohmann/json.hpp>
#include "InputMedia.hpp"

#ifndef ZOLA_OBJECTS_INPUTMEDIAVIDEO_HPP
#define ZOLA_OBJECTS_INPUTMEDIAVIDEO_HPP

namespace Zola::Objects {
    struct InputMediaVideo final : InputMedia{
        /*!
         * @brief Default constructor
         */
        InputMediaVideo();

        /*!
         * @brief Constructor
         */
        InputMediaVideo(std::string media, std::optional<std::string> caption = std::nullopt);

        /*!
         * Parse json format.
         * @param data Json data.
         */
        explicit InputMediaVideo(const nlohmann::json& data);

        /*!
         * @brief Default virtual destructor
         */
        ~InputMediaVideo() override = default;

        /*!
         * @brief Parse InputMediaVideo to json format.
         */
        [[nodiscard]] nlohmann::json toJson() const override;

        // Sorry guys im tired
    };
}

#endif //ZOLA_OBJECTS_INPUTMEDIAVIDEO_HPP
