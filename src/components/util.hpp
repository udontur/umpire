#ifndef util
#define util

#include "../global/allheader.hpp"
#include "../global/var.hpp"

void clearCache() {
    std::vector<std::string> removeList = {
        user.folder + "program",
        user.folder + "main"
    };
    for (auto filePath : removeList) {
        if (std::filesystem::exists(filePath)) {
            std::filesystem::remove(filePath);
        }
    }
    return;
}

std::string rand64() {
    const std::string charList = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device randomDevice;

    std::mt19937 generator(randomDevice());
    std::string randomString(charList);

    shuffle(randomString.begin(), randomString.end(), generator);
    return randomString;
}

#endif
