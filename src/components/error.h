#ifndef error
#define error

#include <fmt/format.h>
#include <fmt/color.h>
#include "./help.h"
#include "./cache.h"
using namespace std;
using namespace fmt;

int throwError(string errorMessage, int errorCode){
    helpPage();
    clearCache();
    string errorType;

    if(errorCode==0) errorType="Argument error";
    if(errorCode==1) errorType="Missing";
    if(errorCode==2) errorType="Compilation error";

    print(fg(color::red), "{}", errorType);
    print(": {}\n", errorMessage);
    return 1;
}

#endif