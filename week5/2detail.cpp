#include <iostream>

class GasHolder {
private:
    float volume; // Объем газгольдера
    float temperature; // Температура газгольдера в Кельвинах
    float mass; // Масса газа в газгольдере
    float molar_mass; // Молярная масса газа

public:
    GasHolder(float v) : volume(v), temperature(273), mass(0), molar_mass(0) {}

    ~GasHolder() {}

    void inject(float m, float M) {
        float new_mass = mass + m;
        if (new_mass != 0) {
            temperature = (mass * temperature + m * 273) / new_mass;
            mass = new_mass;
            molar_mass = (molar_mass * (mass - m) + M * m) / mass;
        } else {
            temperature = 273; // Если газгольдер пуст, температура остается 273 K
            mass = 0;
            molar_mass = M; // В случае пустого газгольдера сохраняем молярную массу последнего впрыска
        }
    }

    void heat(float dT) {
        temperature += dT;
    }

    void cool(float dT) {
        temperature = (temperature - dT < 0) ? 0 : temperature - dT;
    }

    float getPressure() {
        const float R = 8.31; // Универсальная газовая постоянная в Дж/(моль*К)
        return (mass / molar_mass) * R * temperature / volume;
    }
};

int main() {
    GasHolder h(1.0);
    h.inject(29, 29);
    std::cout << "Pressure after operation: " << h.getPressure() << " Pa" << std::endl;
    h.inject(29, 29);
    std::cout << "Pressure after operation: " << h.getPressure() << " Pa" << std::endl;
    h.heat(273);
    std::cout << "Pressure after operation: " << h.getPressure() << " Pa" << std::endl;
    h.cool(373);
    std::cout << "Pressure after operation: " << h.getPressure() << " Pa" << std::endl;
    h.cool(373);
    std::cout << "Pressure after operation: " << h.getPressure() << " Pa" << std::endl;
    return 0;
}
