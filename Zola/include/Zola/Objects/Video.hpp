/*!
    @file
    @brief Video object
    @author Xeim
    @version 0.1
    @data 12.08.24
    @warning not finished

    This struct contains information about video
 */


#ifndef ZOLA_OBJECTS_VIDEO_HPP
#define ZOLA_OBJECTS_VIDEO_HPP

#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace Zola::Objects {
    struct Video {
        explicit Video(const nlohmann::json& data);

        //! Identifier for this file, which can be used to download or reuse the file
        std::string file_id;

        //! Unique identifier for this file
        std::string file_unique_id;

        //! Video width as defined by the sender
        long width;

        //! Video height as defined by the sender
        long height;

        //! Duration of the video in seconds as defined by the sender
        long duration;

        //! todo add optional tumbnail (PhotoSize)

        //! Original filename as defined by the sender
        std::optional<std::string> file_name;

        //! MIME type of the file as defined by the sender
        std::optional<std::string> mime_type;

        //! File size in bytes
        std::optional<long> file_size;
    };
}

#endif //ZOLA_OBJECTS_VIDEO_HPP
