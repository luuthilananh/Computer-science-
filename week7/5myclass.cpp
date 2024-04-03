#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

class MyClass{
private:
    vector<pair<int, string>> elements;
public:
    void addElement(int num, const string& str){
        for (const auto& element : elements){  // add tung thanh phan cua pair (so, chu)(chinh la element) vao vector
            if(element.first == num && element.second == str){
                return;
            }
        }
        elements.push_back(make_pair(num, str));
    }  

    void printStructures() const {
        for (const auto& element: elements){
            cout << element.first << " " << element.second << endl;
        }
    } 

    MyClass& operator += (const MyClass& other){ // dinh nghia phep tinh += cai duoc dung o main
        for (const auto& el : other.elements){
            if (find(elements.begin(), elements.end(), el) == elements.end()){ // chua hieu hien tg xay ra
                elements.push_back(el);
            }
        } 
        return *this;
    }
};

int main(){
    MyClass obj1;
    obj1.addElement(1, "hi");
    obj1.addElement(2, "hello");
    obj1.addElement(2, "hello");
    obj1.addElement(5, "hell");
    MyClass obj2;
    obj2.addElement(3, "hey");
    obj2.addElement(4, "pop");
    obj2.addElement(2, "hello");
    obj2.addElement(5, "hello");
    obj2.addElement(3, "hey");
    obj1 += obj2;
    obj1.printStructures();
    return 0;
}
