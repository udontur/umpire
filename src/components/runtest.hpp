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

    //Empty
    if(inSample.eof()){
        currentTestCase.isRte=1;
        return 0;
    }

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
    currentTestCase.outPath="./"+rand64()+".txt";

    std::string prefix="./"+user.program;
    if(user.isPy){
        prefix="python3 "+user.program+".py";
    }else if(user.isJava){
        prefix="java "+user.program;
    }

    std::string command=prefix+" < "+currentTestCase.in+" > "+currentTestCase.outPath+" && exit 0";

    std::chrono::time_point<std::chrono::high_resolution_clock> runStart, runStop;    

    auto runSystem=[&runStart, &runStop, &command](){
        runStart=std::chrono::high_resolution_clock::now();
        int errorCode=system(command.c_str());
        runStop=std::chrono::high_resolution_clock::now();
    };
    
    auto runSystemFuture=std::async(std::launch::async, runSystem);

    if(runSystemFuture.wait_for(std::chrono::milliseconds(runTimeLimit)) == std::future_status::timeout){
        currentTestCase.isTle=1;
        //BROKEN TLE (TODO)
        if(!tleFlag){
            tleFlag=1;
            fmt::print("{}", deleteLine);
            fmt::print("Please press Ctrl + C as your program has exceeded the time limit.\n");
            fmt::print("This will be fixed in the stable release.\n");
        }
    }

    currentTestCase.runTime=
        std::chrono::duration_cast
            <std::chrono::milliseconds>(runStop - runStart)
                .count();
    
    currentTestCase.isAc=compareOutput(currentTestCaseIndex, currentTestCase.outPath);

    return;
}

#endif

/* Failed TLE function attempts:

// pid_t pid=fork();
    // if(pid==0){
    //     system(command.c_str());
    //     _exit(0);
    // }else if(pid>0){
    //     int status;
    //     while(1){
    //         auto elapsedTime=std::chrono::high_resolution_clock::now()-runStart;
    //         pid_t result=waitpid(pid, &status, WNOHANG);
    //         if(result==pid){
    //             fmt::print("DONE\n");
    //             break;
    //         }
    //         if(elapsedTime>std::chrono::milliseconds(runTimeLimit)){
    //             currentTestCase.isTle=1;
    //             try{
    //                 kill(pid, SIGKILL);
    //             }catch (...){
    //                 fmt::print("FAKE KILL\n");
    //             }
               
    //             fmt::print("KILLED\n");
    //             break;
    //         }
    //     }
    //     _exit(0);
    // }else{
    //     fmt::print("FORK FAIL\n");
    //     currentTestCase.isRte=1;
    // }

    // pid_t pid=fork();
    // if(pid==0){
    //     system(command.c_str());
    //     _exit(0);
    // }else if(pid>0){
    //     int status;
    //     while(1){
    //         auto elapsedTime=std::chrono::high_resolution_clock::now()-runStart;
    //         pid_t result=waitpid(pid, &status, WNOHANG);
    //         if(result==pid){
    //             fmt::print("DONE\n");
    //             break;
    //         }
    //         if(elapsedTime>std::chrono::milliseconds(runTimeLimit)){
    //             // Does not work
    //             kill(pid, SIGKILL);
               
    //             fmt::print("KILLED\n");
    //             break;
    //         }
    //     }
    //     _exit(0);
    // }else{
    //     fmt::print("FORK FAIL\n");
    // }

    // pid_t pid=fork();
    // if(pid==0){
    //     system(command.c_str());
    //     _exit(0);
    // }else if(pid>0){
    //     int status;
    //     while(1){
    //         auto elapsedTime=std::chrono::high_resolution_clock::now()-runStart;
    //         pid_t result=waitpid(pid, &status, WNOHANG);
    //         if(result==pid){
    //             fmt::print("DONE\n");
    //             break;
    //         }
    //         if(elapsedTime>std::chrono::milliseconds(runTimeLimit)){
    //             currentTestCase.isTle=1;
    //             kill(pid, SIGKILL);
    //             fmt::print("KILLED\n");
    //             break;
    //         }
    //     }
    //     _exit(0);
    // }else{
    //     fmt::print("FORK FAIL\n");
    //     currentTestCase.isRte=1;
    // }

    // boost::process::group groupT;
    // boost::process::child runTestCase("bash", "-c", command.c_str(), groupT);

    // while(1){
    //     //runTestCase.wait();
    //     auto elapsedTime=std::chrono::high_resolution_clock::now()-runStart;
        
    //     //FLAG
    //     fmt::print("{}\n", elapsedTime.count());
    //     if(elapsedTime>std::chrono::milliseconds(runTimeLimit)){
    //         currentTestCase.isTle=1;
    //         fmt::print("INTERUPTED: {}\n", elapsedTime.count());
    //         groupT.terminate();
    //         break;
    //     }
    //     //FALG
    //     fmt::print("{}\n", runTestCase.running());
    //     boost::this_thread::sleep_for(boost::chrono::milliseconds(100));
    // }
    // runTestCase.wait();
    // runStop=std::chrono::high_resolution_clock::now();
    


    // if(runTestCase.exit_code()!=0){
    //     currentTestCase.isRte=1;
    // }

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

*/