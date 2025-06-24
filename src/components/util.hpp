#ifndef util
#define util

#include "../global/allheader.hpp"
#include "../global/var.hpp"

void makeFinalVerdict(){
    for(auto currentTestCase: testCaseList){
        if(currentTestCase.isTle){
            user.isTle=true;
        }else if(currentTestCase.isRte){
            user.isRte=true;
        }else if(!currentTestCase.isAc){
            user.isWa=true;
        }else if(currentTestCase.isAc){
            user.isAc=true;
        }
        user.maxRunTime=std::max(user.maxRunTime,
            currentTestCase.runTime);
    }
    return;
}

void printFinalVerdict(){
    
    if(user.isTle){
        fmt::print(fmt::bg(fmt::color::yellow) | fmt::fg(fmt::color::black),
            "Time Limited Exceeded (Time: >{}s)\n",
            static_cast<double>(user.runTimeLimit));
    }else if(user.isRte){
        fmt::print(fmt::bg(fmt::color::orange) | fmt::fg(fmt::color::black),
            "Runtime Error (Time: {}s)\n",
            user.maxRunTime);
    }else if(user.isWa){
        fmt::print(fmt::bg(fmt::color::red) | fmt::fg(fmt::color::white),
            "Wrong Answer (Time: {}s)\n",
            user.maxRunTime);
    }else if(user.isAc){
        fmt::print(fmt::bg(fmt::color::green) | fmt::fg(fmt::color::white),
            "Accepted (Time: {}s)\n",
            user.maxRunTime);
    }else{
        fmt::print(fmt::bg(fmt::color::red) | fmt::fg(fmt::color::white),
            "Internal Error: Please open an issue at https://github.com/udontur/umpire\n");
    }
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

std::vector<TestCase> getTestCaseList(std::vector<std::string> pathList){
    std::vector<TestCase> testCaseList;
    
    for(int pathListIndex =0; pathListIndex<pathList.size(); pathListIndex++){
        TestCase currentTestCase;

        currentTestCase.name=pathList[pathListIndex];

        currentTestCase.inPath=user.testCaseFolder+"/"+currentTestCase.name+".in";
        currentTestCase.outPath=user.testCaseFolder+"/"+currentTestCase.name+".out";

        currentTestCase.index=pathListIndex;

        testCaseList.push_back(currentTestCase);
    }

    return testCaseList;
}

std::string rand64() {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::string random_string(characters);
    shuffle(random_string.begin(), random_string.end(), generator);
    return random_string;
}

#endif
