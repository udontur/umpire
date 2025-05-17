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
        std::string program = "program";
        std::string testcaseFolder="testcase";
};
 
User user;

struct testCase{
    std::string name;
    std::string in;
    std::string out;
    int index;
    bool isTle=0;
    int isAc=-1;
};

int runTimeLimit;
std::vector<testCase> testCaseList;

#endif