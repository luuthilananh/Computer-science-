#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Функция для нахождения пересечения двух последовательностей
vector<int> find_intersection(int length, vector<int>& sequence1, vector<int>& sequence2) {
    unordered_map<int, int> count_map; // Хранение количества каждого элемента во второй последовательности // Lưu số lần xuất hiện của mỗi phần tử trong chuỗi thứ hai

    // Подсчет количества каждого элемента во второй последовательности  // Đếm số lần xuất hiện 
    for (int i = 0; i < length; ++i) {
        count_map[sequence2[i]]++;
    }

    vector<int> intersection; // Хранение элементов пересечения // Lưu phần tử giao nhau

    // Поиск элементов пересечения и добавление их в результирующий вектор // Tìm phần tử giao nhau và thêm chúng vào vector kết quả
    for (int i = 0; i < length; ++i) {
        if (count_map.find(sequence1[i]) != count_map.end() && count_map[sequence1[i]] > 0) {
            intersection.push_back(sequence1[i]);
            count_map[sequence1[i]]--; // Уменьшение количества // Giảm số lần xuất hiện
        }
    }

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
