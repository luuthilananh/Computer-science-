#include <iostream>
using namespace std;

int main() {
	int a, b;
    cout << "height ";
    cin >> a;
    cout << "width ";
    cin >> b;
	for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
		    cout << "+";
	    }
        cout << "\n";
    }	
	return 0;
}