#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> find_intersection(int length, vector<int>& sequence1, vector<int>& sequence2) {
    // Преобразуем последовательности в множества для удобства поиска пересечения
    vector<int> set1 = sequence1;
    vector<int> set2 = sequence2;
    
    // Сортируем обе последовательности
    sort(set1.begin(), set1.end());
    sort(set2.begin(), set2.end());
    
    // Создаем вектор для хранения пересечения
    vector<int> intersection;
    
    // Используем алгоритм set_intersection для нахождения пересечения
    set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), back_inserter(intersection));
    
    // Удаляем повторяющиеся элементы
    intersection.erase(unique(intersection.begin(), intersection.end()), intersection.end());
    
    return intersection;
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

    vector<int> intersection = find_intersection(length, sequence1, sequence2);

    for (int num : intersection) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
