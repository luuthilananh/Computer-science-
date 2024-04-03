#include <iostream>
#include <cctype> // Для функции isxdigit
using namespace std;

unsigned long get_really_any_hexadecimal() {
    unsigned long num = 0;
    char c;
    bool foundHex = false; // Флаг для обнаружения хотя бы одной шестнадцатеричной цифры

    while (cin.get(c)) {
        if (c == ' ' || c == '\n') { // Проверяем на конец ввода
            break;
        }
        if (isxdigit(c)) { // Если символ является шестнадцатеричной цифрой
            foundHex = true; // Устанавливаем флаг
            if (isdigit(c)) { // Если символ - цифра
                num = num * 16 + (c - '0');
            } else { // Если символ - буква A-F или a-f
                c = toupper(c); // Преобразуем в верхний регистр
                num = num * 16 + (c - 'A' + 10);
            }
        }
    }

    if (!foundHex) { // Если не было обнаружено ни одной шестнадцатеричной цифры
        num = 0;
    }

    return num;
}

int main() {
    //cout << "Enter a hexadecimal number: ";
    cout << get_really_any_hexadecimal() << endl;
    return 0;
}
