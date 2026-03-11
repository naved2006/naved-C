#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;

public:
   
    Student(string n, int r) {
        name = n;
        rollNumber = r;
    }

  
    void display() {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "" << endl;
    }
};

int main() {
    
    Student s[3] = {
        Student("Ali", 101),
        Student("Ahmed", 102),
        Student("Naved", 103)
    };

    
    for (int i = 0; i < 3; i++) {
        s[i].display();
    }

    return 0;
}