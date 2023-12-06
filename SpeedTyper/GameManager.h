#include "MapCreator.h"
#include "StringGenerator.h"

class GameManager {
private:
    MapCreator mapCreator;
    StringGenerator stringGenerator;
    std::vector<std::string> words;

public:
    GameManager(int numRows, int numColumns);
    void startGame();
    void handleInput();
    void endGame();
};
