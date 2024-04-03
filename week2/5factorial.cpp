#include <iostream>
using namespace std;

unsigned long long int factorial(unsigned int n) {
    // Base case: factorial of 0 is 1
    if (n == 0) {
        return 1;
    } 
    unsigned long long fact = 1;

    // Calculate factorial from 1 to n
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    
    return fact;
}

unsigned int sum_of_numbers(unsigned long long int n)
{
 unsigned int res = 0;
 while (n)
 {
 res += n % 10;
 n /= 10;
 }
 return res;
}

int main()
{
    unsigned int n;
    cin >>n;
    cout <<sum_of_numbers(factorial(n)) <<endl;
    //cout << factorial(n) <<endl;
    return 0;
}
