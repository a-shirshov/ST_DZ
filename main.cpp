#include <iostream>
#include <vector>
#include "function/function.h"

struct stat {
    int foundErrCount;
    int totalCount;
};

int main() {
    std::vector<int> Vec = {0,1,1,1};
    std::vector<int> gVec = {1,0,1,1};
    std::vector<int> infVec = Vec;
    for (int i=0; i<3; i++) {
        infVec.push_back(0);
    }
    std::vector<int> tail;
    tail = findTail(infVec,gVec);
    std::vector<int> modVec = infVec;
    for (int i = modVec.size()-3; i < modVec.size(); i++) {
        modVec[i] = tail[i];
    }
    stat* resultStat = new stat[8];
    for(int i =0; i < 8; i++) {
        resultStat[i].foundErrCount = 0;
        resultStat[i].totalCount = 0;
    }
    for (int i=1; i<=127; i++) {
        std::vector <int> errVec = intToVec(i);
        std::vector <int> resVec = sumVec(modVec, errVec);
        int kr = countKr(errVec);
        tail = findTail(errVec,gVec);
        if (!checkEmptyVec(tail)) {
            resultStat[kr].foundErrCount++;
        }
        resultStat[kr].totalCount++;
    }
    for(int i =1; i < 8; i++) {
        std::cout << "Разрядность: " << i << " Число обнаруженных ошибок " << resultStat[i].foundErrCount;
        std::cout << " из возможных " << resultStat[i].totalCount <<" .";
        std::cout << "Процентное соотношение :" << float(resultStat[i].foundErrCount)/float(resultStat[i].totalCount)*100 << "%\n";
    }
    return 0;
}