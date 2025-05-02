#include <fmt/format.h>
#include <iostream>
#include <string>
#include <filesystem>
#include <sys/stat.h>
#include <thread>

#include "components/help.h"
#include "components/error.h"
#include "components/cache.h"
#include "components/util.h"

using namespace fmt;
using namespace std;

struct User{
    string homeFolder=getenv("HOME");
    string program="./program";
};

int main(int argc, char* argv[]){
    // Time: -t 
    // Help: --help or -h 

    int runTime=1;
    if(argc!=2){
        if(argv[1]=="-t"){
            try{
                runTime=stoi(argv[2]);
            }catch (int errorCode){
                return throwError("Time limit must be an integer.", errorCode);
            }
        }else if(argv[1]=="--help"||argv[1]=="-h"){
            helpPage();
            return 0;
        }
    }

    if(filesystem::exists("testcase")==false){
        int errorCode=1;
        return throwError("\"testcase\" folder not found.", errorCode);
    }
    if(filesystem::exists("main.cpp")==false){
        int errorCode=1;
        return throwError("\"main.cpp\" not found.", errorCode);
    }
    
    clearCache();

    User user;

    
    try{
        thread compileThread(gccCompile, user.program);
        print("Compiling program...\n");
        compileThread.join();
        print("Compiled!");
        //cannot catch an error
    }catch (int errorCode){
        return throwError("Cannot compile your code!", errorCode);
    }
    
    

}