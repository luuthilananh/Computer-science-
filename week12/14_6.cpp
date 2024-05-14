#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Функция для сортировки четных элементов по убыванию, а нечетных по возрастанию
vector<int> custom_sort(vector<int>& sequence) {
    // Создаем векторы для хранения четных и нечетных элементов
    vector<int> even, odd;

    // Разделяем последовательность на четные и нечетные элементы
    for (int num : sequence) {
        if (num % 2 == 0) {
            even.push_back(num);
        } else {
            odd.push_back(num);
        }
    }

    // Сортируем четные элементы по убыванию
    sort(even.rbegin(), even.rend());

    // Сортируем нечетные элементы по возрастанию
    sort(odd.begin(), odd.end());

    // Обновляем исходную последовательность с учетом порядка сортировки
    int even_index = 0, odd_index = 0;
    for (int i = 0; i < sequence.size(); ++i) {
        if (sequence[i] % 2 == 0) {
            sequence[i] = even[even_index++];
        } else {
            sequence[i] = odd[odd_index++];
        }
    }

    return sequence;
}

int main() {

    int length;
    cin >> length;

    vector<int> sequence(length);
    for (int i = 0; i < length; ++i) {
        cin >> sequence[i];
    }

    custom_sort(sequence);
    for (int num : sequence) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
