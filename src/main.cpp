#include "global/allheader.hpp"
#include "global/var.hpp"

#include "components/util.hpp"
#include "components/help.hpp"
#include "components/error.hpp"
#include "components/cache.hpp"
#include "components/runtest.hpp"

int main(int argc, char* argv[]) {

    // Argument parsing
    if (argc == 1) {
        // Default time limit
        runTimeLimit = 1000;
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
                runTimeLimit = std::stod(argv[2])*1000;
            } catch (...) {
                return throwError("Time limit must be an number.");
            }
        } else {
            return throwError("Invalid flags.");
        }
    } else {
        return throwError("Invalid arguments.");
    }

    // File system requirements
    if (std::filesystem::exists("testcase") == false) {
        return throwError("\"testcase\" folder not found.");
    }
    if(!mainExists()){
        return throwError("Code file not found. \nSupported Language: C++, Rust, Go, Java, Pytho, JavaScript");
    }

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
        // JavaScript: bun run main.js
        
        auto compileThread = std::async(runCompile);
        fmt::print("Compiling program...\n");
        bool isCompiled = compileThread.get();

        if (!isCompiled) {
            return throwError("Cannot compile your code!");
        } else {
            fmt::print("{}Running...\n", deleteLine);
        }
    }
    
    // Generate all the paths
    std::vector<std::string> pathList=getPathList(user.testcaseFolder);
    int testCaseIteratorIndex=0;

    for(auto currentTestCaseName: pathList){
        TestCase currentTestCase;
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
        testCaseThreads[currentTestCase.index]=
            boost::thread(
                boost::bind(runTest, currentTestCase.index));  
    }

    for(auto currentTestCase: testCaseList){
        testCaseThreads[currentTestCase.index].join();
        
    }

    clearCache();

    //std::filesystem::remove("program");

    // Delete the "Running..." line
    
    if(!tleFlag){
        fmt::print("{}", deleteLine);
    }else{
        fmt::print("{}", deleteLine);
        fmt::print("{}", deleteLine);
    }

    // Table creator
    std::vector<std::vector<std::string>> tableContent;
    tableContent.push_back({"Name", "Verdict", "Time"});
    for(auto currentTestCase: testCaseList){
        //currentTestCase.name
        //currentTestCase.verdict
        //currentTestCase.runTime
        std::vector<std::string> currentRow;
        
        currentRow.push_back(currentTestCase.name);

        currentTestCase.verdict=makeVerdict(currentTestCase);\
        currentRow.push_back(currentTestCase.verdict);
        
        std::string runTime_string=makeRunTime(currentTestCase.runTime, currentTestCase.isTle);
        currentRow.push_back(runTime_string);
        

        tableContent.push_back(currentRow);
    }

    auto table = ftxui::Table(tableContent);
    table.SelectAll().Border(ftxui::LIGHT);
    table.SelectAll().SeparatorVertical(ftxui::LIGHT);

    table.SelectRow(0).Border(ftxui::DOUBLE);
    table.SelectRow(0).Decorate(ftxui::bold);

    auto screen=ftxui::Screen::Create(
        ftxui::Dimension::Full(),
        ftxui::Dimension::Fixed(testCaseList.size()+4)
    );

    auto document=table.Render();
    ftxui::Render(screen, document);
    screen.Print();

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