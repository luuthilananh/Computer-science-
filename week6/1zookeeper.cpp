#include <iostream>
#include <string>

using namespace std;

// Объявляем класс Animal
class Animal {
public:
    virtual string getType() = 0;
    virtual bool isDangerous() = 0;
};

// Объявляем класс Monkey, наследуемый от Animal
class Monkey : public Animal {
public:
    string getType() override {
        return "Monkey";
    }

    bool isDangerous() override {
        return false;
    }
};

// Объявляем класс Lion, наследуемый от Animal
class Lion : public Animal {
public:
    string getType() override {
        return "Lion";
    }

    bool isDangerous() override {
        return true;
    }
};

// Объявляем класс ZooKeeper
class ZooKeeper {
private:
    int dangerousCount; // Количество опасных зверей

public:
    ZooKeeper() : dangerousCount(0) {} // Конструктор по умолчанию

    void handleAnimal(Animal* a) { // Метод для обработки зверей
        if (a->isDangerous()) {
            dangerousCount++; // Если зверь опасный, увеличиваем счетчик опасных зверей
        }
    }

    int getDangerousCount() { // Метод для получения количества опасных зверей
        return dangerousCount;
    }
};

int main() {
    ZooKeeper z;
    Monkey* m = new Monkey();
    z.handleAnimal(m);
    delete m;
    Lion* l = new Lion();
    z.handleAnimal(l);
    delete l;
    m = new Monkey();
    z.handleAnimal(m);
    delete m;
    l = new Lion();
    z.handleAnimal(l);
    delete l;
    l = new Lion();
    z.handleAnimal(l);
    delete l;
    l = new Lion();
    z.handleAnimal(l);
    delete l;
    l = new Lion();
    z.handleAnimal(l);
    delete l;
    cout << z.getDangerousCount() << endl;
    return 0;
}
