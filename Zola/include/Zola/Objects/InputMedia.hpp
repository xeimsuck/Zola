/*!
    @file
    @brief InputMedia object.
    @author Xeim
    @version 0.2
    @data 13.08.24

    This object represents the content of a media message to be sent.
 */

#ifndef ZOLA_OBJECTS_INPUTMEDIA_HPP
#define ZOLA_OBJECTS_INPUTMEDIA_HPP

#include <string>
#include <optional>
#include <nlohmann/json.hpp>

namespace Zola::Objects {
    struct InputMedia {
        /*!
         * @brief Default constructor
         */
        InputMedia() = default;

        /*!
         * @brief Default virtual destructor
         */
        virtual ~InputMedia() = default;

        /*!
         * @brief Cast to json.
         */
        explicit operator nlohmann::json() const;

        /*!
         * @brief Parse BotDescription to json format.
         */
        [[nodiscard]] virtual nlohmann::json toJson() const;

        /*!
         * @brief Represent all types
         */
        enum class TYPE {
            error, photo, video, audio, document, animation
        };

        /*!
         * @brief Type of the result
         */
        TYPE type = TYPE::error;


        /*!
         * @brief File to send.
         *
         * Pass a file_id to send a file that exists on the Telegram servers (recommended),
         * pass an HTTP URL for Telegram to get a file from the Internet, or pass “attach://<file_attach_name>”
         * to upload a new one using multipart/form-data under <file_attach_name> name
         */
        std::string media;


        /*!
         * @brief Caption of the photo to be sent, 0-1024 characters after entities parsing
         */
        std::optional<std::string> caption = std::nullopt;
    };
}

#endif //ZOLA_OBJECTS_INPUTMEDIA_HPP
