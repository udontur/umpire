
#ifndef util
#define util

#include <string>
using namespace std;

bool gccCompile(string filePath){
    string command="g++ main.cpp -o ";
    command+=filePath;
    int isCompiled=!system(command.c_str());
    return isCompiled;
}

#endif