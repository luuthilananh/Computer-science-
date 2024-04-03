#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> non_negative;
    vector<int> negative_abs;

    // Чтение и разделение чисел на два вектора: неотрицательные и отрицательные
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        if (num >= 0)
            non_negative.push_back(num);
        else
            negative_abs.push_back(num);
    }

    // Сортировка неотрицательных чисел по возрастанию
    sort(non_negative.begin(), non_negative.end());

    // Сортировка отрицательных чисел по возрастанию модуля
    sort(negative_abs.begin(), negative_abs.end(), [](int a, int b) {
        return abs(a) < abs(b);
    });

    // Вывод отсортированных чисел через пробел
    for (int num : non_negative)
        cout << num << " ";
    for (int num : negative_abs)
        cout << num << " ";

    return 0;
}



/* void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
Compare comp:determines the order in which the elements are going to be sorted. */
