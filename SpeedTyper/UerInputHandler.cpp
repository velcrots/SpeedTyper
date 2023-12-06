#include "UserInputHandler.h"
#include <iostream>

UserInputHandler::UserInputHandler() : threadExitFlag(false) {}

UserInputHandler::~UserInputHandler() {
    endInputThread();
}

void UserInputHandler::inputThreadFunction() {
    while (!threadExitFlag) {
        std::string input;
        std::getline(std::cin, input);

        std::lock_guard<std::mutex> lock(inputMutex);
        userInput = input;
    }
}

void UserInputHandler::startInputThread() {
    inputThread = std::thread(&UserInputHandler::inputThreadFunction, this);
}

void UserInputHandler::endInputThread() {
    threadExitFlag = true;
    if (inputThread.joinable()) {
        inputThread.join();
    }
}

std::string UserInputHandler::getUserInput() {
    std::lock_guard<std::mutex> lock(inputMutex);
    return userInput;
}
