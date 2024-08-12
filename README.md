# Zola
****
## About
Library for working with Telegram API.
## Dependencies
**Languages:** C++20  
**Build systems:** CMake, Make  
**Libraries:** libcurl, nlohmann/json
## Documentation
Create documentation with doxygen
```shell
doxygen doxygen.conf
cd documentation/html
# open index.html file
```
It will be deployed soon
## Hot to build
1. Create a build directory and navigate into it
```shell
mkdir build
cd build
```
2. Build a project with cmake
```shell
cmake ..
make
# make install soon
```
## Project examples
### Echo bot
```c++
#include <Zola/Zola.hpp>
using namespace Zola;

int main(int argc, char*argv[]){
    // Create a bot with your token
    decltype(auto) bot = Zola::Bot::init("YOUR_BOT_TOKEN");
    // Add handler on any messages
    bot.getEventHandler().getMessageHandler().addAny([&](const Objects::Message& msg){
        // Send a message which bot received
        bot.getAPI().sendMessage(msg.text.value_or(""), msg.chat.id);
    });
    try {
        // Run a bot
        bot.run();
    } catch (const std::exception& ex){
        std::cout << ex.what() << "\n";
        return 1;
    }
    return 0;
}
```