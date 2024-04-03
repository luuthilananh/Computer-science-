#include <iostream>
using namespace std;
//dang nhi phan cua so thap phan(array, for nguoc)
void binary(unsigned int n){
    //array
    int binary[32];  
    int i = 0;
    if (n == 0){
        cout << n;
    }
    else {
        while (n > 0) { 
        // storing remainder in binary array 
        binary[i] = n % 2; 
        n = n / 2; 
        i++; 
        } 
  
        // printing in reverse order 
        for (int j = i - 1; j >= 0; j--) 
            cout << binary[j];

    }
    
}
int main()
{
    unsigned int n;
    cin >>n;
    binary(n);
    cout <<endl;
    return 0;
}
