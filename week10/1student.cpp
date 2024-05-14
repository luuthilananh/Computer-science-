#include <iostream>
#include <string>

using namespace std;

class Student {
private:
    string name;
    unsigned int score;

public:
    void setName(string name) {
        this->name = name;
    }

    void setScore(unsigned int score) {
        this->score = score;
    }

    string getName() const {
        return name;
    }

    unsigned int getScore() const {
        return score;
    }

    friend istream& operator>>(istream& in, Student& student) {
        getline(in, student.name); // Read the whole line as the name
        student.score = 0; // Set the score to 0
        return in;
    }

    friend ostream& operator<<(ostream& out, const Student& student) {
        out << "'" << student.name << "': " << student.score;
        return out;
    }
};

int main() {
    Student s;
    std::cin >> s;
    s.setScore(10);
    std::cout << s;

    return 0;
}
