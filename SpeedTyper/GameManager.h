#include "MapCreator.h"
#include "StringGenerator.h"

class GameManager {
private:
    MapCreator mapCreator;
    StringGenerator stringGenerator;
    std::vector<std::pair<int, std::string>> words;
    std::string input;

public:
    GameManager(int numRows, int numColumns);
    void startGame();
    void handleInput();
    void endGame();
};
