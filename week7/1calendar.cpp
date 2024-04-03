#include <iostream>

class CalendarData {
private:
    int day;
    int month;
    int year;

public:
    // Конструктор с параметрами
    CalendarData(int d, int m, int y) : day(d), month(m), year(y) {}

    // Деструктор
    ~CalendarData() {
        std::cout << day << "." << month << "." << year << std::endl;
    }
};

int main() {
    // Примеры использования класса CalendarData
    CalendarData data1(5, 8, 2005);
    CalendarData data2(15, 12, 2012);
    CalendarData data3(3, 3, 333);

    return 0;
}
