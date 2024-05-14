#include <iostream>
#include <cmath>

using namespace std;

class Point {
protected:
    int x;
    int y;
public:
    Point(int x, int y) : x(x), y(y) {}

    Point operator+(const Point& a) const {
        return Point(x + a.x, y + a.y);
    }

    Point operator-(const Point& a) const {
        return Point(x - a.x, y - a.y);
    }

    double dist() const {
        return sqrt(x * x + y * y);
    }
};

class Triangle {
private:
    Point a;
    Point b;
    Point c;
public:
    Triangle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c) {}

    double perimeter() const {
        double ab = (b - a).dist();
        double bc = (c - b).dist();
        double ca = (a - c).dist();
        return ab + bc + ca;
    }
};

int main() {
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    Point a(x1, y1), b(x2, y2), c(x3, y3);

    Triangle t(a, b, c);
    cout << "Triangle perimeter: " << t.perimeter() << endl;

    return 0;
}
