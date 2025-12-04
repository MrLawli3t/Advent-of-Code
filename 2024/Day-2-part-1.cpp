#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

const int N = 1000;

bool isLineSafe(std::vector<int>& numbers) {
    int dir = numbers.at(0) < numbers.at(1);

    for (int i = 0; i < numbers.size()-1; i++) {
        if ((numbers.at(i) < numbers.at(i+1)) != dir) {
            return false;
        }

        int distance = abs(numbers.at(i) - numbers.at(i+1));
        if (distance < 1 || distance > 3) {
            return false;
        }
    }

    return true;
}

bool isLineSafeWithRemove(std::vector<int>& numbers) {
    for (int i = 0; i < numbers.size(); i++) {
        std::vector<int> tempVector;
        tempVector.reserve(numbers.size());
        for (int j = 0; j < numbers.size(); j++) {
            if (j == i) continue;
            tempVector.emplace_back(numbers.at(j));
        }

        if (isLineSafe(tempVector)) return true;
    }

    return false;
}

int main() {

    std::string filename = "input_2024_02.txt";
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return 1;
    }

    int nSafe;
    std::string line;
    std::vector<int> lineNumbers;
    lineNumbers.reserve(10);

    for (int i = 0; i < N; i++) {
        lineNumbers.clear();
        std::getline(inputFile, line);

        std::istringstream ss(line);

        int num;
        while (ss >> num) {
            lineNumbers.emplace_back(num);
        }

        nSafe += isLineSafeWithRemove(lineNumbers);
    }

    std::cout << nSafe;

    return 0;
}