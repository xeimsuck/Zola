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
        /*!
         * @brief Default constructor.
         */
    	PhotoSize() = default;

		/*!
		 * Constructor parse json message.
		 * @param data Data in json format.
		 */
		explicit PhotoSize(const nlohmann::json& data);

    	/*!
		 * @brief Cast to json
		 */
    	explicit operator nlohmann::json() const;

    	/*!
		 * @brief Parse Document to json format
		 */
    	[[nodiscard]]nlohmann::json toJson() const;

    	/*!
         * @brief Identifier for this file, which can be used to download or reuse the file.
         */
        std::string file_id;

    	/*!
		 * @brief Unique identifier for this file.
		 */
		std::string file_unique_id;

    	/*!
		 * @brief Photo width.
		 */
		long width = 0;

    	/*!
		 * @brief Photo height.
		 */
		long height = 0;

    	/*!
		 * @brief File size in bytes.
		 */
		std::optional<long> file_size;
    };
}

#endif //ZOLA_OBJECTS_PHOTO_HPP
