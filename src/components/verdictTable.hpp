#ifndef verdictTable
#define verdictTable

#include "../global/allheader.hpp"
#include "../global/var.hpp"

ftxui::Element verdictToElement(std::string verdict);
std::string makeVerdict(TestCase &currentTestCase);
std::string makeVerdictRunTime(double runTime, bool isTle);

void renderVerdictTable(std::vector<TestCase> &testCaseList) {
    std::vector<std::vector<ftxui::Element>> tableContent;
    // First row
    tableContent.push_back({
        ftxui::text("Name"),
        ftxui::text("Verdict"),
        ftxui::text("Time")});
    
    for (auto currentTestCase : testCaseList) {
        std::vector<ftxui::Element> currentRow;

        // currentTestCase.name
        currentRow.push_back(ftxui::text(currentTestCase.name));

        // currentTestCase.verdict
        currentTestCase.verdict =
            makeVerdict(currentTestCase);
        currentRow.push_back(
            verdictToElement(currentTestCase.verdict));

        // currentTestCase.runTime
        std::string runTime_string =
            makeVerdictRunTime(
                currentTestCase.runTime,
                currentTestCase.isTle);
        currentRow.push_back(ftxui::text(runTime_string));

        tableContent.push_back(currentRow);
    }

    // Make all border light
    auto table = ftxui::Table(tableContent);
    table.SelectAll().Border(ftxui::LIGHT);
    table.SelectAll().SeparatorVertical(ftxui::LIGHT);

    // Make the first row border heavy
    table.SelectRow(0).Border(ftxui::DOUBLE);
    table.SelectRow(0).Decorate(ftxui::bold);

    auto screen = ftxui::Screen::Create(
        ftxui::Dimension::Full(),
        ftxui::Dimension::Fixed(testCaseList.size() + 4));
        //                                            ^ 
        //                2 borders at the top + 1 title + 1 bottom border

    auto document = table.Render();
    ftxui::Render(screen, document);
    screen.Print();

    return;
}

ftxui::Element verdictToElement(std::string verdict) {
    if (verdict == "Time Limit Exceeded") {
        return ftxui::color(
            ftxui::Color::Yellow, ftxui::text(verdict));
    } else if (verdict == "Runtime Error") {
        // Yes, orange is called Orange1
        return ftxui::color(
            ftxui::Color::Orange1, ftxui::text(verdict));
    } else if (verdict == "Wrong Answer") {
        return ftxui::color(
            ftxui::Color::Red, ftxui::text(verdict));
    } else if (verdict == "Accepted") {
        return ftxui::color(
            ftxui::Color::Green, ftxui::text(verdict));
    } else {
        return ftxui::color(
            ftxui::Color::Yellow, ftxui::text(verdict));
    }
}

std::string makeVerdict(TestCase &currentTestCase) {
    std::string resultVerdict;

    if (currentTestCase.isTle) {
        resultVerdict = "Time Limit Exceeded";
    } else if (currentTestCase.isRte) {
        resultVerdict = "Runtime Error";
    } else if (currentTestCase.isAc) {
        resultVerdict = "Accepted";
    } else {
        resultVerdict = "Wrong Answer";
    }
    
    return resultVerdict;
}

std::string makeVerdictRunTime(double runTime, bool isTle) {
    std::string resultRunTime;

    if (isTle) {
        // Convert to run time limit
        std::string userRunTimeLimit_string = std::to_string(user.runTimeLimit);
        userRunTimeLimit_string = userRunTimeLimit_string.substr(0, 5);
        resultRunTime = ">" + userRunTimeLimit_string + "s";
    } else {
        // Convert to string
        resultRunTime = std::to_string(runTime);
        resultRunTime = resultRunTime.substr(0, 5);
        resultRunTime = resultRunTime + "s";
    }
    
    return resultRunTime;
}

#endif
