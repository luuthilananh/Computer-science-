#include <iostream>
#include <cmath>

using namespace std;

class Rational {
private:
    int a;   // Числитель
    int b; // Знаменатель

public:
    // Конструктор дроби
    Rational(int a, int b) : a(a), b(b) {}

    // Оператор сложения двух дробей
    Rational operator+(const Rational& other) const {
        return Rational(a * other.b + other.a * b, b * other.b);
    }

    // Оператор вычитания двух дробей
    Rational operator-(const Rational& other) const {
        return Rational(a * other.b - other.a * b, b * other.b);
    }

    // Оператор умножения двух дробей
    Rational operator*(const Rational& other) const {
        return Rational(a * other.a, b * other.b);
    }

    // Оператор деления двух дробей
    Rational operator/(const Rational& other) const {
        return Rational(a * other.b, b * other.a);
    }

    // Оператор умножения дроби на целое число (должно работать при любом порядке операндов)
    friend Rational operator*(int x, const Rational& r) {
        return Rational(x * r.a, r.b);
    }

    // Оператор вывода
    friend ostream& operator<<(ostream& os, const Rational& r) {
        os << r.a << "/" << r.b;
        return os;
    }
};

int main() {
    Rational a(1, 2);
    Rational b(1, 3);
    cout << a << endl;
    cout << b << endl;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    cout << a / b << endl;
    cout << 3 * a << endl;
    cout << 4 * b << endl;
    return 0;
}
