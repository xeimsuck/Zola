/*!
    \file
    \brief Sticker object
    \author Xeim
    \version 0.1
    \data 12.08.24

    This struct contains information about sticker

    \warning not finished
    \todo add thumb and thumbnail attributes
    \todo use magicenum library with type attribute
 */

#ifndef ZOLA_OBJECTS_STICKER_HPP
#define ZOLA_OBJECTS_STICKER_HPP

#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace Zola::Objects {
    struct Sticker {
        //! Class represent type of sticker
        enum class Type {
            regular, mask, custom_emoji
        };

        //! Constructor parse json sticker
        explicit Sticker(const nlohmann::json& data);

        //! Sticker width
        long width;

        //! Sticker height
        long height;

        //! True if sticker is animated
        bool is_animated;

        //! True if sticker is video
        bool is_video;

        //! Type of sticker
        Type type;

        //! ID of sticker
        std::string file_id;

        //! Unique ID of sticker
        std::string file_unique_id;

        //! Emoji of sticker
        std::optional<std::string> emoji;

        //! Name of sticker
        std::optional<std::string> set_name;

        //! Size of sticker in bytes
        std::optional<long> file_size;
    };
}

#endif //ZOLA_OBJECTS_STICKER_HPP
