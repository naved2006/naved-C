#include<iostream>
using namespace std;

class Queue
{
private:
    int arr[50];
    int front;
    int rear;
    int size;

public:

    Queue(int s)
    {
        size = s;
        front = 0;
        rear = -1;
    }

    void enqueue()
    {
        if(rear == size - 1)
        {
            cout << "Queue Overflow" << endl;
        }
        else
        {
            int value;
            cout << "Enter Value : ";
            cin >> value;

            rear++;
            arr[rear] = value;

            cout << "Value Inserted" << endl;
        }
    }

    void dequeue()
    {
        if(front > rear)
        {
            cout << "Queue Underflow" << endl;
        }
        else
        {
            cout << "Deleted Value : " << arr[front] << endl;
            front++;
        }
    }

    void display()
    {
        if(front > rear)
        {
            cout << "Queue Empty" << endl;
        }
        else
        {
            cout << "Queue Data : ";

            for(int i = front; i <= rear; i++)
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

    cout << "Enter Queue Size : ";
    cin >> n;

    Queue q(n);

    int choice;

    do
    {
        cout << "\n1. Enqueue";
        cout << "\n2. Dequeue";
        cout << "\n3. Display";
        cout << "\n0. Exit";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                q.enqueue();
                break;

            case 2:
                q.dequeue();
                break;

            case 3:
                q.display();
                break;

            case 0:
                cout << "Program End";
                break;

            default:
                cout << "Wrong Choice";
        }

    }while(choice != 0);

    return 0;
}
