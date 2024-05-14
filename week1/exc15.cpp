#include <iostream>

int main() {
    char ch;
    int digitCount = 0;

    std::cout << "Enter characters (type '@' to end input):\n";

    // Считываем символы с клавиатуры до появления символа '@'
    while (std::cin >> ch && ch != '@') {
        // Проверяем, является ли символ цифрой
        if (ch >= '0' && ch <= '9') {
            digitCount++; // Увеличиваем счетчик цифр
        }
    }

    // Выводим количество введенных цифр
    std::cout << digitCount << std::endl;

    return 0;
}
