#include <iostream>
using namespace std;

int stolen_apples(int Vv, int Vm, int L, int K, int N) {
    while (K > 0) {
        // Вова бежит до тех пор, пока не доберется до забора или киберпес не догонит его
        int Vovas_move = min(Vv, K); // расстояние, которое может пробежать Вова за один ход
        K -= Vovas_move;
        L -= Vovas_move;
        if (L <= 0) {
            // Киберпес догнал Вову
            return N;
        }
        // Если они на одной клетке или киберпес впереди, Вова скидывает мешок и продолжает бежать
        if (L <= K || L <= Vm) {
            N -= 1;
            L = K; // киберпес догоняет Вову, поэтому расстояние сбрасывается до 0
        }
    }
    return N;
}

int main() {
    int Vv, Vm, L, K, N;
    cin >> Vv >> Vm >> L >> K >> N;
    // Вызов функции и вывод результата
    int result = stolen_apples(Vv, Vm, L, K, N);
    if (result == 0) {
        cout << "DAY LA VI DU" << endl;
    } else {
        cout << result << endl;
    }
    return 0;
}
