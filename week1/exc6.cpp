#include <iostream>
using namespace std;

int main() {
    int n;
    cout << " ";
    cin >> n;  

    // Check if the entered number is negative
    if (n < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else if (n == 0) {
        // Calculate and output the factorial of n
        cout << "1" << endl;
    } else {
        unsigned long long fact = 1;
        for (int i = 1; i <= n; ++i) {
            fact *= i;
        }
    
        cout << fact << endl;
    }

    return 0;
}