#ifndef util
#define util

#include "../global/allheader.hpp"
#include "../global/var.hpp"

ftxui::Element toElement(std::string verdict){
    if(verdict=="Time Limit Exceeded"){
        return ftxui::color(ftxui::Color::Yellow, ftxui::text(verdict));
    }else if(verdict=="Runtime Error"){
        return ftxui::color(ftxui::Color::Yellow, ftxui::text(verdict));
    }else if(verdict=="Wrong Answer"){
        return ftxui::color(ftxui::Color::Red, ftxui::text(verdict));
    }else if(verdict=="Accepted"){
        return ftxui::color(ftxui::Color::Green, ftxui::text(verdict));
    }else{
        return ftxui::color(ftxui::Color::Yellow, ftxui::text(verdict));
    }
}

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

std::string makeVerdict(TestCase currentTestCase){
    std::string resultVerdict;
    if(currentTestCase.isTle){
        resultVerdict="Time Limit Exceeded";
    }else if(currentTestCase.isRte){
        resultVerdict="Runtime Error";
    }else if(!currentTestCase.isAc){
        resultVerdict="Wrong Answer";
    }else if(currentTestCase.isAc){
        resultVerdict="Accepted";
    } else{
        resultVerdict="Internal Error";
    }
    return resultVerdict;
}

std::string makeRunTime(int runTime, bool isTle){
    std::string resultRunTime;
    if(isTle){
        std::string runTimeLimit_string=std::to_string(
            static_cast<double>(runTimeLimit)
                /1000.0);
        runTimeLimit_string=runTimeLimit_string.substr(0, 5);
        resultRunTime=">"+runTimeLimit_string+"s";
    }else{
        resultRunTime=std::to_string(
            static_cast<double>(runTime)
                /1000.0);
        resultRunTime=resultRunTime.substr(0, 5);
        resultRunTime=resultRunTime+"s";
    }
    return resultRunTime;
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
