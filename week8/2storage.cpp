#include <iostream>

class Storage {
protected:
    unsigned int size;
    int* data;

public:
    // Конструктор хранилища размерности n
    Storage(unsigned int n) : size(n) {
        // Cấp phát bộ nhớ cho mảng data có kích thước là n
        data = new int[size];
    }

    // Деструктор
    //Чтобы гарантировать отсутствие утечек памяти,написать деструктор, который освобождает выделенную память при уничтожении объекта.
    //Để đảm bảo không có rò rỉ bộ nhớ, ta cần viết destructor để giải phóng bộ nhớ đã cấp phát khi đối tượng bị hủy. 
    virtual ~Storage() {
        delete[] data;
    }

    // Получение размерности хранилища
    unsigned getSize() {
        return size;
    }

    // Получение значения i-го элемента из хранилища
    int getValue(unsigned int i) {
        return data[i];
    }

    // Задание значения i-го элемента из хранилища равным value
    void setValue(unsigned int i, int value) {
        data[i] = value;
    }
};

// Класс TestStorage, наследуется от реализации Storage
class TestStorage : public Storage {
protected:
    int* more_data;

public:
    // Конструктор, выделяющий память
    TestStorage(unsigned int n) : Storage(n) {
        more_data = new int[n];
    }

    // Деструктор, освобождающий память
    ~TestStorage() override {
        delete[] more_data;
    }
};

int main() {
    // Создание объекта TestStorage и его удаление
    Storage* ts = new TestStorage(42);
    delete ts;

    return 0;
}
