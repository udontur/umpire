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

#endif