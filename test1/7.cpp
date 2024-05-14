#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Module {
public:
    virtual string getName() const = 0;
    virtual void run() = 0;
    virtual ~Module() {}
};

// Module A
class ModuleA : public Module {
public:
    string getName() const override {
        return "moduleA";
    }

    void run() override {
        cout << "ModuleA runs" << endl;
    }
};

// Module B
class ModuleB : public Module {
public:
    string getName() const override {
        return "moduleB";
    }

    void run() override {
        cout << "ModuleB runs" << endl;
    }
};

// диспетчер
class Dispatcher {
private:
    vector<pair<string, Module*>> modules;

public:
    // Зарегистрировать переданный модуль
    void registerModule(Module* m) {
        modules.push_back({m->getName(), m});
        cout << "Registering module: " << m->getName() << endl;
    }

    // Вызвать метод run для модуля с именем moduleName
    // Если такого модуля не зарегистрировано, ничего не делать (но не падать)
    void runModule(const string& moduleName) const {
        for (const auto& pair : modules) {
            if (pair.first == moduleName) {
                cout << "Running module: " << moduleName << endl;
                pair.second->run();
                return;
            }
        }
    }
};

int main() {
    Module* m1 = new ModuleA();
    Module* m2 = new ModuleB();

    Dispatcher d;
    d.registerModule(m1);
    d.registerModule(m2);
    d.runModule("moduleA");
    d.runModule("moduleB");
    d.runModule("moduleC");

    delete m1;
    delete m2;

    return 0;
}
