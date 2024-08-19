/*!
	@file
	@brief Command handler
	@author Xeim
	@version 0.2
	@data 19.08.24

	Class that handles commands
 */

#ifndef ZOLA_HANDLERS_COMMANDHANDLER_HPP
#define ZOLA_HANDLERS_COMMANDHANDLER_HPP

#include <vector>
#include <string>
#include <functional>
#include <unordered_map>
#include <Zola/Objects/Message.hpp>

namespace Zola::Handlers {
	class CommandHandler {
	public:
		using Handler = std::function<void(const Objects::Message&, const std::vector<std::string>&)>;

	public:
		/*!
		 * @brief Call "call" method
		 * @param message Message object
		 */
		void operator()(const Objects::Message& message);

		/*!
		 * @return Handler of this text.
		 */
		Handler& operator[](const std::string& text);

		/*!
		 * @brief Call linked handler.
		 * @param message IDI NAXYI<3
		 */
		void call(const Objects::Message& message);

		/*!
		 * @brief Link handler with command
		 * @param text command
		 * @param handler callback handler
		 */
		void add(const std::string& text, Handler handler);

		/*!
		 * @brief Link handler with any command
		 * @param handler callback handler
		 */
		void addAny(Handler handler);

		/*!
		 * @brief Link handler with unknown command
		 * @param handler callback handler
		 */
		void addUnknown(Handler handler);

		/*!
		 * @brief Parse command
		 * @param text full command
		 * @return vector of parameters with command in 0 index
		 */
		static std::vector<std::string> parseCommand(const std::string& text);
	private:
		std::unordered_map<std::string, Handler> handlers;
		Handler unknownHandler = nullptr;
		Handler anyHandler = nullptr;
	};
}

#endif //COMMANDHANDLER_HPP
