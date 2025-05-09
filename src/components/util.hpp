#ifndef util
#define util

#include <string>
#include <vector>
#include <filesystem>
#include <unordered_map>
#include <fmt/format.h>

using namespace std;
using namespace fmt;

bool gccCompile(string filePath){
    string command="g++ main.cpp -o ";
    command+=filePath;
    int isCompiled=!system(command.c_str());
    return isCompiled;
}

class File{
    public:
        string str;
        string out;
        string in;
        filesystem::path path;
};

vector<string> getPathList(string directory){
    vector<string> pathList;
    unordered_map<string, bool> isUnique;
    
    for(auto const& dirEntry: filesystem::directory_iterator{directory}){
        File currentFile;

        currentFile.path=dirEntry.path().filename();
        currentFile.str=static_cast<string>(currentFile.path);
        //
        
        //int currentFile.str.length()=currentFileStr.str.length()gth();
        int dotPosition, eraseLength;
        if(currentFile.str[currentFile.str.length()-1]=='n'){
            dotPosition=currentFile.str.length()-3;
            eraseLength=3;
        }else{
            dotPosition=currentFile.str.length()-4;
            eraseLength=4;
        }
        //print("CHECK {}, {}, {}", eraseLength, dotPosition, currentFile.str);
        //return pathList;
        currentFile.str.erase(dotPosition, eraseLength);
        
        if(!isUnique[currentFile.str]){
            pathList.push_back(currentFile.str);
            isUnique[currentFile.str]=1;
        }
    }
    return pathList;
}

#endif