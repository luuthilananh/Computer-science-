#include <iostream>
#include <vector>

// Định nghĩa lớp Car
class Car {
protected:
    bool allowsBoarding; // Cho phép chở khách
    bool allowsLoading; // Cho phép chở hàng
    unsigned int numberOfSeats; // Số ghế
    unsigned int numberOfContainers; // Số container

public:
    // Constructor của lớp Car
    Car(bool allowsBoarding, bool allowsLoading, unsigned int numberOfSeats, unsigned int numberOfContainers) {
        this->allowsBoarding = allowsBoarding;
        this->allowsLoading = allowsLoading;
        this->numberOfSeats = numberOfSeats;
        this->numberOfContainers = numberOfContainers;
    }
    ~Car() {}
    // Phương thức kiểm tra xem có cho phép chở khách không
    bool isBoardingAllowed() const {
        return allowsBoarding;
    }

    // Phương thức kiểm tra xem có cho phép chở hàng không
    bool isLoadingAllowed() const {
        return allowsLoading;
    }

    // Phương thức trả về số ghế
    unsigned int getNumberOfSeats() const {
        return numberOfSeats;
    }

    // Phương thức trả về số container
    unsigned int getNumberOfContainers() const {
        return numberOfContainers;
    }
};

// Lớp ConvoyManager để quản lý việc tổ chức đội xe
class ConvoyManager {
private:
    std::vector<Car> convoy; // Vector để lưu trữ các xe trong đội xe

public:
    // Phương thức để đăng ký một xe mới vào đội xe
    void registerCar(const Car& c) {
        convoy.push_back(c);
    }

    // Phương thức để lấy tổng số ghế có sẵn trong đội xe
    unsigned int getTotalSeats() const {
        unsigned int totalSeats = 0;
        for (const auto& car : convoy) {
            totalSeats += car.getNumberOfSeats();
        }
        return totalSeats;
    }

    // Phương thức để lấy tổng số container có sẵn trong đội xe
    unsigned int getTotalContainers() const {
        unsigned int totalContainers = 0;
        for (const auto& car : convoy) {
            totalContainers += car.getNumberOfContainers();
        }
        return totalContainers;
    }
};

int main() {
    ConvoyManager cm; // Tạo một đối tượng ConvoyManager
    // Tạo các đối tượng Car để kiểm tra
    Car c1(true, false, 12, 3);
    cm.registerCar(c1);
    Car c2(false, true, 12, 3);
    cm.registerCar(c2);
    Car c3(true, true, 12, 3);
    cm.registerCar(c3);
    Car c4(false, false, 12, 3);
    cm.registerCar(c4);

    // In ra tổng số ghế và container có sẵn trong đội xe
    std::cout << "Tổng số ghế có sẵn: " << cm.getTotalSeats() << std::endl;
    std::cout << "Tổng số container có sẵn: " << cm.getTotalContainers() << std::endl;

    return 0;
}
