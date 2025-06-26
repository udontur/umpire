#ifndef compile
#define compile

#include "../global/allheader.hpp"
#include "../global/var.hpp"

bool compileFunction() {
    std::string command;

    if (user.isCpp) {
        command = "g++ ";
        command += user.folder + "main.cpp ";
        command += "-o ";
        command += user.folder + "main";
    } else if (user.isRs) {
        command = "rustc ";
        command += user.folder + "main.rs ";
        command += "-o ";
        command += user.folder + "main";
    } else if (user.isGo) {
        command = "go build -o ";
        command += user.folder + "main ";
        command += user.folder + "main.go";
    } else if (user.isJava) {
        command = "javac -d " + user.folder + " ";
        command += user.folder + "main.java";
    }

    int isCompiled = !system(command.c_str());
    return isCompiled;
}

#endif
