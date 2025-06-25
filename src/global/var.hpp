#ifndef var
#define var

#include "allheader.hpp"

class File{
    public:
        std::string str;
        std::string out;
        std::string in;
        std::filesystem::path path;
};

class User {
    public:
        std::string folder;
        std::string program = "main";
        std::string testCaseFolder="testcase";

        double runTimeLimit=0.0;
        double maxRunTime=0.0;
        
        bool isCpp=false;
        bool isPy=false;
        bool isRs=false;
        bool isGo=false;
        bool isJava=false;

        bool isTle=false;
        bool isRte=false;
        bool isWa=false;
        bool isAc=false;   
};
 


struct TestCase{
    std::string name;
    std::string inPath;
    std::string outPath;
    std::string programOutPath;
    std::string verdict;
    double runTime=-1.0;
    int index;
    bool isTle=false;
    bool isAc=false;
    bool isRte=false;
};

std::vector<TestCase> testCaseList;
bool tleFlag=0;
User user;
#define deleteLine "\033[1A\r\033[K"

#endif
