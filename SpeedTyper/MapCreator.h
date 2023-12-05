#include <iostream>
#include <vector>
#include <string>


class MapCreator {
private:
    std::vector<std::vector<std::string>> map;
    int row;
    int col;

public:
    MapCreator(int numRows, int numColumns);
    void printMap() const;
    void setTile(int row, int col, const std::string& value);
    int getRow() const;
    int getCol() const;
    std::string getElement(int row, int col);

};