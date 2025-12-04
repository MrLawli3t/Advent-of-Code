#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>

const int N = 1000;

int main() {

    std::array<unsigned int, N> list1, list2;

    std::string filename = "input_2024_01.txt";

    std::ifstream inFile(filename);

    if (!inFile) std::cerr << "Failed to open file";

    for (int i = 0; i < N; i++) {
        int x, y;
        inFile >> x >> y;
        
        list1[i] = x;
        list2[i] = y;
    }

    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());

    unsigned int totalDistance = 0;

    for (int i = 0; i < N; ++i) {
        totalDistance += abs(list1[i]-list2[i]);
    }

    std::cout << totalDistance;

    return 0;
}