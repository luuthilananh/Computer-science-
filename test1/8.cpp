#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int median(const vector<int>& values) {
    vector<int> sortVal = values;
    sort(sortVal.begin(), sortVal.end());
    int n = sortVal.size();
    return (n % 2 == 0) ? sortVal[n / 2 - 1] : sortVal[n / 2];
}

int main() {
    int N;
    cin >> N;

    map<string, vector<int>> cal;

    for (int i = 0; i < N; ++i) {
        string sensor;
        int value;
        cin >> sensor >> value;
        cal[sensor].push_back(value);
    }

    int M;
    cin >> M; 

    for (int i = 0; i < M; ++i) {
        string sensor;
        cin >> sensor;
        if (cal.find(sensor) != cal.end()) {
            
            cout << median(cal[sensor]) << endl;
        } else {
            
            cout << "no data" << endl;
        }
    }

    return 0;
}
