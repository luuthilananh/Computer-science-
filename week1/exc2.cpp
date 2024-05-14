#include <iostream>
using namespace std;

int main()
{
    int a;
    cout << "number\n";
    cin >> a;
    if (a % 13 == 0){
        cout << "Yes";
    }
    else{
        cout << "No";
    }

    return 0;   
}

