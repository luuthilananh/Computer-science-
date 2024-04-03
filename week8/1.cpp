#include <iostream>

//SU DUNG CAC KHONG GIAN TEN (NAMESPACE) KHAC NHAU DE TAO RA CAC LOP(CLASS) KHAC NHAU NHUNG COS CUNG 1 TEN 
//пример использования различных пространств имен для создания разных классов с одним и тем же именем 
// Подключение пространств имен для эмулируемых сторонних библиотек
namespace namespaceA {
    class Engine {
    public:
        void run() {
            std::cout << "EngineA run" << std::endl;
        }
    };
}

namespace namespaceB {
    class Engine {
    public:
        void run() {
            std::cout << "EngineB run" << std::endl;
        }
    };
}

namespace namespaceC {
    class Engine {
    public:
        void run() {
            std::cout << "EngineC run" << std::endl;
        }
    };
}

// Определение класса MyEngine
class MyEngine {
private:
    namespaceA::Engine engineA;  //(::) là để chỉ định rõ ràng cho trình biên dịch rằng Engine là thành viên của namespaceA. 
    namespaceB::Engine engineB;
    namespaceC::Engine engineC;

public:
    // Метод run, который вызывает метод run нужного Engine-а
    //SWITCH-CASE-DEFAULT (number= 1,2,3) chọn và chạy một trong ba động cơ khác nhau (engineA-num1, engineB-num2, hoặc engineC-num3) dựa trên giá trị của number mà chúng ta truyền vào.
    void run(unsigned int number) {
        switch (number) {
            case 1:
                engineA.run();
                break;
            case 2:
                engineB.run();
                break;
            case 3:
                engineC.run();
                break;
            default:
                // Ничего не делаем для остальных случаев
                break;
        }
    }
};

// Пример использования
int main() {
    MyEngine e;
    e.run(1); // вызов run из Engine-а из библиотеки A
    e.run(2); // вызов run из Engine-а из библиотеки B
    e.run(3); // вызов run из Engine-а из библиотеки C
    e.run(10); // ничего не происходит
    return 0;
}
