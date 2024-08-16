/*!
    @file
    @brief Document object
    @author Xeim
    @version 0.1
    @data 16.08.24

    This object represents a general file (as opposed to Photo, Message and Audio objects).
 */

#ifndef ZOLA_OBJECTS_DOCUMENT_HPP
#define ZOLA_OBJECTS_DOCUMENT_HPP

#include <optional>
#include <string>
#include <nlohmann/json.hpp>
#include "PhotoSize.hpp"

namespace Zola::Objects {
    struct Document {
        /*!
         * @brief Default constructor
         */
        Document() = default;

        /*!
         * @brief Parse json.
         * @param data Json CallbackQuery
         */
        explicit Document(const nlohmann::json& data);

        /*!
         * @brief Cast to json
         */
        explicit operator nlohmann::json() const;

        /*!
         * @brief Parse Document to json format
         */
        [[nodiscard]]nlohmann::json toJson() const;

        /*!
         * @brief Identifier for this file, which can be used to download or reuse the file
         */
        std::string file_id;

       /*!
        * @brief Unique identifier for this file.
        *
        * Supposed to be the same over time and for different bots. Can't be used to download or reuse the file.
        */
        std::string file_unique_id;

        /*!
         * @brief Document thumbnail as defined by the sender
         */
        std::optional<PhotoSize> thumbnail;

        /*!
         * @brief Original filename as defined by the sender.
         */
        std::optional<std::string> file_name;

        /*!
         * @brief MIME type of the file as defined by the sender.
         */
        std::optional<std::string> mime_type;

        /*!
         * @brief File size in bytes.
         *
         * It can be bigger than 2^31 and some programming languages
         * may have difficulty/silent defects in interpreting it. But
         * it has at most 52 significant bits, so a signed 64-bit integer
         * or double-precision float type are safe for storing this value.
         */
        std::optional<int> file_size;
    };
}

#endif //ZOLA_OBJECTS_DOCUMENT_HPP
