#include <iostream>
#include <vector>


using namespace std;

class Car {
protected:
    bool allowsBoarding; // Разрешена ли посадка пассажиров
    bool allowsLoading; // Разрешена ли погрузка грузов
    unsigned int numberOfSeats; // Количество мест для пассажиров
    unsigned int numberOfContainers; // Количество контейнеров для грузов

public:
    // Конструктор класса Car
    Car(bool allowsBoarding, bool allowsLoading, unsigned int numberOfSeats, unsigned int numberOfContainers) : 
        allowsBoarding(allowsBoarding),
        allowsLoading(allowsLoading),
        numberOfSeats(numberOfSeats),
        numberOfContainers(numberOfContainers){}
    
    ~Car() {}

   // Метод, определяющий, разрешена ли посадка пассажиров
    bool isBoardingAllowed() const {
        return allowsBoarding;
    }

    // Метод, определяющий, разрешена ли погрузка грузов
    bool isLoadingAllowed() const {
        return allowsLoading;
    }

    // Метод, возвращающий количество мест для пассажиров
    unsigned int getNumberOfSeats() const {
        return numberOfSeats;
    }

    // Метод, возвращающий количество контейнеров для грузов
    unsigned int getNumberOfContainers() const {
        return numberOfContainers;
    }
};
 
class ConvoyManager{
private:
    vector<Car> convoy;// Вектор для хранения машин в колонне


public:
// Метод для регистрации новой машины в колонне
    void registerCar(const Car& c) {
        convoy.push_back(c);
    } 
    // Метод для получения общего количества мест для пассажиров в колонне
    unsigned int getTotalSeats() const{
        unsigned int totalSeats=0;
        for(const auto& i : convoy){
            if (i.isBoardingAllowed()) {
                totalSeats += i.getNumberOfSeats();
            }
        }
        return totalSeats;
    } 
    // Метод для получения общего количества контейнеров для грузов в колонне
    unsigned int getTotalContainers() const{
        unsigned int totalContainers=0;
        for(const auto& j : convoy){
            if (j.isLoadingAllowed()){
                totalContainers += j.getNumberOfContainers();
            }
        }
        return totalContainers;
    }     
};

int main() {
    ConvoyManager cm; // Создание экземпляра класса ConvoyManager
    // Создание объектов класса Car для тестирования
    Car c1(true, false, 12, 3);
    cm.registerCar(c1);
    Car c2(false, true, 12, 3);
    cm.registerCar(c2);
    Car c3(true, true, 12, 3);
    cm.registerCar(c3);
    Car c4(false, false, 12, 3);
    cm.registerCar(c4);

    // Вывод общего количества мест и контейнеров в колонне
    std::cout << "Total available seats: " << cm.getTotalSeats() << std::endl;
    std::cout << "Total available containers: " << cm.getTotalContainers() << std::endl;

    return 0;
}