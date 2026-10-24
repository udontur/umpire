#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <filesystem>
#include <fstream>
#include <future>
#include <iomanip>
#include <iostream>
#include <thread>
#include <vector>
#include <algorithm>
#include <format>
#include <sys/stat.h>

using namespace std;
using namespace std::chrono;
using namespace std::filesystem;

const string homefolder = getenv("HOME");
const path usrout = homefolder + "/.cache/judgel/out.txt";
const path usrprg = homefolder + "/.cache/judgel/usr.out";

#define ColorReset "\033[0m"
#define ColorInv "\033[30m"
#define ColorRed "\033[31m"
#define ColorGreen "\033[32m"
#define ColorYellow "\033[33m"
#define ColorBlue "\033[34m"
#define ColorGray "\033[90m"
#define DelLine "\033[1A\r\033[K"

void ClearCache();
void PrintHelpPage();
string strip(string s);
bool OutputComparer(path ctcout);

int main(int argc, char * argv[]) {

    string times = "1";
    if (argc == 2)
        times = argv[1];
    for (int i = 0; i < times.size(); i++) {
        if (!(times[i] >= '0' && times[i] <= '9')) {
            cout << ColorRed;
            cout << "Error: ";
            cout << ColorReset;
            cout << "Time limit is not an integer\n";
            ClearCache();
            PrintHelpPage();
            return 0;
        }
    }
    int RunTimeLimit = stoi(times);

    if (!exists("testcase")) {
        cout << ColorRed;
        cout << "Error: ";
        cout << ColorReset;
        cout << "\"testcase\" not found\n";
        ClearCache();
        PrintHelpPage();
        return 0;
    }
    if (!exists("main.cpp")) {
        cout << ColorRed;
        cout << "Error: ";
        cout << ColorReset;
        cout << "\"main.cpp\" not found\n";
        ClearCache();
        PrintHelpPage();
        return 0;
    }

    ClearCache();

    cout << ColorGray;
    cout << "Compiling program...\n";
    cout << ColorReset;

    string runcmd = "g++ main.cpp -o " + static_cast < string > (usrprg);
    system(runcmd.c_str());

    if (!exists(usrprg)) {
        cout << ColorRed;
        cout << "Error: ";
        cout << ColorReset;
        cout << "Compilation error\n";
        ClearCache();
        return 0;
    }

    cout << DelLine;

    vector < string > tculp;
    for (path CurrentTestCase: recursive_directory_iterator("testcase")) {
        string t = static_cast < string > (CurrentTestCase);
        int n = t.size();
        if (t[n - 1] == 'n') {
            for (int j = 0; j < 3; j++) t.pop_back();
            tculp.push_back(t);
        }
    }
    sort(tculp.begin(), tculp.end());

    cout << "\033[90mTest       Verdict         Time\033[0m\n";
    int finalverdict = -1;
    bool skip = 0;
    for (string CurrentTestCase: tculp) {

        string ctcin = CurrentTestCase + ".in";
        string ctcout = CurrentTestCase + ".out";
        string ctcname = strip(CurrentTestCase);
        string RunCommand = "~/.cache/judgel/usr.out < " + ctcin + " > ~/.cache/judgel/out.txt";

        if (skip) {
            cout << format("{:<10} Skipped          N/A\n", ctcname);
            continue;
        }

        int state;
        time_point < high_resolution_clock > UserProgramStart;
        time_point < high_resolution_clock > UserProgramStop;

        auto RunSystem = [ & UserProgramStart, & RunCommand, & UserProgramStop, & state]() {
            UserProgramStart = high_resolution_clock::now();
            state = system(RunCommand.c_str());
            UserProgramStop = high_resolution_clock::now();
        };

        auto UserProgramFuture = async (launch::async, RunSystem);

        if (UserProgramFuture.wait_for(seconds(RunTimeLimit)) == future_status::timeout) {
            cout << format("{:<10} \033[33mTime Limit\033[0m   >{}s\n", ctcname, to_string(RunTimeLimit) + ".000");
            system("pkill -9 -f ~/.cache/judgel/usr.out");
            skip = 1;
            finalverdict = 3;
            continue;
        }

        const auto RuntimeTime = duration_cast < milliseconds > (UserProgramStop - UserProgramStart);
        int RuntimeInt = RuntimeTime.count();
        double Runtime = RuntimeInt / 1000.0;

        cout << fixed << setprecision(3);

        if (WEXITSTATUS(state) != 0) {
            cout << format("{:<10} \033[33mRuntime Error\033[0m {}s\n", ctcname, Runtime);
            skip = 1;
            finalverdict = 2;
            continue;
        }

        bool accepted = OutputComparer(ctcout);

        if (accepted == 1) {
            cout << format("{:<10} \033[32mAccepted\033[0m      {}s\n", ctcname, Runtime);
            finalverdict = 0;
        } else if (accepted == 0) {
            cout << format("{:<10} \033[31mWrong Answer\033[0m  {}s\n", ctcname, Runtime);
            finalverdict = 1;
        }

    }

    if (finalverdict == 0) cout << "\n\033[32mFinal Verdict: Accepted\033[0m\n";
    else if (finalverdict == 1) cout << "\n\033[31mFinal Verdict: Wrong Answer\033[0m\n";
    else if (finalverdict == 2) cout << "\n\033[33mFinal Verdict: Runtime Error\033[0m\n";
    else if (finalverdict == 3) cout << "\n\033[33mFinal Verdict: Time Limit Exceed\033[0m\n";
    else cout << "\033[34mYou’ve wandered off the map!\033[0m\n";

    ClearCache();
    return 0;

}

void ClearCache() {
    system("rm -rf ~/.cache/judgel");
    system("mkdir -p ~/.cache/judgel");
}

string strip(string s) {
    int n = s.size();
    string ans = "";
    for (int i = 9; i < n; i++) ans += s[i];
    return ans;
}

void PrintHelpPage() {
    cout << "\nCommand: ";
    cout << ColorGreen;
    cout << "judgel ";
    cout << ColorYellow;
    cout << "<TIME_LIMIT> \n";
    cout << ColorReset;
    cout << ColorGray;
    cout << "Leave the time limit empty for a 1 second time limit\n\n";
    cout << ColorReset;
    cout << "Prerequisites\n";
    cout << "   - Testcase folder name: \033[34m\"testcase\"\033[0m\n";
    cout << "   - Code file name: \033[34m\"main.cpp\"\033[0m\n";
    cout << "   - Testcases format: \033[34mABC.in\033[0m and \033[34mABC.out\033[0m\n\n";
    cout << ColorGray;
    cout << "More: https://github.com/udontur/judgel\n";
    cout << ColorReset;
}

bool OutputComparer(path ctcout) {
    ifstream tin(ctcout);
    ifstream uin(usrout);
    string t, u;
    while (!tin.eof()) {
        uin >> u;
        tin >> t;
        if (t != u) return 0;
    }
    return 1;
}