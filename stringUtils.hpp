#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

namespace string_util {

    static vector<string> splitString(const string& str, char delimiter) {
        vector<string> tokens;
        std::istringstream ss(str);
        string token;

        while (std::getline(ss, token, delimiter)) {
            tokens.emplace_back(token);
        }

        return tokens;
    }

    static void print(const vector<string>& vec) {
        for (const auto& item : vec) {
            std::cout << item << "\n";
        }
        std::cout << "\n";
    }

    static void print(const vector<unsigned long long>& vec) {
        for (const auto& item : vec) {
            std::cout << "Printing: " << item << "\n";
        }
        std::cout << "\n";
    }

    static string repeatString(const string& str, int times) {
        string result;
        for (int i = 0; i < times; i++) {
            result += str;
        }
        return result;
    }
}