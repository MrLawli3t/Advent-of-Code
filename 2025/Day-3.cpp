#include "D:\Skrivebord\Advent of Code\stringUtils.hpp"
#include <fstream>
#include <iostream>

int exp(int num, int power) {

    if (power == 0) return 1;

    unsigned long long expNum = num;

    for(int i = 1; i < power; i++) {
        expNum *= expNum;
    }

    return expNum;
}

unsigned long long findMaxJoltage(const std::string& sequence, int batteries) {
    unsigned long long maxJoltage = 0;
    int sortedIndeces[batteries];

    for (int i = 0; i < batteries; i++) {
        int largestNum = -1;
        for (int j = (i > 0 ? sortedIndeces[i-1] + 1 : 0); j < sequence.size()+1-batteries+i; j++) {
            int num = sequence[j] - '0';
            if (num > largestNum) {
                largestNum = num;
                sortedIndeces[i] = j;
            }
        }
    }

    std::string numStr = "";
    for (int index : sortedIndeces) {
        numStr += sequence[index];
    }
    
    maxJoltage = std::stoull(numStr);
    
    return maxJoltage;
}

int main() {
    string filename = "input3.txt";
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return 1;
    }

    string line;
    unsigned long long totalJoltage = 0;

    while (std::getline(inputFile, line)) {
        totalJoltage += findMaxJoltage(line, 12);
    }

    std::cout << totalJoltage << "\n";
}