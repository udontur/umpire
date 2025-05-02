#include <fmt/format.h>
#include <iostream>
#include <string>
#include <filesystem>
#include <sys/stat.h>
#include <thread>
#include <future>

#include "components/help.h"
#include "components/error.h"
#include "components/cache.h"
#include "components/util.h"

using namespace fmt;
using namespace std;

class User{
    public:
        string homeFolder=getenv("HOME");
        string program="./program";
};

int main(int argc, char* argv[]){
    // Time: -t 
    // Help: --help or -h 

    int runTime;
    if(argc==1){
        runTime=1;
    }else if(argc==2){
        if(!strcmp(argv[1], "--help")==true||!strcmp(argv[1], "-h")==true){
            helpPage();
            return 0;
        }else{
            return throwError("Invalid flags.");
        }
    }else if(argc==3){
        if(!strcmp(argv[1], "-t")==true){
            try{
                runTime=stoi(argv[2]);
            }catch (...){
                return throwError("Time limit must be an integer.");
            }
        }else{
            return throwError("Invalid flags.");
        }
    }else{
        return throwError("Invalid arguments.");
    }

    if(filesystem::exists("testcase")==false){
        return throwError("\"testcase\" folder not found.");
    }
    if(filesystem::exists("main.cpp")==false){
        return throwError("\"main.cpp\" not found.");
    }
    
    clearCache();

    User user;

    auto compileThread = async(gccCompile, user.program);

    print("Compiling program...\n");

    bool isCompiled=compileThread.get();

    if(!isCompiled){
        return throwError("Cannot compile your code!");
    }else{
        print("Compiled!\n");
    }


}