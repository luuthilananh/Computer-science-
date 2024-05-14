#include <iostream>
#include <vector>

int main() {
    int length;
    std::cin >> length; // Вводим длину последовательности
    std::vector<int> sequence(length); // Создаем вектор для хранения последовательности

    // Вводим саму последовательность
    for (int i = 0; i < length; ++i) {
        std::cin >> sequence[i];
    }

    // Выводим последовательность на экран в обратном порядке
    for (int i = length - 1; i >= 0; --i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
