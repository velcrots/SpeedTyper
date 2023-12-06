#include "GameManager.h"
#include <iostream>
#include <windows.h>
#include <thread>
#include <conio.h>

GameManager::GameManager(int numRows, int numColumns) : mapCreator(numRows, numColumns) {}

void GameManager::startGame() {
    const int minLength = 2;
    const int maxLength = 20;
    bool isFailed = false;
    unsigned int count = 0;
    unsigned int stage = 5;

    std::string defaultString = "";
    for (int i = 0; i < maxLength; i++) {
        defaultString += " ";
    }

    std::string newString;
    std::string input;

    std::thread inputThread(&GameManager::handleInput, this);

    while (!isFailed) {
        Sleep(1000);

        if (count % stage == 0) {
            newString = stringGenerator.generateRandomString(minLength, maxLength);
            srand((unsigned int)time(NULL));
            int location = rand() % mapCreator.getCol();
            mapCreator.setTile(0, location, newString);
            this->words.push_back(newString);
        }

        count++;

        if (count % 100 == 0 && stage > 1) {
            stage--;
        }

        for (int i = 0; i < mapCreator.getCol(); i++) {
            if (mapCreator.getElement(mapCreator.getRow() - 1, i) != defaultString) {
                isFailed = true;
            }
        }

        for (int i = mapCreator.getRow() - 2; i >= 0; i--) {
            for (int j = 0; j < mapCreator.getCol(); j++) {
                if (mapCreator.getElement(i, j) != defaultString) {
                    mapCreator.setTile(i + 1, j, mapCreator.getElement(i, j));
                    mapCreator.setTile(i, j, defaultString);
                }
            }
        }

        system("cls");
        mapCreator.printMap();
    }

    inputThread.join();
    endGame();
    
}

void GameManager::handleInput() {
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
        }
    }
}

void GameManager::endGame() {

}