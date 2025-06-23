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
        std::string homeFolder = getenv("HOME");
        std::string program = "main";
        std::string testCaseFolder="testcase";
        int runTimeLimit=1000;
        bool isCpp=0;
        bool isPy=0;
        bool isRs=0;
        bool isGo=0;
        bool isJava=0;
};
 
User user;


struct TestCase{
    std::string name;
    std::string inPath;
    std::string outPath;
    std::string programOutPath;
    std::string verdict;
    double runTime=-1;
    int index;
    bool isTle=0;
    bool isAc=0;
    bool isRte=0;
};

std::vector<TestCase> testCaseList;

bool tleFlag=0;

#define deleteLine "\033[1A\r\033[K"

#endif