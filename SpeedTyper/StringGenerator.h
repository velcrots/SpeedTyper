#ifndef STRINGGENERATOR_H
#define STRINGGENERATOR_H

#include <string>
#include <random>

class StringGenerator {
private:
    std::random_device rd;
    std::mt19937 randomEngine;

public:
    StringGenerator();
    std::string generateRandomString(int minLength, int maxLength);
};

#endif // STRINGGENERATOR_H
