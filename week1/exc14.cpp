#include <iostream> 
using namespace std; 
  
// function to convert decimal to binary 
void decToBin(int n) 
{ 
    int binNum[32];  
    int i = 0;
    int coutnum = 0; 
    while (n > 0) { 
        binNum[i] = n % 2;
        coutnum ++; 
        n = n / 2; 
        i++; 
    } 
  
    // Выводим все единицы
    for (int i = coutnum - 1; i >= 0; --i) {
        if (binNum[i] == 1){
            cout << binNum[i];
        }
    }
    // Выводим все нули
    for (int i = coutnum - 1; i >= 0; --i) {
        if (binNum[i] == 0){
            cout << binNum[i];
        }
    }  
} 
  
int main() 
{ 
    int n;
    cout << " ";
    cin >> n; 
    decToBin(n); 
    return 0; 
}