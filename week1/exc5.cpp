#include <iostream>

int main() {
    int n, m;
    std::cin >> n >> m;  // Вводим размеры n и m

    // Верхняя горизонтальная граница
    for (int i = 0; i < m; ++i) {
        std::cout << "+";
    }
    std::cout << std::endl;

    // Боковые границы и пробелы внутри
    for (int i = 0; i < n - 2; ++i) {
        std::cout << "+";
        for (int j = 0; j < m - 2; ++j) {
            std::cout << " ";
        }
        std::cout << "+" << std::endl;
    }

    // Нижняя горизонтальная граница
    for (int i = 0; i < m; ++i) {
        std::cout << "+";
    }
    std::cout << std::endl;

    return 0;
}
