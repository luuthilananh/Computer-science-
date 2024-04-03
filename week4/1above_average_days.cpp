#include <iostream>
#include <vector>

using namespace std;
/*
cout << above_average_days.size() << endl; in ra kich thuoc cua day
for (int day : above_average_days) {cout << day << " ";} cout << endl; in ra day chu y toi for(int i: vector)
  
*/ 
int main() {
    int N;
    cin >> N;

    vector<int> temp(N);
    int sum = 0;

    // Считываем температуры и суммируем их
    for (int i = 0; i < N; ++i) {
        cin >> temp[i];
        sum += temp[i];
    }

    // Вычисляем среднее арифметическое
    int average = sum / N;

    vector<int> above_average_days;

    // Ищем дни, температура в которых выше среднего
    for (int i = 0; i < N; ++i) {
        if (temp[i] > average) {
            above_average_days.push_back(i);
        }
    }

    // Выводим результат
    cout << above_average_days.size() << endl;
    for (int day : above_average_days) {
        cout << day << " ";
    }
    cout << endl;

    return 0;
}
