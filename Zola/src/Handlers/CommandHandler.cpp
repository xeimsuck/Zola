#include <Zola/Handlers/CommandHandler.hpp>

using namespace Zola;
using namespace Zola::Handlers;
using namespace Zola::Objects;

void CommandHandler::operator()(const Objects::Message &message) {
	call(message);
}

CommandHandler::Handler &CommandHandler::operator[](const std::string &text) {
	return handlers[text];
}

std::vector<std::string> CommandHandler::parseCommand(const std::string &text) {
	std::vector<std::string> ans;
    size_t i = 0;
    while (i!=std::string::npos) {
        const size_t j = text.find_first_of(' ', i);
        ans.push_back(text.substr(i, j-i));
        i = text.find_first_not_of(' ', j);
    }
    return ans;
}


void CommandHandler::call(const Message &message) {
	const auto params = parseCommand(message.text.value());
	if(anyHandler) anyHandler(message, params);
	if(handlers.contains(params.front())) {
		handlers[params.front()](message, params);
	} else if(unknownHandler) {
		unknownHandler(message, params);
	}
}


void CommandHandler::add(const std::string &text, Handler handler) {
	handlers[text] = std::move(handler);
}

void CommandHandler::addAny(Handler handler) {
	anyHandler = std::move(handler);
}

void CommandHandler::addUnknown(Handler handler) {
	unknownHandler = std::move(handler);
}




