#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <unordered_map>

const int N = 1000;

int main() {

    std::array<unsigned int, N> list1, list2;

    std::string filename = "AOC_2024_01_input.txt";

    std::ifstream inFile(filename);

    if (!inFile) std::cerr << "Failed to open file";

    for (int i = 0; i < N; i++) {
        int x, y;
        inFile >> x >> y;
        
        list1[i] = x;
        list2[i] = y;
    }

    std::unordered_map<int, int> freqs;
    freqs.reserve(N);

    for (int i : list2) {
        freqs[i]++;
    }

    unsigned int simScore = 0;

    for (int i : list1) {
        simScore += i*freqs[i];
    }

    std::cout << simScore;

    return 0;
}