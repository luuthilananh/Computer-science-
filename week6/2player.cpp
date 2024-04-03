#include <iostream>
#include <string>

using namespace std;

// Объявляем класс Item (cong cu)
class Item {
private:
    string title;
    int weight;
    int level;
    bool magical;

public:
    Item(string title, int weight, int level, bool magical) : title(title), weight(weight), level(level), magical(magical) {}

    int getWeight() {
        return weight;
    }

    int getLevel() {
        return level;
    }

    bool isMagical() {
        return magical;
    }
};

// Объявляем класс Player (ng choi)
class Player {
protected:
    int strength;
    int level;

public:
    Player() {}

    virtual ~Player() {}

    void setStrength(int strength) {
        this->strength = strength;
        
    }

    void setLevel(int level) {
        this->level = level;
    }

    int getStrength() {
        return strength;
    }

    int getLevel() {
        return level;
    }

    virtual bool canUse(Item* item) = 0;
};

// Объявляем класс Knight(hiep si), унаследованный от Player(phap su)
class Knight : public Player {
public:
    bool canUse(Item* item) override {
        // Рыцарь может использовать только немагические предметы
        // и только если его сила не меньше веса предмета
        // и его уровень не меньше уровня предмета
        return !item->isMagical() && strength >= item->getWeight() && level >= item->getLevel();
    }
};

// Объявляем класс Wizard, унаследованный от Player
class Wizard : public Player {
public:
    bool canUse(Item* item) override {
        // Волшебник может использовать магические и немагические предметы
        // и только если его сила не меньше веса предмета
        // и его уровень не меньше уровня предмета
        return strength >= item->getWeight() && level >= item->getLevel();
    }
};

int main() {
    // Создаем предметы
    Item* items[3];
    items[0] = new Item("Small sword", 1, 1, false);
    items[1] = new Item("Big sword", 5, 3, false);
    items[2] = new Item("Ward", 1, 3, true);

    // Создаем игроков
    Player* players[2];
    players[0] = new Wizard();
    players[0]->setStrength(3);
    players[0]->setLevel(5);
    players[1] = new Knight();
    players[1]->setStrength(6);
    players[1]->setLevel(5);

    // Проверяем, может ли каждый игрок использовать каждый предмет
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 3; j++) {
            cout << "Can use: " << players[i]->canUse(items[j]) << endl;
            //1 he can use this item, 0 he can't use this item
        }
    }

    // Освобождаем выделенную память
   for (int i = 0; i < 3; i++) {
        delete items[i];
    }

    for (int i = 0; i < 2; i++) {
        delete players[i];
    }

    return 0;
}

/*override ghi de len ham virtual*/
/*private: 
are only accessible within the class itself, cannot be accessed from outside the class, not even by derived classes(lop dan xuat).*/
/*example of derived classes
class BaseClass {
protected:
    int protectedVar;
};

class DerivedClass : public BaseClass { //derived classes
public:
    void derivedFunction() {
        protectedVar = 5; // Accessible within derived class
    }
};*/

/*public:
Members declared as public are accessible from any part of the program.*/
/*protected:
Members declared as protected are accessible within the class itself and by derived classes.*/