/*!
    @file
    @brief CallbackQuery handler
    @author Xeim
    @version 0.2
    @data 13.08.24

    Class that handles CallbackQueries
 */

#ifndef ZOLA_HANDLERS_CALLBACKQUERYHANDLER_HPP
#define ZOLA_HANDLERS_CALLBACKQUERYHANDLER_HPP

#include <string>
#include <functional>
#include <unordered_map>
#include "../Objects/CallbackQuery.hpp"

namespace Zola::Handlers {
    class CallbackQueryHandler {
    public:
        /*!
         * @brief Callback alias
         */
        using Handler = std::function<void(Objects::CallbackQuery)>;

    public:
        /*!
         * @brief Use call method with callbackQuery
         * @param callbackQuery CallbackQuery object
         */
        void operator()(const Objects::CallbackQuery& callbackQuery);

        /*!
         * @param id ID of CallbackQuery
         * @return Handler which has this ID
         */
        Handler& operator[](const std::string& id);

        /*!
         * @brief Call handlers
         * @param callbackQuery CallbackQuery object
         */
        void call(const Objects::CallbackQuery& callbackQuery);

        /*!
         * @brief Add handler that will be called when "call" get object with this id
         * @param id ID of CallbackQuery
         * @param handler Callback handler
         */
        void add(const std::string& id, Handler handler);

        /*!
         * @brief Add handler that will be called when "call" get object with any id
         * @param handler
         */
        void addAny(Handler handler);

        /*!
         * @brief Add handler that will be called when "call" get object with unknown id
         * @param handler
         */
        void addUnknown(Handler handler);

    private:
        std::unordered_map<std::string, Handler> handlers;
        Handler unknownHandler = nullptr;
        Handler anyHandler = nullptr;
    };
}

#endif //ZOLA_HANDLERS_CALLBACKQUERYHANDLER_HPP
