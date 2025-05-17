#ifndef runtest
#define runtest

#include "../global/allheader.hpp"
#include "../global/var.hpp"

std::string rand64() {
    const std::string characters = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::random_device random_device;
    std::mt19937 generator(random_device());
    std::string random_string(characters);
    shuffle(random_string.begin(), random_string.end(), generator);
    return random_string;
}
int compareOutput(int currentTestCaseIndex, std::string outPath){
    testCase& currentTestCase=testCaseList[currentTestCaseIndex];
    
    std::filesystem::path samplePath=currentTestCase.out;
    std::filesystem::path userPath=outPath;

    std::ifstream inSample(samplePath); //currentTestCase.out
    std::ifstream inUser(userPath); //outPath

    std::string sampleString, userString;
    while(!inSample.eof()){
        inSample>>sampleString;
        inUser>>userString;
        if(sampleString!=userString){
            return 0;
        }
    }

    inSample.close();
    inUser.close();
    return 1;
}
void runTest(int currentTestCaseIndex){
    testCase& currentTestCase=testCaseList[currentTestCaseIndex];
    std::string outPath="./"+rand64()+".txt";
    std::string command="./"+user.program+" < "+currentTestCase.in+" > "+outPath;
    boost::thread runTestCase(system, command.c_str());
    if(!runTestCase.timed_join(boost::chrono::seconds(runTimeLimit))){
        runTestCase.interrupt();
        currentTestCase.isTle=1;
    }else{
        currentTestCase.isAc=compareOutput(currentTestCaseIndex, outPath);
    }
    std::filesystem::remove(outPath);
}

#endif
