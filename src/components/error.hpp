#ifndef error
#define error

#include <fmt/format.h>
#include <fmt/color.h>
#include "help.hpp"
#include "cache.hpp"
using namespace std;
using namespace fmt;

int throwError(string errorMessage){
    //helpPage();
    clearCache();
    string errorType;

    print(fg(color::red), "Error");
    print(": {}\n", errorMessage);
    return 1;
}

#endif