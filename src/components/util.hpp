#ifndef util
#define util

#include "../global/allheader.hpp"
#include "../global/var.hpp"

bool runCompile(){
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

std::vector<std::string> getPathList(std::string directory){
    std::vector<std::string> pathList;
    std::unordered_map<std::string, bool> isUnique;
    
    for(auto const& dirEntry: std::filesystem::directory_iterator{directory}){
        File currentFile;

        currentFile.path=dirEntry.path().filename();
        currentFile.str=static_cast<std::string>(currentFile.path);

        int dotPosition, eraseLength;
        if(currentFile.str[currentFile.str.length()-1]=='n'){
            dotPosition=currentFile.str.length()-3;
            eraseLength=3;
        }else{
            dotPosition=currentFile.str.length()-4;
            eraseLength=4;
        }
        
        currentFile.str.erase(dotPosition, eraseLength);
        
        if(!isUnique[currentFile.str]){
            pathList.push_back(currentFile.str);
            isUnique[currentFile.str]=1;
        }
    }
    return pathList;
}

bool mainExists(){
    if(std::filesystem::exists("main.cpp") == true){
        user.isCpp=1;
    }else if(std::filesystem::exists("main.py") == true){
        user.isPy=1;
    }else if(std::filesystem::exists("main.rs") == true){
        user.isRs=1;
    }else if(std::filesystem::exists("main.go") == true){
        user.isGo=1;
    }else if(std::filesystem::exists("main.java") == true){
        user.isJava=1;
    }
    if(
        std::filesystem::exists("main.cpp") == true ||
        std::filesystem::exists("main.py") == true ||
        std::filesystem::exists("main.rs") == true ||
        std::filesystem::exists("main.go") == true ||
        std::filesystem::exists("main.java") == true
    ) return true;
    else return false;
}

#endif