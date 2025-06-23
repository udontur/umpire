#ifndef verdictTable
#define verdictTable

#include "../global/allheader.hpp"
#include "../global/var.hpp"

ftxui::Element verdictToElement(std::string verdict){
    if(verdict=="Time Limit Exceeded"){
        return ftxui::color(ftxui::Color::Yellow, ftxui::text(verdict));
    }else if(verdict=="Runtime Error"){
        return ftxui::color(ftxui::Color::Yellow, ftxui::text(verdict));
    }else if(verdict=="Wrong Answer"){
        return ftxui::color(ftxui::Color::Red, ftxui::text(verdict));
    }else if(verdict=="Accepted"){
        return ftxui::color(ftxui::Color::Green, ftxui::text(verdict));
    }else{
        return ftxui::color(ftxui::Color::Yellow, ftxui::text(verdict));
    }
}

std::string makeVerdict(TestCase &currentTestCase){
    std::string resultVerdict;

    if(currentTestCase.isTle){
        resultVerdict="Time Limit Exceeded";
    }else if(currentTestCase.isRte){
        resultVerdict="Runtime Error";
    }else if(currentTestCase.isAc){
        resultVerdict="Accepted";
    }else{
        resultVerdict="Wrong Answer";
    }
    return resultVerdict;
}

std::string makeVerdictRunTime(int runTime, bool isTle){
    std::string resultRunTime;
    if(isTle){
        std::string userRunTimeLimit_string=std::to_string(
            static_cast<double>(user.runTimeLimit)
                /1000.0);
        userRunTimeLimit_string=userRunTimeLimit_string.substr(0, 5);
        resultRunTime=">"+userRunTimeLimit_string+"s";
    }else{
        resultRunTime=std::to_string(
            static_cast<double>(runTime)
                /1000.0);
        resultRunTime=resultRunTime.substr(0, 5);
        resultRunTime=resultRunTime+"s";
    }
    return resultRunTime;
}

void renderVerdictTable(std::vector<TestCase> &testCaseList){
    // Table creator
    std::vector<std::vector<ftxui::Element>> tableContent;
    tableContent.push_back({
        ftxui::text("Name"),
        ftxui::text("Verdict"),
        ftxui::text("Time")
    });
    for(auto currentTestCase: testCaseList){
        std::vector<ftxui::Element> currentRow;
        
        //currentTestCase.name
        currentRow.push_back(
            ftxui::text(currentTestCase.name)
        );

        //currentTestCase.verdict
        currentTestCase.verdict=makeVerdict(currentTestCase);
        currentRow.push_back(
            verdictToElement(currentTestCase.verdict)
        );
        
        //currentTestCase.runTime
        std::string runTime_string=makeVerdictRunTime(currentTestCase.runTime, currentTestCase.isTle);
        currentRow.push_back(
            ftxui::text(runTime_string)
        );
        
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

    return;
}

#endif 