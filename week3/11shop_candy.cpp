#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Box {
    int price;
    int candies;
};

int main() {
    int N;
    cin >> N;

    vector<Box> boxes(N);

    // Считываем информацию о коробках
    for (int i = 0; i < N; ++i) {
        cin >> boxes[i].price >> boxes[i].candies;
    }

    int S;
    cin >> S;

    // Сортируем коробки по цене за конфеты
    sort(boxes.begin(), boxes.end(), [](const Box& a, const Box& b) {
        return a.price < b.price;
    });

    int bought_boxes = 0;
    int total_candies = 0;
    int remaining_money = S;

    // Покупаем коробки, пока есть деньги
    for (const auto& box : boxes) {
        if (box.price <= remaining_money) {
            bought_boxes++;
            total_candies += box.candies;
            remaining_money -= box.price;
        } else {
            break;
        }
    }

    cout << bought_boxes << " " << total_candies << endl;

    return 0;
}
