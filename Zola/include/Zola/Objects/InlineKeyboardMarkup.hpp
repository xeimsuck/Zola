/*!
    @file
    @brief Inline keyboard markup object
    @author Xeim
    @version 0.2
    @data 13.08.24

    This object represents an inline keyboard that appears right next to the message it belongs to.
 */

#ifndef ZOLA_OBJECTS_INLINEKEYBOARDMARKUP_HPP
#define ZOLA_OBJECTS_INLINEKEYBOARDMARKUP_HPP

#include <vector>
#include <nlohmann/json.hpp>
#include "InlineKeyboardButton.hpp"

namespace Zola::Objects {
    struct InlineKeyboardMarkup {
        /*!
         * @brief Default constructor
         */
         InlineKeyboardMarkup() = default;

         /*!
          * @brief Parse json
          * @param data Json markup
          */
         explicit InlineKeyboardMarkup(const nlohmann::json& data);

         /*!
          * @brief Array of button rows, each represented by an Array of InlineKeyboardButton objects
          */
         std::vector<std::vector<InlineKeyboardButton>> inline_keyboard;
    };
}

#endif //ZOLA_OBJECTS_INLINEKEYBOARDMARKUP_HPP
