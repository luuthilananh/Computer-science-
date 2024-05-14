#include <iostream>

// Function to calculate the factorial of a natural number
unsigned long long factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0) {
        return 1;
    }
    
    // Initialize the factorial to 1
    unsigned long long fact = 1;

    // Calculate factorial from 1 to n
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    
    return fact;
}

int main() {
    int n;
    std::cout << "Enter a natural number: ";
    std::cin >> n;  // Input a natural number

    // Check if the entered number is negative
    if (n < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        // Calculate and output the factorial of n
        std::cout << "Factorial of " << n << " is: " << factorial(n) << std::endl;
    }

    return 0;
}