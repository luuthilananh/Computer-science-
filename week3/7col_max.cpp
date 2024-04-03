#include <iostream>
#include <vector>

using namespace std;
/*vector<vector<int>> matrix(n, vector<int>(m)); // Объявляем матрицу размером n x m
    for (int i = 0; i < n; ++i) {for (int j = 0; j < m; ++j) {cin >> matrix[i][j];}} nhap ma tran hai chieu vao vector 
    
    */
int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m)); // Объявляем матрицу размером n x m

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    int max_sum = 0; 

    int max_col_idx = -1; // Номер столбца с максимальной суммой

    // Проходим по каждому столбцу
    for (int col = 0; col < m; ++col) {
        int col_sum = 0; 
        for (int row = 0; row < n; ++row) {
            col_sum += matrix[row][col];
            
        }
        // Проверяем, является ли текущая сумма максимальной
        if (col_sum > max_sum) {
            max_sum = col_sum;
            max_col_idx += 1; 
           //cout << max_sum << " " << max_col_idx << endl;
           }
    }
    cout << max_col_idx << endl;

    return 0;
}
