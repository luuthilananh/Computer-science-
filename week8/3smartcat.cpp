#include <iostream>

// Интерфейс зверушки
class Animal {
public:
    // Погладить данную зверушку.
    virtual void pet() = 0;
    virtual ~Animal() {};
};

// Интерфейс NPC
class NPC {
public:
    // Поговорить с NPC.
    virtual void talk() = 0;
    virtual ~NPC() {};
};

// Класс SmartCat, который реализует оба интерфейса
class SmartCat : public Animal, public NPC {
public:
    // Переопределение метода pet() для вывода "Meow!"
    void pet() override {
        std::cout << "Meow!" << std::endl;
    }

    // Переопределение метода talk() для вывода "Meow!"
    void talk() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    // Пример использования класса SmartCat
    Animal *a = new SmartCat(); // cap phat bo nho
    a->pet();
    delete a; // xoa bo nho da dc cap phat

    NPC *n = new SmartCat();
    n->talk();
    delete n;

    return 0;
}
