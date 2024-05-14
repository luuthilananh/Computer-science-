#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Tracker {
private:
    struct UserClicks {
        unsigned long long firstClick = ULLONG_MAX;
        unsigned long long lastClick = 0;
        unsigned long long clickCount = 0;
    };

    unordered_map<string, UserClicks> clickStats;

public:
    void click(const string& username, unsigned long long timestamp) {
        auto& userStats = clickStats[username];
        userStats.clickCount++;
        userStats.firstClick = min(userStats.firstClick, timestamp);
        userStats.lastClick = max(userStats.lastClick, timestamp);
    }

    unsigned long long getClickCount(const string& username) const {
        auto it = clickStats.find(username);
        if (it != clickStats.end()) {
            return it->second.clickCount;
        }
        return 0;
    }

    unsigned long long getFirstClick(const string& username) const {
        auto it = clickStats.find(username);
        if (it != clickStats.end()) {
            return it->second.firstClick;
        }
        return ULLONG_MAX;
    }

    unsigned long long getLastClick(const string& username) const {
        auto it = clickStats.find(username);
        if (it != clickStats.end()) {
            return it->second.lastClick;
        }
        return 0;
    }
};

int main() {
    Tracker t;
    t.click("alice", 1000);
    t.click("bob", 1100);
    t.click("alice", 1001);
    t.click("alice", 1200);
    t.click("alice", 1002);

    cout << t.getClickCount("alice") << endl;
    cout << t.getClickCount("bob") << endl;
    cout << t.getFirstClick("alice") << endl;
    cout << t.getFirstClick("bob") << endl;
    cout << t.getLastClick("alice") << endl;
    cout << t.getLastClick("bob") << endl;

    return 0;
}
