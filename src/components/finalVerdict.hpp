#ifndef finalVerdict
#define finalVerdict

#include "../global/allheader.hpp"
#include "../global/var.hpp"

void makeFinalVerdict() {
    for (auto currentTestCase : testCaseList) {
        if (currentTestCase.isTle == true) {
            user.isTle = true;
        } else if (currentTestCase.isRte == true) {
            user.isRte = true;
        } else if (!currentTestCase.isAc == true) {
            user.isWa = true;
        } else if (currentTestCase.isAc == true) {
            user.isAc = true;
        }
        
        user.maxRunTime = std::max(
            currentTestCase.runTime, user.maxRunTime);
    }

    return;
}

void printFinalVerdict() {
    if (user.isTle) {
        fmt::print(fmt::bg(fmt::color::yellow) | fmt::fg(fmt::color::black),
            "Time Limited Exceeded (Time: >{}s)\n", static_cast<double>(user.runTimeLimit));
    } else if (user.isRte) {
        fmt::print(fmt::bg(fmt::color::orange) | fmt::fg(fmt::color::black),
            "Runtime Error (Time: {}s)\n", user.maxRunTime);
    } else if (user.isWa) {
        fmt::print(fmt::bg(fmt::color::red) | fmt::fg(fmt::color::white),
            "Wrong Answer (Time: {}s)\n", user.maxRunTime);
    } else if (user.isAc) {
        fmt::print(fmt::bg(fmt::color::green) | fmt::fg(fmt::color::white),
            "Accepted (Time: {}s)\n", user.maxRunTime);
    } else {
        fmt::print(fmt::bg(fmt::color::red) | fmt::fg(fmt::color::white),
            "Internal Error: Please open an issue at https://github.com/udontur/umpire\n");
    }
}

#endif
