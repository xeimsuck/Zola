/*!
    @file
    @brief Voice object
    @author Xeim
    @version 0.1
    @data 13.08.24

    This struct contains information about voice
 */


#ifndef ZOLA_OBJECTS_VOICE_HPP
#define ZOLA_OBJECTS_VOICE_HPP

#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace Zola::Objects {
    struct Voice {
        //! Constructor parse json message
        explicit Voice(const nlohmann::json& data);

        //! Identifier for this file, which can be used to download or reuse the file
        std::string file_id;

        //! Unique identifier for this file
        std::string file_unique_id;

        //! Duration of the audio in seconds as defined by the sender
        long duration;

        //! MIME type of the file as defined by the sender
        std::string mime_type;

        //! File size in bytes
        std::optional<long> file_size;
    };
}

#endif //ZOLA_OBJECTS_VOICE_HPP
