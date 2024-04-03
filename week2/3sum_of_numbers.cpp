#include <iostream>
using namespace std;
//tinh tong cac chu so trong 1 so
unsigned int sum_of_numbers(unsigned int n){
    int res = 0;
    while (n)
    {
        int number = n % 10;
        res = res + number;
        n /= 10;
    }
    return res;
}

int main()
{
    unsigned int n;
    cin >>n;
    cout <<sum_of_numbers(n) <<endl;
    return 0;
}