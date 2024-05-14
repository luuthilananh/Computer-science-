#include <iostream>
#include <vector>

using namespace std;

// Функция для удаления элементов последовательности, которые больше k
vector<int> remove_greater_than_k(int length, vector<int>& sequence, int k) {
    // Создание вектора для хранения результата
    vector<int> result;

    // Перебор элементов последовательности
    for (int i = 0; i < length; ++i) {
        // Если элемент меньше или равен k, добавляем его в результат
        if (sequence[i] <= k) {
            result.push_back(sequence[i]);
        }
    }

    return result;
}

int main() {
    int length;
    cin >> length;
    vector<int> sequence(length);
    for (int i = 0; i < length; ++i) {
        cin >> sequence[i];
    }

    int k;
    cin >> k;
    vector<int> result = remove_greater_than_k(length, sequence, k);
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
