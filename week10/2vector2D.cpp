#include <iostream>

using namespace std;

class Vector2D {
private:
    int x;
    int y;

public:
    Vector2D() : x(0), y(0) {}

    Vector2D(int x, int y) : x(x), y(y) {}

    ~Vector2D() {}

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void setX(int x) {
        this->x = x;
    }

    void setY(int y) {
        this->y = y;
    }

    bool operator== (const Vector2D& v2) const {
        return (x == v2.x && y == v2.y);
    }

    bool operator!= (const Vector2D& v2) const {
        return (x != v2.x || y != v2.y);
        //return !(*this == v2);
    }

    Vector2D operator+ (const Vector2D& v2) const {
        return Vector2D(x + v2.x, y + v2.y);
    }

    Vector2D operator- (const Vector2D& v2) const {
        return Vector2D(x - v2.x, y - v2.y);
    }

    Vector2D operator* (const int a) const {
        return Vector2D(x * a, y * a);
    }
};

Vector2D operator* (int a, const Vector2D& v) {
    return Vector2D(v.getX() * a, v.getY() * a);
}

ostream& operator<<(ostream& os, const Vector2D& v) {
    os << "(" << v.getX() << "; " << v.getY() << ")";
    return os;
}
istream& operator>>(istream &is, Vector2D &v) {
    int x, y;
    is >> x >> y;
    v.setX(x);
    v.setY(y);
    return is;
}

int main() {
    Vector2D v1;
    cin >> v1;
    cout << v1 << endl;

    Vector2D v2;
    cin >> v2;
    cout << v2 << endl;

    cout << boolalpha << (v1 == v2) << endl;
    cout << boolalpha << (v1 != v2) << endl;

    Vector2D v3 = v1 - v2;
    cout << v3 << endl;
    cout << v3 * 42 << endl;
    cout << 42 * v3 << endl;

    return 0;
}
