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
        std::string testcaseFolder="testcase";
        bool isCpp=0;
        bool isPy=0;
        bool isRs=0;
        bool isGo=0;
        bool isJava=0;
};
 
User user;

struct testCase{
    std::string name;
    std::string in;
    std::string out;
    std::string outPath;
    double runTime=-1;
    int index;
    bool isTle=0;
    bool isAc=0;
    bool isRte=0;
};

int runTimeLimit;
std::vector<testCase> testCaseList;

bool tleFlag=0;

#define deleteLine "\033[1A\r\033[K"


#endif