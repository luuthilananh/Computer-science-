#include <iostream>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false; // 1 and negative numbers are not prime
    }
    for (int i = 2; i < num; ++i) {
        if (num % i == 0) {
            return false; // Found a divisor, the number is not prime
        }
    }
    return true; // The number is prime
}

// Function to find the nth prime number
int nthPrime(int n) {
    int count = 0; // Counter for prime numbers
    int num = 2; // Start checking from 2 (the first prime number)
    while (true) {
        if (isPrime(num)) {
            ++count; // Increment the counter if the number is prime
            if (count == n) {
                return num; // Return the nth prime number
            }
        }
        ++num; // Move to the next number to check
    }
}

int main() {
    int n;
    std::cout << "Enter a natural number: ";
    std::cin >> n; // Input the position of the prime number

    // Find the nth prime number and output the result
    std::cout << "The " << n << "-th prime number is: " << nthPrime(n) << std::endl;

    return 0;
}
