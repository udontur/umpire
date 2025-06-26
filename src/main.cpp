#include "components/compareFunc.hpp"
#include "components/compile.hpp"
#include "components/error.hpp"
#include "components/finalVerdict.hpp"
#include "components/getList.hpp"
#include "components/judge.hpp"
#include "components/util.hpp"
#include "components/verdictTable.hpp"

#include "global/allheader.hpp"
#include "global/var.hpp"

int main(int argc, char* argv[]) {
    argparse::ArgumentParser program("um", "v0.1");

    program.add_epilog(
        "More help available at https://github.com/udontur/umpire.");

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
    } catch (const std::exception& err) {
        // Show help page
        std::cout << program;
        return throwError(err.what());
    }

    // Get parsed args
    user.folder = program.get<std::string>("folderPath");
    user.folder += "/";
    user.runTimeLimit = program.get<double>("-t");

    if (program["--help"] == true) {
        // Cannot use fmt::print
        std::cout << program;
    }

    // File system requirements
    if (std::filesystem::exists(user.folder + "testcase") == false) {
        fmt::print("The directory is \"{}\".\n", user.folder);
        return throwError("\"testcase\" folder not found.");
    }
    if (mainExists() == false) {
        fmt::print("The directory is \"{}\".\n", user.folder);
        return throwError(
            "Code file not found. \nSupported Language: C++, Rust, Go, Java, Python.");
    }

    clearCache();

    if (user.isCpp || user.isGo || user.isRs || user.isJava) {
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
        getPathList(user.folder + user.testCaseFolder);
    testCaseList = getTestCaseList(pathList);

    std::vector<std::thread> testCaseThreads(testCaseList.size());
    for (auto currentTestCase : testCaseList) {
        testCaseThreads[currentTestCase.index] =
            std::thread(runTest, currentTestCase.index);
    }
    for (auto currentTestCase : testCaseList) {
        testCaseThreads[currentTestCase.index].join();
    }

    clearCache();

    fmt::print("{}", deleteLine);
    renderVerdictTable(testCaseList);

    makeFinalVerdict();
    printFinalVerdict();

    return 0;
}
