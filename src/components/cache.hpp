#ifndef cache
#define cache

#include "../global/allheader.hpp"

void clearCache(){
    std::vector<std::string> removeList={"program", "main"};
    for(auto filePath: removeList){
        if(std::filesystem::exists(filePath)){
            std::filesystem::remove(filePath);
        }
    }
    return;
}

#endif