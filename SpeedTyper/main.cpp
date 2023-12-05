#include "GameManager.h"

int main() {
    const int width = 5;
    const int height = 30;

    GameManager gameManager(height, width);
    gameManager.startGame();

    return 0;
}
