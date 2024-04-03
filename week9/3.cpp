#include <iostream>
#include <string>

// Определение класса предмета
class Item {
protected:
    std::string title; // Название предмета
    int weight; // Вес предмета
    int level; // Уровень предмета
    bool magical; // Магический ли предмет

public:
    // Создание предмета с указанными параметрами
    Item(std::string title, int weight, int level, bool magical) {
        this->title = title;
        this->weight = weight;
        this->level = level;
        this->magical = magical;
    }

    // Получить вес предмета
    int getWeight() const {
        return weight;
    }

    // Получить уровень предмета
    int getLevel() const {
        return level;
    }

    // Является ли предмет магическим
    int isMagical() const {
        return magical;
    }
};

// Базовый класс игрока
class Player {
protected:
    int strength; // Сила игрока
    int level; // Уровень игрока

public:
    // Создать игрока
    Player() {}

    // Удалить игрока
    virtual ~Player() {}

    // Задать силу игрока
    virtual void setStrength(int strength) final {
        this->strength = strength;
    }

    // Задать уровень игрока
    virtual void setLevel(int level) final {
        this->level = level;
    }

    // Получить силу игрока
    virtual int getStrength() const final {
        return strength;
    }

    // Получить уровень игрока
    virtual int getLevel() const final {
        return level;
    }

    // Проверить, может ли игрок использовать предмет
    virtual bool canUse(const Item& item) const = 0;

    // Может ли игрок колдовать
    virtual bool canCast() const = 0;

    // Проверить, может ли игрок лечить других игроков
    virtual bool canHeal() const {
        return canCast() || getLevel() > 10;
    }
};

// Класс рыцаря
class Knight : public Player {
public:
    // Может ли рыцарь использовать предмет
    bool canUse(const Item& item) const override {
        return !item.isMagical() && getStrength() >= item.getWeight() && getLevel() >= item.getLevel();
    }

    // Может ли рыцарь колдовать
    bool canCast() const override {
        return false;
    }
};

// Класс волшебника
class Wizard : public Player {
public:
    // Может ли волшебник использовать предмет
    bool canUse(const Item& item) const override {
        return getStrength() >= item.getWeight() && getLevel() >= item.getLevel();
    }

    // Может ли волшебник колдовать
    bool canCast() const override {
        return true;
    }
};

int main() {
    // Создание предметов для тестирования
    Item items[3] = {
        Item("Маленький меч", 1, 1, false),
        Item("Большой меч", 5, 3, false),
        Item("Заклинание", 1, 3, true)
    };

    // Создание игроков для тестирования
    Player* players[2];
    players[0] = new Wizard();
    players[0]->setStrength(3);
    players[0]->setLevel(5);
    players[1] = new Knight();
    players[1]->setStrength(6);
    players[1]->setLevel(5);

    // Проверка возможности лечить
    for (int i = 0; i < 2; i++) {
        std::cout << "Can heal: " << players[i]->canHeal() << std::endl;
    }

    // Проверка возможности использования предметов
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "Can use: " << players[i]->canUse(items[j]) << std::endl;
        }
    }

    // Очистка памяти
    for (int i = 0; i < 2; i++) {
        delete players[i];
    }

    return 0;
}
    