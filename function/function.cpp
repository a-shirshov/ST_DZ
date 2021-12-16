#include "function.h"
#include <iostream>

void printVec(std::vector<int>Vec) {
    for (int i = 0; i < Vec.size(); i++) {
        std::cout << Vec[i];
    }
    std::cout << std::endl;
}

std::vector<int> findTail(std::vector<int>InfVec, std::vector<int>gVec) {
    for (int i=0; i<4; i++) {
        if (InfVec[i] == 0) {
            continue;
        }

        for(int j=0; j<4; j++) {
            InfVec[i+j] = InfVec[i+j] ^ gVec[j];
        }
    }
    return InfVec;
}

std::vector <int> intToVec(int number) {
    std::vector<int> result;
    int bin = 64;
    while (bin != 0) {
        if ((number / bin) == 0) {
            result.push_back(0);
        } else {
            result.push_back(1);
            number -= bin;
        }
        bin /= 2;
    }
    return result;
}

std::vector <int> sumVec(std::vector<int>firstVec, std::vector<int>secondVec) {
    std::vector <int> result;
    for (int i =0; i < firstVec.size(); i++) {
        result.push_back(firstVec[i] ^ secondVec[i]);
    }
    return result;
}

bool checkEmptyVec (std::vector<int>firstVec) {
    for (int i =0; i < firstVec.size(); i++) {
        if (firstVec[i] != 0) {
            return false;
        }
    }
    return true;
}

int countKr (std::vector<int> Vec) {
    int counter = 0;
    for (int i =0; i < Vec.size(); i++) {
        if (Vec[i] == 1) {
            counter++;
        }
    }
    return counter;
}