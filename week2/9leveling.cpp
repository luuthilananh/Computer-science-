#include <iostream>
using namespace std;
//cin.get(c); char c;
char leveling(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - ('A' - 'a'); // Convert uppercase to lowercase
    } else {
        return c; // Return the character unchanged if it's not uppercase
    }
}

int main() {
    char c;
    do {
        cin.get(c);
        cout << leveling(c);
    } while (c != '\n');
    cout << endl;
    return 0;
}



/* Since  in ASCII lowercase letters come after uppercase letters in ASCII, For example, 'A' - 'a' equals -32.
 if c is 'B', then 'B' - ('A' - 'a') is equivalent to 'B' - (-32), which is equivalent to 'B' + 32, resulting in 'b' */
 /*Поскольку строчные буквы идут после прописных, разница между кодами ASCII соответствующих букв положительна. Например, 'A' - 'a' даст -32.*/