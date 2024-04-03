#include <iostream>
#include <cstring> // for memset
using namespace std;
// dat 1 vi tri bat ki trong day la vi tri dau tien cua day  memset(a, 0, sizeof(a)); a[8]=1
unsigned long long int nonacci(unsigned int n) {
    if (n < 8)
        return 0;
    else if (n == 8)
        return 1;
    
    unsigned long long int nona[n + 1];
    // Инициализируем массив нулем - Initialize the array to zero
    memset(nona, 0, sizeof(nona));

    nona[8] = 1;
    for (unsigned int i = 9; i <= n; ++i) {
        for (unsigned int j = 8; j <= i-1; ++j) {
            nona[i] += nona[j];
        }
    }
    return nona[n];
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
 cout <<sum_of_numbers(nonacci(n)) <<endl;
 //cout <<nonacci(n) <<endl; 
 return 0;
}