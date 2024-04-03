#include <iostream>

class Train {
private:
    double mass;
    double velocity;
    double position;

public:
    // Конструктор, создающий паровоз массой m, стоящий в начале координат
    Train(double m) : mass(m), velocity(0), position(0) {}

    // Ехать с текущей скоростью в течение времени dt
    void move(double dt) {
        position += velocity * dt;
    }

    // Изменить полный импульс паровоза (p = mv) на dp
    // Изменение может менять знак скорости
    void accelerate(double dp) {
        velocity += dp / mass;
    }

    // Получить текущую координату паровоза
    double getX() {
        return position;
    }
    /*void set_X(double x){
        this->x = position;
    }*/
};

int main() {
    Train t(10);
    t.accelerate(1); // Скорость стала 0.1
    t.move(1);
    std::cout << "Current X: " << t.getX() << std::endl;
    t.move(1);
    std::cout << "Current X: " << t.getX() << std::endl;
    t.accelerate(-2); // Скорость стала -0.1
    t.move(3);
    std::cout << "Current X: " << t.getX() << std::endl;

    return 0;
}
