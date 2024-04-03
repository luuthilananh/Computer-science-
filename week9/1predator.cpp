#include <iostream>

// Базовый класс Animal
class Animal
{
protected:
    double mass; // масса
    double speed; // скорость

public:
    Animal() {} // Конструктор по умолчанию
    virtual ~Animal() {} // Виртуальный деструктор

    // Создание зверя с заданной массой и скоростью
    Animal(double mass, double speed)
    {
        this->mass = mass;
        this->speed = speed;
    }
    /*Animal(double mass, double speed):mass(mass),speed(speed){}*/

    // Получить массу зверя
    virtual double getMass() const // получить массу зверя
    {
        return mass;
    }

    // Получить скорость зверя
    virtual double getSpeed() const // получить скорость зверя
    {
        return speed;
    }

    // Может ли зверушка нападать на других зверей
    // (не может, зверь мирный)
    virtual bool canAtack() const // Может ли зверушка нападать на других зверей
    {
        return false;
    }

    // Съесть другого зверя, не делает ничего, мы же мирные
    virtual void eat(const Animal& a) {} // Съесть другого зверя, не делает ничего, мы же мирные
};

// Класс Predator, наследующий от базового класса Animal, описывающий хищника
class Predator : public Animal
{
public:
    Predator(double mass, double speed) : Animal(mass, speed) {}

    // Перегрузка метода canAtack для возврата true (хищник атаковать других зверей может)
    bool canAtack() const override // Может ли хищник атаковать других зверей
    {
        return true;
    }

    // Перегрузка метода eat, реализующая логику поедания другого зверя
    void eat(const Animal& a) override // Поглотить другого зверя
    {
        // Если переданный зверь больше или быстрее хищника, то ничего не происходит
        if (a.getMass() > mass || a.getSpeed() > speed)
        {
            return;
        }
        // Если переданный зверь не больше и не быстрее хищника, то масса хищника увеличивается на массу переданного зверя
        else
        {
            mass += a.getMass();
        }
    }
};

int main()
{
    // Пример базового тестирования реализации класса
    Animal* predator = new Predator(1, 10);
    std::cout << "Current mass: " << predator->getMass() << std::endl;
    if (predator->canAtack())
    {
        predator->eat(Animal(2, 1)); // Этого не съедим - слишком большой
        std::cout << "Current mass: " << predator->getMass() << std::endl;
        predator->eat(Animal(1, 1)); // А вот этого вполне
        std::cout << "Current mass: " << predator->getMass() << std::endl;
        predator->eat(Animal(1, 20)); // Этого не выйдет - слишком быстрый
        std::cout << "Current mass: " << predator->getMass() << std::endl;
        predator->eat(Animal(2, 2)); // А вот этого догоним
        std::cout << "Current mass: " << predator->getMass() << std::endl;
    }
    delete predator;

    return 0;
}
