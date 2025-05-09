#ifndef util
#define util

#include <string>
#include <vector>
#include <filesystem>
#include <unordered_map>

using namespace std;

bool gccCompile(string filePath){
    string command="g++ main.cpp -o ";
    command+=filePath;
    int isCompiled=!system(command.c_str());
    return isCompiled;
}

class File{
    public:
        string str;
        filesystem::path path;
        int len=str.length();
};

vector<string> getPathList(string directory){
    vector<string> pathList;
    unordered_map<string, bool> isUnique;
    for(auto const& dirEntry: filesystem::directory_iterator{directory}){
        File currentFile;

        currentFile.path=dirEntry.path().filename();
        currentFile.str=static_cast<string>(currentFile.path);

        //int currentFile.len=currentFileStr.length();
        int dotPosition, eraseLength;
        if(currentFile.str[currentFile.len-1]=='n'){
            dotPosition=currentFile.len-3;
            eraseLength=3;
        }else{
            dotPosition=currentFile.len-4;
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