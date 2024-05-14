#include <iostream>

template<typename T>
class Vector2D {
public:
    // Constructors
    Vector2D();
    Vector2D(T x, T y);
    // Destructor
    ~Vector2D();
    // Get coordinates
    T getX() const;
    T getY() const;
    // Set coordinates
    void setX(T x);
    void setY(T y);
    // Overloaded operators
    bool operator== (const Vector2D<T>& v2) const;
    bool operator!= (const Vector2D<T>& v2) const;
    Vector2D<T> operator+ (const Vector2D<T>& v2) const;
    Vector2D<T> operator- (const Vector2D<T>& v2) const;
    Vector2D<T> operator* (const T a) const;
    
private:
    T x_;
    T y_;
};

// Multiplication operator 
template<typename T>
Vector2D<T> operator* (T a, const Vector2D<T>& v);

// Output vector in format (x; y)
template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector2D<T>& v);

// Read vector, reads just two coordinates
template<typename T>
std::istream& operator>>(std::istream& is, Vector2D<T>& v);

// Definitions of member functions
template<typename T>
Vector2D<T>::Vector2D() : x_(0), y_(0) {}

template<typename T>
Vector2D<T>::Vector2D(T x, T y) : x_(x), y_(y) {}

template<typename T>
Vector2D<T>::~Vector2D() {}

template<typename T>
T Vector2D<T>::getX() const {
    return x_;
}

template<typename T>
T Vector2D<T>::getY() const {
    return y_;
}

template<typename T>
void Vector2D<T>::setX(T x) {
    x_ = x;
}

template<typename T>
void Vector2D<T>::setY(T y) {
    y_ = y;
}

template<typename T>
bool Vector2D<T>::operator==(const Vector2D<T>& v2) const {
    return (x_ == v2.x_) && (y_ == v2.y_);
}

template<typename T>
bool Vector2D<T>::operator!=(const Vector2D<T>& v2) const {
    return !(*this == v2);
}

template<typename T>
Vector2D<T> Vector2D<T>::operator+(const Vector2D<T>& v2) const {
    return Vector2D<T>(x_ + v2.x_, y_ + v2.y_);
}

template<typename T>
Vector2D<T> Vector2D<T>::operator-(const Vector2D<T>& v2) const {
    return Vector2D<T>(x_ - v2.x_, y_ - v2.y_);
}

template<typename T>
Vector2D<T> Vector2D<T>::operator*(const T a) const {
    return Vector2D<T>(x_ * a, y_ * a);
}

template<typename T>
Vector2D<T> operator*(T a, const Vector2D<T>& v) {
    return v * a;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector2D<T>& v) {
    return os << "(" << v.getX() << "; " << v.getY() << ")";
}

template<typename T>
std::istream& operator>>(std::istream& is, Vector2D<T>& v) {
    T x, y;
    is >> x >> y;
    v.setX(x);
    v.setY(y);
    return is;
}

int main() {
    Vector2D<int> v1;
    std::cin >> v1;
    std::cout << "Read vector: " << v1 << std::endl;
    std::cout << "Vector multiplied by 42: " << v1 * 42 << std::endl;
    
    Vector2D<double> v2;
    std::cin >> v2;
    std::cout << "Read vector: " << v2 << std::endl;
    std::cout << "Vector multiplied by 42: " << v2 * 42 << std::endl;
    
    return 0;
}
