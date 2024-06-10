#include <iostream>
#include <string>
#include <vector>

bool isLargeDigit(char digit) {
    return digit >= '6' && digit <= '9';
}

bool isLargeNumber(const std::string& num) {
    for (char digit : num) {
        if (!isLargeDigit(digit)) {
            return false;
        }
    }
    return true;
}

bool canBeSumOfLargeNumbers(const std::string& num) {
    int n = num.size();
    for (int i = 1; i < n; ++i) {
        std::string part1 = num.substr(0, i);
        std::string part2 = num.substr(i);
        if (isLargeNumber(part1) && isLargeNumber(part2)) {
            return true;
        }
    }
    return false;
}

int main() {
    int testcases;
    std::cin >> testcases;

    for(int i = 0; i<testcases; i++) {
        std::string userInput;
        std::cin >> userInput;

        if (canBeSumOfLargeNumbers(userInput)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}
