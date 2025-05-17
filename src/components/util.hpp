#ifndef util
#define util

#include "../global/allheader.hpp"
#include "../global/var.hpp"

bool gccCompile(std::string filePath){
    std::string command="g++ main.cpp -o ";
    command+=filePath;
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

#endif