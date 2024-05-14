#include <iostream>

using namespace std;  // This line allows you to use elements from the std namespace without prefixing them with "std::"

int main() {
    int n, m;
    cin >> n >> m;  
    
    for (int i = 0; i < m; ++i) {
        cout << "+";
    }
    cout << endl;

    for (int i = 0; i < n - 2; ++i) {
        cout << "+";
        for (int j = 0; j < m - 2; ++j) {
            cout << " ";
        }
        cout << "+" << endl;
    }

    for (int i = 0; i < m; ++i) {
        cout << "+";
    }
    cout << endl;

    return 0;
}
