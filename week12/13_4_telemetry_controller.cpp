#include <iostream>
#include <string>
#include <unordered_map>
#include <limits>

using namespace std;

class TelemetryController {
private:
    unordered_map<string, pair<long, long>> deviceStats;
    unordered_map<string, unsigned int> eventCounts;

public:
    void handleEvent(const string& device, long value) {
        auto& stats = deviceStats[device];
        stats.first = min(stats.first, value);
        stats.second = max(stats.second, value);
        eventCounts[device]++;
    }

    unsigned int getEventsCount(const string& device) const {
        auto it = eventCounts.find(device);
        if (it != eventCounts.end()) {
            return it->second;
        }
        return 0;
    }

    long getMinValue(const string& device) const {
        auto it = deviceStats.find(device);
        if (it != deviceStats.end()) {
            return it->second.first;
        }
        return numeric_limits<long>::max(); // Возвращаем максимальное значение типа long
    }

    long getMaxValue(const string& device) const {
        auto it = deviceStats.find(device);
        if (it != deviceStats.end()) {
            return it->second.second;
        }
        return numeric_limits<long>::min(); // Возвращаем минимальное значение типа long
    }
};

int main() {
    TelemetryController tc;
    tc.handleEvent("d1", 42);
    tc.handleEvent("d1", -42);
    tc.handleEvent("d2", 100);

    cout << "Events count for d1: " << tc.getEventsCount("d1") << endl;
    cout << "Min value for d1: " << tc.getMinValue("d1") << endl;
    cout << "Max value for d1: " << tc.getMaxValue("d1") << endl;

    return 0;
}
