#include <iostream>
#include <vector>
using namespace std;

template <class T>
class MemoryCalculate
{
private:
    T id;
    string name;

public:
    
    MemoryCalculate(T i, string n)
    {
        id = i;
        name = n;
    }

    void display()
    {
        cout << "Student ID: " << id << endl;
        cout << "Student Name: " << name << endl;
    }
};

int main()
{

    vector<MemoryCalculate<int>> students;

    students.push_back(MemoryCalculate<int>(101, "Ali"));
    students.push_back(MemoryCalculate<int>(102, "Sara"));

    for (int i = 0; i < students.size(); i++)
    {
        students[i].display();
        cout << endl;
    }

    return 0;
}