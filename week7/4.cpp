#include <iostream>
#include <vector>
#include <utility>

class MyClass {
private:
    std::vector<std::pair<int, std::string>> elements;
//list { {"a",10},{"a",20} };
public:
    void addElement(int num, const std::string& str) {
        // Проверяем, есть ли уже такая структура в векторе
        for (const auto& element : elements) {
            if (element.first == num && element.second == str) {
                return; // Если есть - просто выходим
            }
        }
        // Если не нашли такую структуру, добавляем её в вектор
        elements.push_back(std::make_pair(num, str)); // ham make_pair hop hai gia tri nao da xac dinh lai vs nhau; la ham co san chi viec dung
    }

    void printStructures() const {
        for (const auto& element : elements) {
            std::cout << element.first << " " << element.second << std::endl;
        }
    }
};

int main() {
    MyClass obj1;
    obj1.addElement(1, "hello");
    obj1.addElement(2, "hi");
    obj1.addElement(2, "hi");
    obj1.printStructures();
    return 0;
}
