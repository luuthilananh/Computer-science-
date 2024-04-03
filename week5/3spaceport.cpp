#include <iostream>
#include <vector>
using namespace std;

class SpacePort {
private:
    vector<bool> docks; // Вектор для хранения состояния доков (занят/свободен)

public:
    // Конструктор, инициализирующий космодром с указанным количеством доков
    SpacePort(unsigned int size) : docks(size, false) {} //все доки свободны.

    // Метод для запроса посадки в указанный док
    bool requestLanding(unsigned int dockNumber) {
        if (dockNumber >= docks.size() || docks[dockNumber]) {
            return false; // Док не существует или занят
        }
        docks[dockNumber] = true; // Док становится занятым
        return true;
    }

    // Метод для запроса взлёта из указанного дока
    bool requestTakeoff(unsigned int dockNumber) {
        if (dockNumber >= docks.size() || !docks[dockNumber]) {
            return false; // Док не существует или свободен
        }
        docks[dockNumber] = false; // Док становится свободным
        return true;
    }
};

int main() {
    SpacePort s(5);
    cout << boolalpha << s.requestLanding(0) << endl;
    cout << boolalpha << s.requestLanding(4) << endl;
    cout << boolalpha << s.requestLanding(5) << endl;
    cout << boolalpha << s.requestTakeoff(0) << endl;
    cout << boolalpha << s.requestTakeoff(4) << endl;
    cout << boolalpha << s.requestTakeoff(5) << endl;

    return 0;
}
