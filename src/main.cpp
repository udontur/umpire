#include <fmt/format.h>
#include <sys/stat.h>

#include <filesystem>
#include <future>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <unordered_map> 
#include <boost/thread.hpp>

#include "util.hpp"
#include "cache.hpp"
#include "help.hpp"
#include "error.hpp"

using namespace fmt;
using namespace std;

class User {
   public:
    string homeFolder = getenv("HOME");
    string program = "program";
    string testcaseFolder="testcase";
};

int main(int argc, char* argv[]) {
    print("testing {}", 1);
    // Argument parsing
    int runTimeLimit;
    if (argc == 1) {
        // Default time limit
        runTimeLimit = 1;
    } else if (argc == 2) {
        // Flags: --help, -h
        if (!strcmp(argv[1], "--help") == true ||
            !strcmp(argv[1], "-h") == true) {
            helpPage();
            return 0;
        } else {
            return throwError("Invalid flags.");
        }
    } else if (argc == 3) {
        // Flags: -t
        if (!strcmp(argv[1], "-t") == true) {
            try {
                runTimeLimit = stoi(argv[2]);
            } catch (...) {
                return throwError("Time limit must be an integer.");
            }
        } else {
            return throwError("Invalid flags.");
        }
    } else {
        return throwError("Invalid arguments.");
    }

    // File system requirements
    if (filesystem::exists("testcase") == false) {
        return throwError("\"testcase\" folder not found.");
    }
    if (filesystem::exists("main.cpp") == false) {
        return throwError("\"main.cpp\" not found.");
    }

    // Getting ready
    clearCache();
    User user;

    // Compile user's main.cpp
    auto compileThread = async(gccCompile, user.program);

    print("Compiling program...\n");

    bool isCompiled = compileThread.get();
    if (!isCompiled) {
        return throwError("Cannot compile your code!");
    } else {
        print("Compiled!\n");
    }

    vector<string> pathList=getPathList(user.testcaseFolder);

    

}