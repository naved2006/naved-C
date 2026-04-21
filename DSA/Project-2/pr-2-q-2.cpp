#include <iostream>
#include <vector>
using namespace std;


template <class T>
class Student
{
private:
    T id;
    string name;

public:
  
    Student(T i, string n)
    {
        id = i;
        name = n;
    }

    T getId()
    {
        return id;
    }

    void display()
    {
        cout << "ID: " << id << "\tName: " << name << endl;
    }
};

int main()
{
    vector<Student<int>> students;

    students.push_back(Student<int>(101, "Ali"));
    students.push_back(Student<int>(102, "Sara"));
    students.push_back(Student<int>(103, "Ahmed"));

    cout << "All Students:\n";
    for (int i = 0; i < students.size(); i++)
    {
        students[i].display();
    }

    int searchId;
    cout << "\nEnter ID to search: ";
    cin >> searchId;

    bool found = false;
    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getId() == searchId)
        {
            cout << "Student Found:\n";
            students[i].display();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Student not found.\n";
    }

    int removeId;
    cout << "\nEnter ID to remove: ";
    cin >> removeId;

    for (int i = 0; i < students.size(); i++)
    {
        if (students[i].getId() == removeId)
        {
            students.erase(students.begin() + i);
            cout << "Student removed successfully.\n";
            break;
        }
    }

    cout << "\nUpdated Student List:\n";
    for (int i = 0; i < students.size(); i++)
    {
        students[i].display();
    }

    return 0;
}