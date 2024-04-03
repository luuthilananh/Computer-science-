#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int Q;
    cin >> Q;

    vector<bool> queue; // Вектор для хранения состояния каждого человека в очереди: true - беспокоится, false - спокоен

    for (int i = 0; i < Q; ++i) {
        string oper;
        cin >> oper;//operation

        if (oper == "WORRY") {
            int pers; //person
            cin >> pers;
            queue[pers] = true; // Помечаем человека как беспокоящегося
        } else if (oper == "QUIET") {
            int pers;
            cin >> pers;
            queue[pers] = false; // Помечаем человека как успокоившегося
        } else if (oper == "COME") {
            int k;
            cin >> k;
            if (k > 0) {
                queue.resize(queue.size() + k, false); // Добавляем k спокойных человек в конец очереди
            } else {
                k = -k;
                queue.resize(queue.size() - k); // Убираем k человек из конца очереди
            }
        } else if (oper == "WORRY_COUNT") {
            int worry_count = 0;
            for (bool is_worried : queue) {
                if (is_worried) {
                    worry_count++;
                }
            }
            cout << worry_count << endl; // Выводим количество беспокоящихся людей в очереди
        }
    }

    return 0;
}
