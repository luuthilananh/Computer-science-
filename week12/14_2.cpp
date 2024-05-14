#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool can_reorder(int length, vector<int>& sequence1, vector<int>& sequence2) {
    // Преобразуем последовательности в множества для удобства сравнения
    vector<int> set1 = sequence1;
    vector<int> set2 = sequence2;
    
    // Сортируем обе последовательности
    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());
    
    // Если отсортированные последовательности одинаковы, то одну можно получить из другой перестановкой элементов
    return set1 == set2;
}

int main() {
    int length;
    cin >> length;

    vector<int> sequence1(length);
    vector<int> sequence2(length);
    for (int i = 0; i < length; ++i) {
        cin >> sequence1[i];
    }
    for (int i = 0; i < length; ++i) {
        cin >> sequence2[i];
    }

    bool result = can_reorder(length, sequence1, sequence2);

    cout << boolalpha << result << endl;

    return 0;
}
