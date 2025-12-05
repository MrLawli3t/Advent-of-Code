#include "D:\Skrivebord\Advent of Code\stringUtils.hpp"
#include <fstream>
#include <iostream>
#include <unordered_map>
#include <algorithm>

constexpr int lines = 1175;
using ull = unsigned long long;

std::vector<std::pair<ull, ull>> sanitizeRanges(const std::vector<std::pair<ull, ull>>& ranges) {
    if (ranges.empty()) return {};

    std::vector<std::pair<ull, ull>> sortedRanges = ranges;
    std::sort(sortedRanges.begin(), sortedRanges.end());

    std::vector<std::pair<ull, ull>> mergedRanges;
    mergedRanges.reserve(sortedRanges.size());
    mergedRanges.push_back(sortedRanges[0]);

    for (size_t i = 1; i < sortedRanges.size(); i++) {
        auto& lastRange = mergedRanges.back();
        const auto& currentRange = sortedRanges[i];

        if (currentRange.first <= lastRange.second + 1) {
            lastRange.second = std::max(lastRange.second, currentRange.second);
        } else {
            mergedRanges.push_back(currentRange);
        }
    }

    return mergedRanges;
}

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

    unsigned long long freshCount = 0;

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

        break;
    }

    std::vector<std::pair<ull, ull>> sanitizedRanges = sanitizeRanges(ranges);
    
    for (const auto& [first, second] : sanitizedRanges) {
        freshCount += (second - first + 1);
        if (freshCount < 1) {
            std::cout << "OVERFLOW" << "\n";
        }
    }

    std::cout << "Total fresh ingredients: " << freshCount << std::endl;
    return 0;
}