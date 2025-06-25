#ifndef compareFunc
#define compareFunc

#include "../global/allheader.hpp"
#include "../global/var.hpp"

bool compareOutput(int index) {
    TestCase& currentTestCase = testCaseList[index];

    std::filesystem::path samplePath =
        user.folder + currentTestCase.outPath;
    std::ifstream inSample(samplePath);

    std::filesystem::path programOutPath =
        currentTestCase.programOutPath;
    std::ifstream inProgram(programOutPath);

    // Empty
    if (inProgram.eof()) {
        currentTestCase.isRte = true;
        return false;
    }

    std::string sampleString, userString;
    while (!inSample.eof()) {
        inSample >> sampleString;
        inProgram >> userString;
        if (sampleString != userString) {
            return false;
        }
    }

    inSample.close();
    inProgram.close();

    return true;
}

#endif
