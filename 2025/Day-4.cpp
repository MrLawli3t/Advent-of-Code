#include <iostream>
#include <fstream>
#include "D:\Skrivebord\Advent of Code\stringUtils.hpp"

constexpr int gridSize = 136;

 void printBoard(char array[gridSize][gridSize]) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            std::cout << array[i][j];
        }
        std::cout << '\n';
    }
}

bool isAccessible(const char grid[gridSize][gridSize], int row, int col) {
    int total = 0;
    int count = 0;

    for (int i = -1; i <= 1; i++) {
        int selectedRow = row+i;
        if (selectedRow < 0) continue;
        if (selectedRow >= gridSize) continue;
        for (int j = -1; j <= 1; j++) {
            int selectedCol = col+j;
            if (selectedCol < 0) continue;
            if (selectedCol >= gridSize) continue;
            if (i == 0 && j == 0) continue;

            if (grid[selectedRow][selectedCol] != '@') continue;
            count++;
        }
    }

    return count < 4;
}

int main() {
    string filename = "input4.txt";
    std::ifstream inputFile(filename);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file " << filename << std::endl;
        return 1;
    }

    char c;
    char grid[gridSize][gridSize];
    char debugGrid[gridSize][gridSize];
    int row = 0;
    int col = 0;

    while (inputFile.get(c)) {
        if (c == '\n') {
            row++;
            col = 0;
            continue;
        }
        grid[row][col] = c;
        col++;
    }

    unsigned int numAccessible = 0;
    unsigned int removedItems = 0;

    do {
        removedItems = 0;
        for (int i = 0; i < gridSize; ++i) {
            for (int j = 0; j < gridSize; ++j) {
                if (grid[i][j] == '@' && isAccessible(grid, i, j)) {
                    grid[i][j] = 'x';
                    ++removedItems;
                    ++numAccessible;
                }
            }
        }

        std::cout << removedItems << "\n";
    } while (removedItems > 0);

    std::cout << numAccessible;
}