#include "MapCreator.h"

MapCreator::MapCreator(int numRows, int numColumns) : map(numRows, std::vector<std::string>(numColumns, "                    ")) {}

void MapCreator::printMap() const {
    for (const auto& row : map) {
        for (const std::string& tile : row) {
            std::cout << tile << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "--------------------------------------------------------------------------------------------------------\n";
}

void MapCreator::setTile(int row, int col, const std::string& value) {
    std::string formed_str = value;
    while (formed_str.length() < 20) {
        formed_str.append(" ");
    }

    if (row >= 0 && row < map.size() && col >= 0 && col < map[0].size()) {
        map[row][col] = formed_str.substr(0, 20);
    }
}
