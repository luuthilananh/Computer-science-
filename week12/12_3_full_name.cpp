#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Person
{
private:
    string surname;
    string name;
    string middleName;

public:
    // Конструктор по умолчанию
    Person() {}

    Person(string surname, string name, string middleName) : surname(surname), name(name), middleName(middleName) {}

    friend istream &operator>>(istream &input, Person &p)
    {
        getline(input, p.surname, ',');
        input.ignore();
        getline(input, p.name, ',');
        input.ignore();
        getline(input, p.middleName);
        return input;
    }

    friend ostream &operator<<(ostream &output, const Person &p)
    {
        output << p.surname << ", " << p.name << ", " << p.middleName;
        return output;
    }

    bool operator<(const Person &other) const
    {
        if (surname != other.surname)
            return surname < other.surname;
        else if (name != other.name)
            return name < other.name;
        else
            return middleName < other.middleName;
    }
};

int main()
{
    cout << "Testing I/O" << endl;
    Person p;
    cin >> p;
    cout << p << endl;

    cout << "Testing sorting" << endl;
    vector<Person> people;
    people.push_back(Person("Ivanov", "Ivan", "Ivanovich"));
    people.push_back(Person("Petrov", "Petr", "Petrovich"));
    people.push_back(Person("Ivanov", "Ivan", "Petrovich"));
    people.push_back(Person("Ivanov", "Petr", "Ivanovich"));

    sort(people.begin(), people.end());
    for (const auto &person : people)
    {
        cout << person << endl;
    }

    return 0;
}
