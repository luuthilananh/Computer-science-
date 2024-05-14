#include <iostream>
using namespace std;


int LCM( int a, int b, int c);

int main() {
    int a, b, c;
    cout << "Enter a, b, c: ";
    cin >> a >> b >> c;
    cout << "LCM: " << LCM(a, b,c);
    
    return 0;
}


int LCM( int a, int b, int c) {
     // find the greatest number of three munbers
     int greater, lcm;
     greater = (a > b && a > c ) ? a : ((b > c) ? b : c);

     // run anđ find lcm
     while (true) {
        if (greater%a == 0 && greater%b == 0 && greater%c == 0){
            lcm = greater;
            break;
        }
        ++greater;
     } 
}