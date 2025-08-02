#ifndef getList
#define getList

#include "../global/allheader.hpp"
#include "../global/var.hpp"

std::vector<std::string> getPathList(std::string directory) {
    std::vector<std::string> pathList;
    std::unordered_map<std::string, bool> isUnique;

    for (auto const& dirEntry : std::filesystem::directory_iterator{directory}) {
        File currentFile;

        currentFile.path = dirEntry.path().filename();
        currentFile.str = static_cast<std::string>(currentFile.path);

        // Get file name
        int dotPosition, eraseLength;
        if (currentFile.str[currentFile.str.length() - 1] == 'n') {
            dotPosition = currentFile.str.length() - 3;
            eraseLength = 3;
        } else {
            dotPosition = currentFile.str.length() - 4;
            eraseLength = 4;
        }
        currentFile.str.erase(dotPosition, eraseLength);

        // Remove duplicate
        if (!isUnique[currentFile.str]) {
            pathList.push_back(currentFile.str);
            isUnique[currentFile.str] = 1;
        }
    }
    return pathList;
}

std::vector<TestCase> getTestCaseList(std::vector<std::string> pathList) {
    std::vector<TestCase> testCaseList;

    for (int pathListIndex = 0; pathListIndex < pathList.size(); pathListIndex++) {
        TestCase currentTestCase;

        currentTestCase.name =
            pathList[pathListIndex];

        currentTestCase.inPath =
            user.testCaseFolder + "/" + currentTestCase.name + ".in";
        currentTestCase.outPath =
            user.testCaseFolder + "/" + currentTestCase.name + ".out";

        currentTestCase.index =
            pathListIndex;

        testCaseList.push_back(currentTestCase);
    }

    return testCaseList;
}

#endif
