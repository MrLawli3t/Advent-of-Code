#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "D:\Skrivebord\Advent of Code\stringUtils.hpp"

using std::vector;
using std::string;

unsigned long long invalidIdsSum = 0;

// Part 1
vector<unsigned long long> findInvalidIds(unsigned long long lower, unsigned long long upper) {
    vector<unsigned long long> invalidIds;
    string idStr;

    for (unsigned long long id = lower; id <= upper; id++) {
        idStr = std::to_string(id);

        if (idStr.size() % 2 != 0) {
            continue;
        }
        
        if (idStr.substr(0, idStr.size()/2) == idStr.substr(idStr.size()/2)) {
            invalidIds.emplace_back(id);
            invalidIdsSum += id;
        }
    }

    return invalidIds;
}

// Part 2
vector<unsigned long long> findInvalidIdsExtended(unsigned long long lower, unsigned long long upper) {
    vector<unsigned long long> invalidIds;
    string idStr;

    for (unsigned long long id = lower; id <= upper; id++) {
        idStr = std::to_string(id);
        int parts = 2;

        while (parts <= idStr.size()) {
            if (idStr.size() % parts != 0) {
                parts++;
                continue;
            }

            bool isInvalidID = true;
            string partStr = idStr.substr(0, idStr.size()/parts);
            
            if (string_util::repeatString(partStr, parts) == idStr) {
                invalidIds.emplace_back(id);
                invalidIdsSum += id;
                std::cout << "Found one: " << id << " with parts: " << parts << "\n";
                goto outer;
            }

            parts++;
        }
        outer:;
    }

    return invalidIds;
}

int main() {
    string filename = "input2.txt";
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return 1;
    }

    string line;

    std::getline(inputFile, line);

    vector<string> ranges = string_util::splitString(line, ',');

    for (const string& range : ranges) {
        vector<string> bounds = string_util::splitString(range, '-');
        if (bounds.size() != 2) {
            std::cerr << "Error: Invalid range format: " << range << std::endl;
            continue;
        }

        unsigned long long lower = std::stoull(bounds[0]);
        unsigned long long upper = std::stoull(bounds[1]);

        findInvalidIdsExtended(lower, upper);
    }

    std::cout << "Sum of invalid IDs: " << invalidIdsSum << std::endl;

    return 0;
}