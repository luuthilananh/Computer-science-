#include <iostream>
using namespace std;
 // doc input 1 array; in ra 1 day
// Print array elements greater than average
void aboveAvg(int arr[], int n)
{
    // Find average
    double avg = 0;
    for (int i = 0; i < n; i++) 
        avg += arr[i];    
        avg = avg / n;
 
    // Print elements greater than average
    for (int i = 0; i < n; i++) 
        if (arr[i] > avg) 
            cout << arr[i] << " ";
}
 
// Driver program 
int main()
{
    int n, arr[1000];
    cin >> n;
    for (int i = 0; i < n; ++i){
        cin >> arr[i];
    }
    aboveAvg(arr, n);
    return 0;
}