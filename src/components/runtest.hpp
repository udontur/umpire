#ifndef runtest
#define runtest

#include <fmt/format.h>
#include <sys/stat.h>
#include <boost/thread.hpp>
#include <boost/chrono.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

#include <filesystem>
#include <future>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <unordered_map> 
#include "util.hpp"
#include <iostream>
#include <string>
#include <random>
#include <algorithm>

using namespace fmt;
using namespace std;
using namespace ftxui;

struct testCase{
    string name;
    string in;
    string out;
    int index;
    bool isTle=0;
    int verdict=-1;
    // 0: WA
    // 1: AC
    // 2: TLE
    // HOW TO DETEECT RTE
};

int runTimeLimit;
extern vector<testCase> testCaseList;

string rand64() {
    const string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    random_device random_device;
    mt19937 generator(random_device());
    string random_string(characters);
    shuffle(random_string.begin(), random_string.end(), generator);
    return random_string;
}

void runTest(int currentTestCaseIndex){
    testCase& currentTestCase=testCaseList[currentTestCaseIndex];
    string outPath="./"+rand64()+".txt";
    string command="./"+user.program+" < "+currentTestCase.in+" > "+outPath;
    boost::thread runTestCase(system, command.c_str());
    if(runTestCase.timed_join(boost::chrono::seconds(runTimeLimit))){
        print("HI {}: {}\n", currentTestCase.index, currentTestCase.isTle);
    }else{
        runTestCase.interrupt();
        currentTestCase.isTle=1;
        print("HI [{},{}] [{},{}]\n", currentTestCase.index, currentTestCase.isTle, testCaseList[currentTestCaseIndex].index, testCaseList[currentTestCaseIndex].isTle);
    }
    filesystem::remove(outPath);
}

#endif
