#include "MapCreator.h"

int main() {
    const int width = 5;
    const int height = 15;
    MapCreator mapCreator(height, width);
    mapCreator.printMap();

    return 0;
}
