#ifndef error
#define error

#include "../global/allheader.hpp"
#include "cache.hpp"

int throwError(std::string errorMessage){
    //helpPage();
    clearCache();
    std::string errorType;

    fmt::print(fmt::fg(fmt::color::red), "Error");
    fmt::print(": {}\n", errorMessage);
    return 1;
}

bool mainExists(){
    if(std::filesystem::exists(user.folder+"main.cpp") == true){
        user.isCpp=1;
    }else if(std::filesystem::exists(user.folder+"main.py") == true){
        user.isPy=1;
    }else if(std::filesystem::exists(user.folder+"main.rs") == true){
        user.isRs=1;
    }else if(std::filesystem::exists(user.folder+"main.go") == true){
        user.isGo=1;
    }else if(std::filesystem::exists(user.folder+"main.java") == true){
        user.isJava=1;
    }
    if(
        std::filesystem::exists(user.folder+"main.cpp") == true ||
        std::filesystem::exists(user.folder+"main.py") == true ||
        std::filesystem::exists(user.folder+"main.rs") == true ||
        std::filesystem::exists(user.folder+"main.go") == true ||
        std::filesystem::exists(user.folder+"main.java") == true
    ) return true;
    else return false;
}

#endif
