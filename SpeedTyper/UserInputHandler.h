#include <string>
#include <thread>
#include <mutex>

class UserInputHandler {
public:
    UserInputHandler();
    ~UserInputHandler();

    void startInputThread();
    void endInputThread();

    std::string getUserInput();

private:
    bool threadExitFlag;
    std::string userInput;
    std::thread inputThread;
    std::mutex inputMutex;

    void inputThreadFunction();
};
