#include <iostream> 
using namespace std; 
  
// function to convert decimal to binary 
void decToBin(int n) 
{ 
    int binNum[32];  
    int i = 0; 
    while (n > 0) { 
  
        // storing remainder in binary array 
        binNum[i] = n % 2; 
        n = n / 2; 
        i++; 
    } 
  
    // printing in reverse order 
    for (int j = i - 1; j >= 0; j--) 
        cout << binNum[j]; 
} 
  
// Driver program to test above function 
int main() 
{ 
    int n;
    cout << " ";
    cin >> n; 
    decToBin(n); 
    return 0; 
}