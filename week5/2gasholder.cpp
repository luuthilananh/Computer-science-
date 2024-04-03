#include <iostream>
#include <cmath>

class GasHolder {
private:
    float volume; // объём
    float mol; // число моли газа
    float temp; // температура
    const float R = 8.31; // постоянная газа

public:
    // Создать газгольдер заданного объёма.
    // Температура созданного термостата равна 273 К.
    GasHolder(float v) : volume(v), mol(0), temp(273) {}

    // Уничтожить газгольдер.
    ~GasHolder() {}

    // Впрыск порции газа массой m и молярной массой M.
    // Считать, что газ принимает текущую температуру газгольдера за пренебрежимо малое время.
    void inject(float m, float M) {
        mol += m/M;
    }

    // Подогреть газгольдер на dT градусов.
    // Считать, что нагрев возможен до любых значений температуры.
    void heat(float dT) {
        temp += dT;
    }

    // Охладить газгольдер на dT градусов.
    // При попытке охладить ниже 0 К температура становится ровно 0 К.
    void cool(float dT) {
        temp = std::max(0.0f, temp - dT);
    }

    // Получить текущее давление в газгольдере.
    // Считать, что для газа верно уравнение состояния PV = (m/M)RT.
    float getPressure() {
        return (mol * R * temp) /(volume);
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
