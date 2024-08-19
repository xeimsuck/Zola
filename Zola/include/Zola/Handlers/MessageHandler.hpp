/*!
    \file
    \brief Message handler
    \author Xeim
    \version 0.1
    \data 12.08.24

    Class that handles messages (also commands and edited messages)
 */

#ifndef ZOLA_HANDLERS_MESSAGEHANDLER_HPP
#define ZOLA_HANDLERS_MESSAGEHANDLER_HPP

#include <string>
#include <functional>
#include <unordered_map>
#include "../Objects/Message.hpp"

namespace Zola::Handlers {
    class MessageHandler{
    public:
        using Handler = std::function<void(const Objects::Message&)>;

    public:
        void operator()(const Objects::Message& message);
        Handler& operator[](const std::string& text);
        void call(const Objects::Message& message);
        void add(const std::string& text, Handler handler);
        void addAny(Handler handler);
        void addUnknown(Handler handler);

    private:
        std::unordered_map<std::string, Handler> handlers;
        Handler unknownHandler = nullptr;
        Handler anyHandler = nullptr;
    };
}

#endif //ZOLA_HANDLERS_MESSAGEHANDLER_HPP
