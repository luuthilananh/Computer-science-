#include <iostream>
#include <vector>
#include <utility>

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
};

int main(){
    MyClass obj1;
    obj1.addElement(1, "hello");
    obj1.addElement(2, "hi");
    obj1.addElement(2, "hi");
    obj1.addElement(1, "hello");
    obj1.addElement(3, "lallo");
    obj1.printStructures();
    return 0;
}
