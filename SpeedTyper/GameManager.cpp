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
    int count = 0;
    int stage = 5;

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
            std::pair<int, std::string> newPair;
            newPair.first = 0;
            newPair.second = newString;
            this->words.push_back(newPair);
        }

        count++;

        if (count % 100 == 0 && stage > 1) {
            stage--;
        }

        for (int i = mapCreator.getRow() - 2; i >= 0; i--) {
            for (int j = 0; j < mapCreator.getCol(); j++) {
                if (mapCreator.getElement(i, j) != defaultString) {
                    mapCreator.setTile(i + 1, j, mapCreator.getElement(i, j));
                    mapCreator.setTile(i, j, defaultString);
                }
            }
        }

        for (int i = 0; i < words.size(); i++) {
            words[i].first++;
            if (words[i].first == mapCreator.getRow() - 1) {
                isFailed = true;
            }
        }

        system("cls");
        mapCreator.printMap();
    }
    endGame();

}

void GameManager::handleInput() {
    while (true) {
        if (_kbhit()) {
            char ch = _getch();
            if (ch == 27) {
                break;
            }
            else if (ch == 8) {
                if (input.length() > 0) {
                    input.pop_back();
                }
            }
            else if (ch == 13) {
                for (int i = 0; i < words.size(); i++) {
                    if (input == words[i].second) {
                        for (int j = 0; j < mapCreator.getCol(); j++) {
                            mapCreator.setTile(words[i].first, j, "                    ");
                        }
                        words.erase(words.begin() + i);
                        score += 10;
                        break;
                    }
                }
                input = "";
            }
            else {
                input += ch;
            }
        }
    }
}

void GameManager::endGame() {
    std::cout << "Game Over!" << std::endl;
    std::cout << "Your score is: " << score << std::endl;
    std::cout << "Press ESC key to exit / Press R to restart" << std::endl;
    char ch = _getch();
    if (ch == 27) {
        exit(0);
    }
    else if (ch == 'r' || ch == 'R') {
        words.clear();
        for (size_t i = 0; i < mapCreator.getRow(); i++)
        {
            for (size_t j = 0; j < mapCreator.getCol(); j++)
            {
                mapCreator.setTile(i, j, "                    ");
            }
        }
        startGame();
    }

}