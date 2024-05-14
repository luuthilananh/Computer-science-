#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <deque>

using namespace std;

class Connection {
public:
    string getSource() const {
        return source;
    }
    unsigned short int getPort() const {
        return port;
    }
    unsigned long long getTimestamp() const {
        return timestamp;
    }
    
    Connection(string source, unsigned short int port, unsigned long long timestamp) : 
        source(source), port(port), timestamp(timestamp) {}

private:
    string source;
    unsigned short int port;
    unsigned long long timestamp;
};

class IntrusionDetector {
public:
    void setTimeThreshold(unsigned short int timeThreshold) {
        this->timeThreshold = timeThreshold;
    }

    void setPortLimit(unsigned short int portLimit) {
        this->portLimit = portLimit;
    }
     // Обработка нового подключения
    void handleConnection(const Connection& c) {
        connections[c.getSource()].insert(c.getPort());
        timestamps[c.getSource()].push_back(c.getTimestamp());

        // Очищаем старые записи из истории подключений
        auto& timestampsForSource = timestamps[c.getSource()];
        while (!timestampsForSource.empty() && c.getTimestamp() - timestampsForSource.front() > timeThreshold) {
            timestampsForSource.pop_front();
        }

        // Проверяем наличие массового сканирования портов
        if (connections[c.getSource()].size() >= portLimit && timestampsForSource.size() >= portLimit) {
            intruders.insert(c.getSource());
        }
    }

    bool isIntruder(const string& source) const {
        return intruders.find(source) != intruders.end();
    }

private:
    unordered_map<string, unordered_set<unsigned short int>> connections;
    unordered_map<string, deque<unsigned long long>> timestamps;
    unordered_set<string> intruders;
    unsigned short int timeThreshold;
    unsigned short int portLimit;
};

int main() {
    IntrusionDetector id;
    id.setTimeThreshold(5);
    id.setPortLimit(3);
    id.handleConnection({"evil.com", 21, 100504});
    id.handleConnection({"evil.com", 22, 100501});
    id.handleConnection({"evil.com", 23, 100502});
    id.handleConnection({"evil.com", 24, 100503});
    id.handleConnection({"evil.com", 25, 100500});
    cout << boolalpha << "Checking if evil.com is intruder: " << id.isIntruder("evil.com") << endl;
    id.handleConnection({"load.com", 80, 100504});
    id.handleConnection({"load.com", 80, 100501});
    id.handleConnection({"load.com", 80, 100502});
    id.handleConnection({"load.com", 80, 100503});
    id.handleConnection({"load.com", 80, 100500});
    cout << boolalpha << "Checking if load.com is intruder: " << id.isIntruder("load.com") << endl;

    return 0;
}
