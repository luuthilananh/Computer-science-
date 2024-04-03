#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Функция для вывода дел на конкретный день
void dump(const vector<vector<string>>& schedule, int day) {
    cout << schedule[day - 1].size(); //day-1 thu tu cua ngay day trong thang do la day nen nos bat dau tu khong
    for (const auto& task : schedule[day - 1]) {
        cout << " " << task;
    }
    cout << endl;
}

int main() {
    const int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> current_month(31); // Вектор для хранения списка дел на каждый день текущего месяца
    int q;
    cin >> q;

    int current_day = 1;
    int current_month_index = 0;

    for (int i = 0; i < q; ++i) {
        string oper; //operation
        cin >> oper;

        if (oper == "ADD") {   //дело с названием s на день i текущего месяца.
            int day;
            string task;
            cin >> day >> task;
            current_month[day - 1].push_back(task);
        } else if (oper == "DUMP") { //Вывести все дела, запланированные на день i текущего месяца
            int day;
            cin >> day;
            dump(current_month, day);
        } else if (oper == "NEXT") {  //Перейти к списку дел на новый месяц.
            int next_month_index = (current_month_index + 1) % 12;
            int days_current_month = days_in_month[current_month_index];
            int days_next_month = days_in_month[next_month_index];

            if (days_next_month < days_current_month) {
                for (int j = days_next_month; j < days_current_month; ++j) {
                    current_month[days_next_month - 1].insert(
                        end(current_month[days_next_month - 1]),
                        begin(current_month[j]),
                        end(current_month[j])
                    );
                }
            }

            current_month.resize(days_next_month);
            current_day = min(current_day, days_next_month);
            current_month_index = next_month_index;
        }
    }

    return 0;
}
