#include <iostream>

int main() {
    char ch;
    int count = 0;

    std::cout << "Enter a sequence of 0s and 1s (enter any other character to finish):\n";
    
    // Читаем символы с экрана, пока не будет введен любой другой символ
    while (std::cin >> ch && (ch == '0' || ch == '1')) {
        // Если введенный символ - '1', увеличиваем счетчик
        if (ch == '1') {
            count++;
        }
    }

    // Выводим количество единиц
    std::cout << "Number of ones: " << count << std::endl;

    return 0;
}