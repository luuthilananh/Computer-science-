#include <iostream>
using namespace std;
void findmax();
void findmax()
{
    int n;
    cout << " ";
    cin >> n;
    cout << " " <<endl;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];  
	} 
    int max;
    max = array[0];
    for (int i = 0; i < n; i++) {
        if (array[i] > max){
            max= array[i];
        }    
	} 
    cout << max <<endl; 
}

int main() {
	findmax();
	return 0;
}