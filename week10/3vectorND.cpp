#include <iostream>
#include <vector>

using namespace std;

class VectorN {
private:
    vector<int> values;
    unsigned int size;

public:
    VectorN(unsigned int n) : size(n) {
        values.resize(n);
    }

    ~VectorN() {}

    unsigned int getSize() const {
        return size;
    }

    int getValue(unsigned int i) const {
        return values[i];
    }

    void setValue(unsigned int i, int value) {
        values[i] = value;
    }

    bool operator== (const VectorN& v2) const {
        if (size != v2.size)
            return 0;
            //return false;
        for (unsigned int i = 0; i < size; ++i) {
            if (values[i] != v2.values[i])
                return 0;
                //return false;
        }
        //return true;
        return 1;
    }

    bool operator!= (const VectorN& v2) const {
        return !(*this == v2);
    }

    VectorN operator+ (const VectorN& v2) const {
        VectorN result(size);
        for (unsigned int i = 0; i < size; ++i) {
            result.setValue(i, values[i] + v2.values[i]);
        }
        return result;
    }

    VectorN operator* (const int a) const {
        VectorN result(size);
        for (unsigned int i = 0; i < size; ++i) {
            result.setValue(i, values[i] * a);
        }
        return result;
    }

    friend VectorN operator* (int a, const VectorN& v) {
        return v * a;
    }
};

int main() {
    VectorN a(4);
    a.setValue(0, 0);
    a.setValue(1, 1);
    a.setValue(2, 2);
    a.setValue(3, 3);

    VectorN b(4);
    b.setValue(0, 0);
    b.setValue(1, -1);
    b.setValue(2, -2);
    b.setValue(3, -3);

    cout << boolalpha << (a == b) << endl;
    cout << boolalpha << (a != b) << endl;

    VectorN c = a + b;
    VectorN d = 5 * c;

    for (unsigned int i = 0; i < a.getSize(); ++i)
        cout << d.getValue(i) << endl;

    return 0;
}
