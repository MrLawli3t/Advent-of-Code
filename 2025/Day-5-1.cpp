#include "D:\Skrivebord\Advent of Code\stringUtils.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>

constexpr int lines = 1175;
using ull = unsigned long long;

int main() {
    string filename = "input5.txt";
    std::ifstream inputFile(filename);

    if (!inputFile) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return 1;
    }

    string line;
    bool isRanges = true;
    std::vector<std::pair<ull, ull>> ranges;

    int freshCount = 0;

    while (std::getline(inputFile, line)) {
        if (line.empty()) {
            isRanges = false;
            continue;
        }
        if (isRanges) {
            std::vector<string> parts = string_util::splitString(line, '-');
            ull start = std::stoull(parts[0]);
            ull end = std::stoull(parts[1]);
            ranges.emplace_back(start, end);
            continue;
        }

        ull ingredientID = std::stoull(line);
    
        for (const auto& [rangeStart, rangeEnd] : ranges) {
            if (ingredientID >= rangeStart && ingredientID <= rangeEnd) {
                freshCount++;
                break;
            }
        }
    }

    std::cout << "Total fresh ingredients: " << freshCount << std::endl;
    return 0;
}