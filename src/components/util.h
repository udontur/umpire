
#ifndef util
#define util

#include <string>
using namespace std;

void gccCompile(string filePath){
    string command="g++ main.cpp -o ";
    command+=filePath;
    system(command.c_str());
}

#endif