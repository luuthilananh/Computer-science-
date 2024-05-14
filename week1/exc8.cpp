#include <iostream>

int main() {
    int n;
    std::cout << "Enter the size of the triangle: ";
    std::cin >> n; // Вводим размер треугольника

    // Рисуем треугольник
    for (int i = 1; i <= n; ++i) {
        // В каждой строке выводим i символов '+'
        for (int j = 1; j <= i; ++j) {
            std::cout << "+";
        }
        std::cout << std::endl;
    }

    return 0;
}