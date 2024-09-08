/*!
    @file
    @brief Inline keyboard button object
    @author Xeim
    @version 0.2
    @data 13.08.24
    @warning not finished

    This object represents one button of an inline keyboard. Exactly
    one of the optional fields must be used to specify type of the button
 */

#ifndef ZOLA_OBJCETS_INLINEKEYBOARDBUTTON_HPP
#define ZOLA_OBJCETS_INLINEKEYBOARDBUTTON_HPP

#include <string>
#include <optional>
#include <nlohmann/json.hpp>
#include "WebAppInfo.hpp"
#include "LoginUrl.hpp"

namespace Zola::Objects {
    struct InlineKeyboardButton {
        /*!
         * @brief Default constructor.
         */
        InlineKeyboardButton() = default;

        /*!
         * ZOPA
         * @param text
         * @param callback_data
         */
        InlineKeyboardButton(std::string text, std::string callback_data);

        /*!
         * @brief Parse json.
         * @param data Json button.
         */
        explicit InlineKeyboardButton(const nlohmann::json& data);

        /*!
         * @brief Cast to json
         */
        explicit operator nlohmann::json() const;

        /*!
         * @brief Parse to json
         */
        nlohmann::json toJson() const;

        /*!
         * @brief Label text on the button.
         */
        std::string text;

         /*!
          * @brief HTTP or tg:// URL to be opened when the button is pressed.
          */
        std::optional<std::string> url;

        /*!
         * @brief Data to be sent in a callback query to the bot when the button is pressed, 1-64 bytes.
         */
        std::optional<std::string> callback_data;

        /*!
         * @brief Description of the Web App that will be launched when the user presses the button.
         *
         * The Web App will be able to send an arbitrary message on
         * behalf of the user using the method answerWebAppQuery.
         * Available only in private chats between a user and the bot.
         * Not supported for messages sent on behalf of a Telegram Business account.
         */
        std::optional<WebAppInfo> web_app;

        /*!
         * @brief An HTTPS URL used to automatically authorize the user.
         */
        std::optional<LoginUrl> login_url;


        /*!
         * @brief If set, pressing the button will prompt the user to select one of their chats.
         *
         * If set, pressing the button will prompt the user to select one of their chats, open that
         * chat and insert the bot's username and the specified inline query in the input field.
         * May be empty, in which case just the bot's username will be inserted. Not supported
         * for messages sent on behalf of a Telegram Business account.
         */
        std::optional<std::string> switch_inline_query;


        /*!
         * @brief If set, pressing the button will insert the bot's username
         * and the specified inline query in the current chat's input field.
         *
         * May be empty, in which case only the bot's username will be inserted.

         This offers a quick way for the user to open your bot in inline mode in the
         same chat - good for selecting something from multiple options.
         Not supported in channels and for messages sent on behalf of a Telegram
         Business account.
         */
        std::optional<std::string> switch_inline_query_current_chat;

        //! @todo add switch_inline_query_chosen_chat
        //! @todo add callback_game

        /*!
         * @brief Specify True, to send a Pay button.
         *
         * This type of button must always be the first button in the
         * first row and can only be used in invoice messages.
         */
        std::optional<bool> pay;
    };
}

#endif //ZOLA_OBJCETS_INLINEKEYBOARDBUTTON_HPP
