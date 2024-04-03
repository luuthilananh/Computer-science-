#include <iostream>
#include <cctype> // Для функции isalpha()
using namespace std;

char get_a_letter() {
    char c;
    while (true) {
        cin.get(c); // Считываем символ из потока ввода
        if (isalpha(c)) { // Проверяем, является ли символ буквой
            return c; // Если буква, возвращаем символ
        }
    }
}
char unleveling(char c)
{
    if (c >= 'a' && c <= 'z')
    c += 'A' - 'a';
    return c;
}
int main() {
    for (int i = 0; i < 10; i++) {
        cout << (char)unleveling(get_a_letter()); // Преобразуем считанную букву в прописную и выводим
    }
    cout << endl;
    return 0;
}
