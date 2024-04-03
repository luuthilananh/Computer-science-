#include <iostream>
using namespace std;

unsigned long long int fibonacci(unsigned int n) {
    if (n <= 1){
        return n;
    }
    unsigned long long int fib[n + 1];
    fib[1] = 0;
    fib[2] = 1;
    for (unsigned int i = 3; i <= n; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    return fib[n];
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
    cout <<sum_of_numbers(fibonacci(n)) <<endl;
    //cout << fibonacci(n) <<endl;
    return 0;
}

