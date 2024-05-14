#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Animal {
public:
    virtual string getType() const = 0;
    virtual ~Animal() {}
};

class ZooKeeper {
private:
    unordered_map<string, int> animalCounts;

public:
    ZooKeeper() {}

    void handleAnimal(const Animal& a) {
        animalCounts[a.getType()]++;
    }

    int getAnimalCount(const string& type) const {
        auto it = animalCounts.find(type);
        if (it != animalCounts.end()) {
            return it->second;
        }
        return 0;
    }
};

class Monkey : public Animal {
public:
    virtual string getType() const override {
        return "monkey";
    }
};

class Lion : public Animal {
public:
    virtual string getType() const override {
        return "lion";
    }
};

int main() {
    ZooKeeper z;
    Animal *a = new Monkey();
    z.handleAnimal(*a);
    delete a;
    a = new Monkey();
    z.handleAnimal(*a);
    delete a;
    a = new Lion();
    z.handleAnimal(*a);
    delete a;

    cout << z.getAnimalCount("monkey") << endl;
    cout << z.getAnimalCount("lion") << endl;
    cout << z.getAnimalCount("cat") << endl;

    return 0;
}
