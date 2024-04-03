#include <iostream>
#include <vector>
using namespace std;
/*cin >> n >> m; 
cin.ignore(); chuyen sang 1 dong khac trc khi doc tiep hang thu hai dung trong vong lap for
vector<vector<char>> picture(n, vector<char>(m)); tao ra n vector moi vector co m so
cach de input day tren
*/

int main() {
    int n, m;
    cin >> n >> m;

    // Создаем вектор векторов для хранения "картинки"
    vector<vector<char>> picture(n, vector<char>(m));

    // Считываем "картинку" с экрана cin.ignore( n, delim); n so ki tu trich xuat, delim ki tu phan tach can tim
    for (int i = 0; i < n; ++i) {
        cin.ignore(); // Игнорируем символ новой строки перед чтением каждой строки
        for (int j = 0; j < m; ++j) {
            cin.get(picture[i][j]);
        }
    }

    // Поворачиваем "картинку" на pi/2 против часовой стрелки и выводим на экран
    //Rotated picture (counterclockwise by pi/2)
    for (int j = m - 1; j >= 0; --j) {
        for (int i = 0; i < n; ++i) {
            cout << picture[i][j];
        }
        cout << endl;
    }

    return 0;
}
