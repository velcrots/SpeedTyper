#include "StringGenerator.h"

StringGenerator::StringGenerator() : randomEngine(rd()) {
    // Initialize random engine using random_device
}

std::string StringGenerator::generateRandomString(int minLenght, int maxLength) {
    // Define characters to use in the random string
    const std::string characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";

    // Initialize uniform distribution for selecting characters
    std::uniform_int_distribution<int> lengthDistribution(minLenght, maxLength);
    std::uniform_int_distribution<int> characterDistribution(0, characters.length() - 1);

    // Generate a random string of random length (2 to 20)
    int length = lengthDistribution(randomEngine);
    std::string randomString;

    for (int i = 0; i < length; ++i) {
        int randomIndex = characterDistribution(randomEngine);
        randomString += characters[randomIndex];
    }

    return randomString;
}
