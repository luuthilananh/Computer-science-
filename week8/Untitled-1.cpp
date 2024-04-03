#include<isotream>

class Car{
protected:
    bool allowesBoarding;
    bool allowesLoading;
    unsigned int numberOfSeats;
    unsigned int numberOfContainers;
public:
    Car(bool allowesBoarding, bool allowesLoading, unsigned int numberOfSeats, unsigned int 
    numberOfContainers) {
        this->allowesBoarding = allowesBoarding;
        this->allowesLoading = allowesLoading;
        this->numberOfSeats = numberOfSeats;
        this->numberOfContainers = numberOfContainers;
    }
    
    ~Car() {}
    bool isBoardingAllowed() const {
    return allowesBoarding;
    }
    bool isLoadingAllowed() const {
    return allowesLoading;
    }
    unsigned int getNumberOfSeats() const {
    return numberOfSeats;
    }
    unsigned int getNumberOfContainers() const {
    return numberOfContainers;
    }
};    
class ConvoyManager{
public:
    // Зарегистрировать новую машину в колонне
    void registerCar(const Car& c);
    // Сообщить, сколько всего пассажиров может принять колонна
    unsigned int getTotalSeats() const;
    // Сообщить, сколько всего грузовых контейнеров может взять колонна
    unsigned int getTotalContainers() const;
};
    При регистрации машины необходимо учитывать не только её ёмкость, но и готова ли она 
    вообще брать пассажиров и грузы.
    Для тестирования можете использовать следующую реализацию класса Car:

    
    Car c1(true, false, 12, 3);
    cm.registerCar(c1);
    Car c2(false, true, 12, 3);
    cm.registerCar(c2);
    Car c3(true, true, 12, 3);
    cm.registerCar(c3);
    Car c4(false, false, 12, 3);
    cm.registerCar(c4);
    cout << "Total available seats: " << cm.getTotalSeats() << endl;
    cout << "Total available containers: " << cm.getTotalContainers() << endl;