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

bool compareOutput(int currentTestCaseIndex, std::string outPath){
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

    std::string prefix="./"+user.program;
    if(user.isPy){
        prefix="python3 "+user.program+".py";
    }else if(user.isJs){
        prefix="bun run"+user.program+".js";
    }else if(user.isJava){
        prefix="java "+user.program;
    }

    std::string command=prefix+" < "+currentTestCase.in+" > "+outPath+" && exit 0";

    std::chrono::time_point<std::chrono::high_resolution_clock> runStart, runStop;    

    runStart=std::chrono::high_resolution_clock::now();
    
    boost::process::group groupT;
    boost::process::child runTestCase("bash", "-c", command.c_str(), groupT);

    while(runTestCase.running()){
        //runTestCase.wait();
        auto elapsedTime=std::chrono::high_resolution_clock::now()-runStart;
        if(elapsedTime>std::chrono::milliseconds(runTimeLimit)){
            currentTestCase.isTle=1;
            fmt::print("INTERUPTED: {}\n", elapsedTime.count());
            groupT.terminate();
            break;
        }
        fmt::print("{}\n", runTestCase.running());
        boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
    }
    runTestCase.wait();
    runStop=std::chrono::high_resolution_clock::now();
    


    if(runTestCase.exit_code()!=0){
        currentTestCase.isRte=1;
    }

    currentTestCase.isAc=compareOutput(currentTestCaseIndex, outPath);

    // if(!runTestCase.timed_join(boost::chrono::milliseconds(runTimeLimit))){
    //     // DO NOT RUN CODE, DOES NOT WORK
    //     // DOES NOT TERMINATE AND WILL BOMB YOUR DISK
    //     boost::this_thread::sleep_for(boost::chrono::milliseconds(200));
    //     runTestCase.interrupt();
    //     runTestCase.join();
    //     fmt::print("INTERUPTED!!! Well I suppose it did. ");
    //     currentTestCase.isTle=1;
    // }else{
    //     currentTestCase.isAc=compareOutput(currentTestCaseIndex, outPath);
    // }
    // runTestCase.join();
    std::filesystem::remove(outPath);
}

#endif
