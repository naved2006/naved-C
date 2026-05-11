#include<iostream>
using namespace std;

class Stack
{
private:
    int arr[100];
    int top;
    int size;

public:

    Stack(int s)
    {
        size = s;
        top = -1;
    }

   
    void push()
    {
        if(top == size - 1)
        {
            cout << "Stack Overflow..." << endl;
        }
        else
        {
            int value;
            cout << "Enter value : ";
            cin >> value;

            arr[++top] = value;

            cout << "Element Inserted Successfully." << endl;
        }
    }

    
    void pop()
    {
        if(top == -1)
        {
            cout << "Stack Underflow..." << endl;
        }
        else
        {
            cout << "Deleted Element : " << arr[top] << endl;
            top--;
        }
    }

   
    void display()
    {
        if(top == -1)
        {
            cout << "Stack is Empty." << endl;
        }
        else
        {
            cout << "Stack Elements are : ";

            for(int i = 0; i <= top; i++)
            {
                cout << arr[i] << " ";
            }

            cout << endl;
        }
    }
};

int main()
{
    int n;

    cout << "Enter Stack Size : ";
    cin >> n;

    Stack s(n);

    int choice;

    while(true)
    {
        cout << "\n STACK MENU " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter Choice : ";
        cin >> choice;

        if(choice == 1)
        {
            s.push();
        }
        else if(choice == 2)
        {
            s.pop();
        }
        else if(choice == 3)
        {
            s.display();
        }
        else if(choice == 4)
        {
            cout << "Program Ended." << endl;
            break;
        }
        else
        {
            cout << "Invalid Choice." << endl;
        }
    }

    return 0;
}