#include <iostream>
#include <cmath>

int main() {
    int n;
    std::cout << "Enter an odd natural number: ";
    std::cin >> n; // Input an odd natural number

    // Check if n is odd
    if (n % 2 == 0) {
        std::cout << "Please enter an odd number." << std::endl;
        return 1; // Exit with error
    }

    // Upper half of the diamond
    for (int i = 0; i < n / 2 + 1; ++i) {
        for (int j = 0; j < n / 2 - i; ++j) {
            std::cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            std::cout << "+";
        }
        std::cout << std::endl;
    }

    // Lower half of the diamond
    for (int i = n / 2 - 1; i >= 0; --i) {
        for (int j = 0; j < n / 2 - i; ++j) {
            std::cout << " ";
        }
        for (int j = 0; j < 2 * i + 1; ++j) {
            std::cout << "+";
        }
        std::cout << std::endl;
    }

    return 0;
}
