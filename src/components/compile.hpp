#ifndef compile
#define compile

#include "../global/allheader.hpp"
#include "../global/var.hpp"

bool compileFunction(){
    std::string command;
    
    if(user.isCpp){
        command="g++ main.cpp -o main";
    }else if(user.isRs){
        command="rustc main.rs -o main";
    }else if(user.isGo){
        command="go build main.go";
    }else if(user.isJava){
        command="javac main.java";
    }

    int isCompiled=!system(command.c_str());
    return isCompiled;
}

#endif