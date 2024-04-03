#include <iostream>
using namespace std;
// do {...} while(..);
bool is_a_number(char c){
    return c >= '0' && c <= '9';      
}

int main()
{
    char c;
    unsigned int sum = 0;
    do
    {
        cin >>c;
        if (is_a_number(c))
        sum += c - '0';// dang o chu(char) can chuyen thanh so(int)
    } while (c != '$');
    cout <<sum <<endl;
    return 0;
}
