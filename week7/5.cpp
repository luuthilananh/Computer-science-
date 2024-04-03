#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

class MyClass {
private:
    std::vector<std::pair<int, std::string>> elements;

public:
    void addElement(int num, const std::string& str) {
        // Проверяем, есть ли уже такая структура в векторе
        for (const auto& element : elements) {
            if (element.first == num && element.second == str) {
                return; // Если есть - просто выходим
            }
        }
        // Если не нашли такую структуру, добавляем её в вектор
        elements.push_back(std::make_pair(num, str));
    }

    void printStructures() const {
        for (const auto& element : elements) {
            std::cout << element.first << " " << element.second << std::endl;
        }
    }

    MyClass& operator+=(const MyClass& other) {
        // Добавляем только те элементы из other, которых ещё нет в текущем объекте
        for (const auto& element : other.elements) {
            if (std::find(elements.begin(), elements.end(), element) == elements.end()) {
                elements.push_back(element);
            }
        }
        return *this;
    }
};

int main() {
    MyClass obj1;
    obj1.addElement(1, "hi");
    obj1.addElement(2, "hello");
    obj1.addElement(2, "hello");
    
    MyClass obj2;
    obj2.addElement(3, "hey");
    obj2.addElement(4, "pop");
    obj2.addElement(2, "hello");
    obj2.addElement(5, "hello");
    
    obj1 += obj2;
    obj1.printStructures();
    
    return 0;
}
