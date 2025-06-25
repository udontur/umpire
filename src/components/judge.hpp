#ifndef judge
#define judge

#include "../global/allheader.hpp"
#include "../global/var.hpp"

void runTest(int index) {
    // Pass by index because boost::ref() does not work
    TestCase& currentTestCase = testCaseList[index];

    currentTestCase.programOutPath = user.folder + rand64() + ".txt";

    // Compile command prefix
    std::string prefix = user.folder + user.program;
    if (user.isPy) {
        prefix = "python3 " + user.folder + user.program + ".py";
    } else if (user.isJava) {
        prefix = "java -cp " + user.folder + " " + user.program;
    }
    std::string command = prefix + " < " + user.folder + currentTestCase.inPath + " > " + currentTestCase.programOutPath;
    
    int systemReturn;
    std::chrono::time_point<std::chrono::high_resolution_clock> runStart, runStop;
    auto runSystem = [&runStart, &runStop, &command, &systemReturn]() {
        runStart = std::chrono::high_resolution_clock::now();
        systemReturn = system(command.c_str());
        runStop = std::chrono::high_resolution_clock::now();
    };
    auto runSystemFuture = std::async(std::launch::async, runSystem);

    if (runSystemFuture.wait_for(
            std::chrono::milliseconds(
                static_cast<int>(user.runTimeLimit * 1000))) == std::future_status::timeout) {

        currentTestCase.isTle = true;
        // TLE display
        if (!tleFlag) {
            tleFlag = true;
            fmt::print("{}", deleteLine);
            fmt::print(fmt::fg(fmt::color::yellow),
                "Please press Control + C as your program has exceeded the time limit.\n");
            std::filesystem::remove(currentTestCase.programOutPath);
        }
    }

    if (systemReturn != 0) {
        currentTestCase.isRte = true;
    }
    
    currentTestCase.runTime = std::chrono::duration_cast<std::chrono::milliseconds>(runStop - runStart).count() / 1000.0;

    currentTestCase.isAc = compareOutput(index);
    
    std::filesystem::remove(currentTestCase.programOutPath);

    return;
}

#endif
