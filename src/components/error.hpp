#ifndef error
#define error

#include "../global/allheader.hpp"
#include "../global/var.hpp"
#include "util.hpp"

int throwError(std::string errorMessage) {
    clearCache();
    std::string errorType;

    fmt::print(fmt::fg(fmt::color::red), "Error");
    fmt::print(": {}\n", errorMessage);
    return 1;
}

bool mainExists() {
    if (std::filesystem::exists(user.folder + "main.cpp") == true) {
        user.isCpp = true;
    } else if (std::filesystem::exists(user.folder + "main.py") == true) {
        user.isPy = true;
    } else if (std::filesystem::exists(user.folder + "main.rs") == true) {
        user.isRs = true;
    } else if (std::filesystem::exists(user.folder + "main.go") == true) {
        user.isGo = true;
    } else if (std::filesystem::exists(user.folder + "main.java") == true) {
        user.isJava = true;
    }
    
    if (std::filesystem::exists(user.folder + "main.cpp") == true ||
        std::filesystem::exists(user.folder + "main.py") == true ||
        std::filesystem::exists(user.folder + "main.rs") == true ||
        std::filesystem::exists(user.folder + "main.go") == true ||
        std::filesystem::exists(user.folder + "main.java") == true){
        return true;
    } else {
        return false;
    }
}

#endif
