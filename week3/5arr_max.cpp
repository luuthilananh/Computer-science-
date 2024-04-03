#include <iostream>
#include <vector>
#include <algorithm> // Для функции sort
using namespace std;


/*tao vector<int> arr(n);
sort(arr.begin(), arr.end()); sap xep mang theo thu tu tang dan
*/
int main() {
    int n, m;
    cin >> n;

    // Создаем массив и считываем элементы
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cin >> m;
    // Сортируем массив по возрастанию
    sort(arr.begin(), arr.end());

    // Выводим m последних элементов отсортированного массива (наибольшие элементы)
    
    for (int i = n - m; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
