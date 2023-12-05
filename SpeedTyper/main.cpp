#include "MapCreator.h"
#include "StringGenerator.h"

int main() {
    const int width = 5;
    const int height = 20;
    const int minLength = 2;
    const int maxLength = 20;

    MapCreator mapCreator(height, width);
    StringGenerator stringGenerator;
    
    mapCreator.printMap();

    return 0;
}
