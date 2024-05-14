template<typename T>
class Vector2D {
public:
    Vector2D(T x, T y); // Khai báo hàm constructor template
    void someFunction(const Vector2D<T>& v2); // Tham số là một tham chiếu đến một Vector2D với kiểu dữ liệu T
};

template<typename T>
Vector2D<T>::Vector2D(T x, T y) {
    // Thực hiện logic khởi tạo
}

template<typename T>
void Vector2D<T>::someFunction(const Vector2D<T>& v2) {
    // Thực hiện một số thao tác với v2
}

int main() {
    Vector2D<int> v1(1, 2); // Khởi tạo một Vector2D với kiểu dữ liệu int
    Vector2D<double> v2(1.5, 2.5); // Khởi tạo một Vector2D với kiểu dữ liệu double
    
    v1.someFunction(v2); // Gọi hàm someFunction với đối tượng v2 với kiểu dữ liệu double
    return 0;
}
