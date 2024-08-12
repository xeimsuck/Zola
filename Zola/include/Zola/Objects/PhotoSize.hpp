/*!
    @file
    @brief Photo object
    @author Xeim
    @version 0.1
    @data 12.08.24
    @warning not finished

    This object represents one size of a photo or a file / sticker thumbnail.
 */

#ifndef ZOLA_OBJECTS_PHOTO_HPP
#define ZOLA_OBJECTS_PHOTO_HPP

#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace Zola::Objects {
    struct PhotoSize {
        //! Constructor parse json message
        explicit PhotoSize(const nlohmann::json& data);

        //! Identifier for this file, which can be used to download or reuse the file
        std::string file_id;

        //! Unique identifier for this file
        std::string file_unique_id;

        //! Photo width
        long width;

        //! Photo height
        long height;

        //! File size in bytes
        std::optional<long> file_size;
    };
}

#endif //ZOLA_PHOTO_HPP
