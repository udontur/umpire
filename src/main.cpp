#include "global/allheader.hpp"
#include "global/var.hpp"

#include "components/util.hpp"
#include "components/help.hpp"
#include "components/error.hpp"
#include "components/cache.hpp"
#include "components/judge.hpp"
#include "components/verdictTable.hpp"
#include "components/compile.hpp"

int main(int argc, char* argv[]) {

    argparse::ArgumentParser program("um", "v0.1");

    program.add_epilog("More help available at https://github.com/udontur/umpire.");
    
    program.add_argument("folderPath")
      .default_value(std::string("."))
      .nargs(1)
      .help("specify which folder to use, leave empty for the current folder")
      .metavar("FOLDER_PATH");
    
    program.add_argument("-t")
        .default_value(1.0)
        .scan<'g', double>()
        .nargs(1)
        .help("specify the time limit, support decimal numbers")
        .metavar("TIME");    

    try {
      program.parse_args(argc, argv);
    }
    catch (const std::exception& err) {
      std::cerr << err.what() << std::endl;
      std::cerr << program;
      std::exit(1);
    }

    // Make the folder universal
    // Make the runTime adapt to it
    // Make the help page print using fmt
    // Make the parse error looks nicer
    auto folder=program.get<std::string>("folderPath");
    auto runTime=program.get<double>("-t");
    
    if(program["--help"]==true){
      std::cout<<program<<"\n";
    }
    
    // // Argument parsing
    // if (argc == 1) {
    //     // Default time limit
    //     user.runTimeLimit = 1.0;
    // } else if (argc == 2) {
    //     // Flags: --help, -h
    //     if (!strcmp(argv[1], "--help") == true ||
    //         !strcmp(argv[1], "-h")     == true) {
    //         helpPage();
    //         return 0;
    //     } else {
    //         return throwError("Invalid flags.");
    //     }
    // } else if (argc == 3) {
    //     // Flags: -t
    //     if (!strcmp(argv[1], "-t") == true) {
    //         try {
    //             user.runTimeLimit = std::stod(argv[2]);
    //         } catch (...) {
    //             return throwError("Time limit must be an number.");
    //         }
    //     } else {
    //         return throwError("Invalid flags.");
    //     }
    // } else {
    //     return throwError("Invalid arguments.");
    // }
    
    // File system requirements
    if (std::filesystem::exists("testcase") == false) {
        return throwError("\"testcase\" folder not found.");
    }
    if(!mainExists()){
        return throwError("Code file not found. \nSupported Language: C++, Rust, Go, Java, Python.");
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
        
        auto compileThread = std::async(compileFunction);
        fmt::print("Compiling program...\n");
        bool isCompiled = compileThread.get();

        if (!isCompiled) {
            return throwError("Cannot compile your code!");
        } else {
            fmt::print("{}Running...\n", deleteLine);
        }
    }
    
    // Generate a list of test cases
    std::vector<std::string> pathList =
        getPathList(user.testCaseFolder);
    testCaseList =
        getTestCaseList(pathList);

    // Multithread run each case
    boost::thread testCaseThreads[testCaseList.size()];
    for(auto currentTestCase: testCaseList){
        testCaseThreads[currentTestCase.index]=
            boost::thread(
                boost::bind(runTest, currentTestCase.index));  
    }
    for(auto currentTestCase: testCaseList){
        testCaseThreads[currentTestCase.index]
            .join();
    }

    clearCache();

    // Delete the "Running..." line    
    fmt::print("{}", deleteLine);

    renderVerdictTable(testCaseList);

    makeFinalVerdict();

    printFinalVerdict();
            
    return 0;
}
