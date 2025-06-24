#ifndef judge
#define judge

#include "../global/allheader.hpp"
#include "../global/var.hpp"

bool compareOutput(int index){
    
    TestCase& currentTestCase=testCaseList[index];

    std::filesystem::path samplePath=currentTestCase.outPath;
    std::filesystem::path programOutPath=currentTestCase.programOutPath;

    std::ifstream inSample(samplePath); 
    std::ifstream inProgram(programOutPath); 

    //Empty
    if(inProgram.eof()){
        currentTestCase.isRte=true;
        return 0;
    }

    std::string sampleString, userString;
    while(!inSample.eof()){
        inSample>>sampleString;
        inProgram>>userString;
        if(sampleString!=userString){
            return 0;
        }
    }
    
    inSample.close();
    inProgram.close();
    return 1;
}

void runTest(int index){

    TestCase& currentTestCase=testCaseList[index];

    currentTestCase.programOutPath="./"+rand64()+".txt";

    std::string prefix="./"+user.program;
    if(user.isPy){
        prefix="python3 "+user.program+".py";
    }else if(user.isJava){
        prefix="java "+user.program;
    }

    std::string command=prefix+" < "+currentTestCase.inPath+" > "+currentTestCase.programOutPath;

    std::chrono::time_point<std::chrono::high_resolution_clock> runStart, runStop;    

    int systemReturn;
    auto runSystem=[&runStart, &runStop, &command, &systemReturn](){
        runStart=std::chrono::high_resolution_clock::now();
        systemReturn=system(command.c_str());
        runStop=std::chrono::high_resolution_clock::now();
    };
    
    auto runSystemFuture=std::async(std::launch::async, runSystem);

    if(runSystemFuture.wait_for(
            std::chrono::milliseconds(
                static_cast<int>(user.runTimeLimit*1000))) ==
            std::future_status::timeout){
        currentTestCase.isTle=true;
        //BROKEN TLE (TODO)
        if(!tleFlag){
            tleFlag=true;
            fmt::print("{}", deleteLine);
            fmt::print(fmt::fg(fmt::color::yellow), "Please press Control + C as your program has exceeded the time limit.\n");
            std::filesystem::remove(currentTestCase.programOutPath);
        }
    }

    if(systemReturn!=0){
        currentTestCase.isRte=true;
    }

    currentTestCase.runTime=
        std::chrono::duration_cast
            <std::chrono::milliseconds>(runStop - runStart)
                .count()/1000.0;
    currentTestCase.isAc=compareOutput(index);

    std::filesystem::remove(currentTestCase.programOutPath);

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
    //         if(elapsedTime>std::chrono::milliseconds(user.runTimeLimit)){
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
    //         if(elapsedTime>std::chrono::milliseconds(user.runTimeLimit)){
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
    //         if(elapsedTime>std::chrono::milliseconds(user.runTimeLimit)){
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
    //     if(elapsedTime>std::chrono::milliseconds(user.runTimeLimit)){
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

     // if(!runTestCase.timed_join(boost::chrono::milliseconds(user.runTimeLimit))){
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
