#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 vector<int> max_elements; -> max_elements.size()  kich thuoc cua day dc goi bang ham .size()
 max_elements.push_back(arr[i]); them 1 so vao cuoi day cua vector
 find(vec.rbegin(), vec.rend(), value); tim so dau tien trong vector cos gtri la value
 min_element(elements.begin(), elements.end()); tim so nho nhat trong day elements
*/

void removeLValue(vector<int>& vec, int value) {
    auto it = find(vec.rbegin(), vec.rend(), value); // Find the first occurrence of the value from the end
    if (it != vec.rend()) { // Check if the value is found
        vec.erase(it.base()); // Erase the value at the found position
    }
}
/*void removeFValue(vector<int>& vec, int value) {
    auto it = find(vec.begin(), vec.end(), value); // Find the first occurrence of the value
    if (it != vec.end()) { 
        vec.erase(it); 
    }
}*/


int main() {
    int n, m;   
    cin >> n;
    
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cin >> m;

    vector<int> max_elements; // Вектор для хранения m наибольших элементов

    // Проходим по всем элементам массива
    for (int i = 0; i < n; ++i) {
        // Если количество наибольших элементов меньше m, добавляем текущий элемент в вектор
        if (max_elements.size() < m) {
            max_elements.push_back(arr[i]);
        } else {
            // Иначе находим наименьший из наибольших элементов
            auto min_max = min_element(max_elements.begin(), max_elements.end());
            // Если текущий элемент больше наименьшего из наибольших, заменяем его
            if (arr[i] > *min_max) {
                removeLValue(max_elements, *min_max);
                max_elements.push_back(arr[i]);

            }
            
            /*for (int i = 0; i < m; ++i) {
                cout << max_elements[i] << " ";
            }
            cout << endl;*/
        }
    }  
    
    for (int i = 0; i < m; ++i) {
        cout << max_elements[i] << " ";
    }
    cout << endl;

    return 0;
}
