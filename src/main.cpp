#include "global/allheader.hpp"
#include "global/var.hpp"

#include "components/util.hpp"
#include "components/cache.hpp"
#include "components/help.hpp"
#include "components/error.hpp"
#include "components/runtest.hpp"

using namespace std;

int main(int argc, char* argv[]) {

    fmt::print("testing {}", 1);
    // Argument parsing
    
    if (argc == 1) {
        // Default time limit
        runTimeLimit = 1;
    } else if (argc == 2) {
        // Flags: --help, -h
        if (!strcmp(argv[1], "--help") == true ||
            !strcmp(argv[1], "-h") == true) {
            helpPage();
            return 0;
        } else {
            return throwError("Invalid flags.");
        }
    } else if (argc == 3) {
        // Flags: -t
        if (!strcmp(argv[1], "-t") == true) {
            try {
                runTimeLimit = stoi(argv[2]);
            } catch (...) {
                return throwError("Time limit must be an integer.");
            }
        } else {
            return throwError("Invalid flags.");
        }
    } else {
        return throwError("Invalid arguments.");
    }

    // File system requirements
    if (filesystem::exists("testcase") == false) {
        return throwError("\"testcase\" folder not found.");
    }
    if(!mainExists()){
        return throwError("Code file not found. \nSupported Language: C++, Rust, Go, Java, Pytho, JavaScript");
    }

    // Getting ready
    clearCache();

    if(user.isCpp||
       user.isGo ||
       user.isRs ||
       user.isJava
    ){
        // Compiler
        // C++: g++ main.cpp -o main
        // Go: go build -o main main.go
        // Rust: rustc main.rs -o main
        // Java: javac main.java

        // Interpreter
        // Python: python3 main.py
        // JavaScript: node main.js
        
        auto compileThread = async(runCompile);
        fmt::print("Compiling program...\n");
        bool isCompiled = compileThread.get();

        if (!isCompiled) {
            return throwError("Cannot compile your code!");
        } else {
            fmt::print("Compiled!\n");
        }
    }
    
    // Generate all the paths
    std::vector<std::string> pathList=getPathList(user.testcaseFolder);
    int testCaseIteratorIndex=0;

    for(auto currentTestCaseName: pathList){
        testCase currentTestCase;
        currentTestCase.name=currentTestCaseName;
        currentTestCase.in=user.testcaseFolder+"/"+currentTestCase.name+".in";
        currentTestCase.out=user.testcaseFolder+"/"+currentTestCase.name+".out";
        currentTestCase.index=testCaseIteratorIndex;
        testCaseIteratorIndex++;

        testCaseList.push_back(currentTestCase);
    }
    
    // Multitrhead run each case
    boost::thread testCaseThreads[testCaseList.size()];
    for(auto currentTestCase: testCaseList){
        testCaseThreads[currentTestCase.index]=boost::thread(boost::bind(runTest, currentTestCase.index));  
    }

    for(auto currentTestCase: testCaseList){
        testCaseThreads[currentTestCase.index].join();
    }

    // Verdict Maker
    for(auto currentTestCase: testCaseList){
        std::string verdict;
        if(currentTestCase.isTle){
            verdict="Time Limit Exceeded";
        }else if(currentTestCase.isAc){
            verdict="Accepted";
        }else if(!currentTestCase.isAc){
            verdict="Wrong Answer";
        }else{
            verdict="Error";
        }

        fmt::print("{}({}): {}\n", currentTestCase.index, currentTestCase.name, verdict);
    }
    
    // Element document=hbox({
    //     text("left") | border,
    //     text("center") | border | flex,
    //     text("right") | border,
    // });
    // auto screen=Screen::Create(
    //     Dimension::Full(),
    //     Dimension::Fit(document)
    // );
    // Render(screen, document);
    // screen.Print();

}