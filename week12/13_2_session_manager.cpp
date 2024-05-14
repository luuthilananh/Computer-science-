#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class SessionManager {
private:
    unordered_set<string> activeUsers; // хэш-множество для хранения активных пользователей

public:
   
    void login(const string& username) {
        activeUsers.insert(username); // добавляем 
    }

    void logout(const string& username) {
        activeUsers.erase(username); // удаляем пользователя из множества
    }

    int getNumberOfActiveUsers() const {
        return activeUsers.size(); // возвращаем размер множества
    }
};

int main() {
    SessionManager m;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.login("bob");
    cout << m.getNumberOfActiveUsers() << endl;
    m.login("alice");
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("whoever"); 
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("alice"); 
    cout << m.getNumberOfActiveUsers() << endl;
    m.logout("bob");
    cout << m.getNumberOfActiveUsers() << endl;

    return 0;
}
