#include <iostream>

int main() {
    int n;
    std::cout << "Enter a natural number: ";
    std::cin >> n; // Input a natural number

    std::cout << "Factors of " << n << " are: ";
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            std::cout << i << " "; // If i is a factor of n, print it
        }
    }
    std::cout << std::endl;

    return 0;
}
