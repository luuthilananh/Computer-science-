#include <iostream>
#include <cctype> // Для функции isdigit и isalpha
using namespace std;

unsigned long get_a_hexadecimal() {
    unsigned long num = 0;
    char c;
    while (true) {
        cin.get(c); // Считываем символ из потока ввода
        if (c == ' ' || c == '\n') { // Проверяем на конец ввода
            break;
        }
        if (isdigit(c)) { // Если символ - цифра
            num = num * 16 + (c - '0');
        } else if (isalpha(c)) { // Если символ - буква
            c = toupper(c); // Преобразуем в верхний регистр
            if (c >= 'A' && c <= 'F') {
                num = num * 16 + (c - 'A' + 10);
            } else { // Некорректный символ
                return 0;
            }
        } else { // Некорректный символ
            return 0;
        }
    }
    return num;
}

int main() {
    //cout << "Enter a hexadecimal number: ";
    cout << get_a_hexadecimal() << endl;
    return 0;
}
