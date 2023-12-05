#include <iostream>
#include <vector>
#include <string>


class MapCreator {
private:
    std::vector<std::vector<std::string>> map;

public:
    MapCreator(int numRows, int numColumns);
    void printMap() const;
    void setTile(int row, int col, const std::string& value);

};