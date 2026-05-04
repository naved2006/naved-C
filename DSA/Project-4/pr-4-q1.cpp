#include <iostream>
using namespace std;


class StackBase {
protected:
    int *arr;
    int topIndex;
    int size;

public:
    StackBase(int s) {
        size = s;
        arr = new int[size];
        topIndex = -1;
    }


    virtual void push(int value) = 0;
    virtual void pop() = 0;
    virtual void top() = 0;
    virtual void isEmpty() = 0;
    virtual void isFull() = 0;

    virtual ~StackBase() {
        delete[] arr;
    }
};


class Stack : public StackBase {
public:
    Stack(int s) : StackBase(s) {}

    // Push
    void push(int value) override {
        if (topIndex == size - 1) {
            cout << "Stack is Full!\n";
        } else {
            topIndex++;
            arr[topIndex] = value;
            cout << value << " pushed into stack.\n";
        }
    }

 
    void pop() override {
        if (topIndex == -1) {
            cout << "Stack is Empty!\n";
        } else {
            cout << arr[topIndex] << " popped from stack.\n";
            topIndex--;
        }
    }


    void top() override {
        if (topIndex == -1) {
            cout << "Stack is Empty!\n";
        } else {
            cout << "Top element: " << arr[topIndex] << endl;
        }
    }

 
    void isEmpty() override {
        if (topIndex == -1)
            cout << "Stack is Empty.\n";
        else
            cout << "Stack is NOT Empty.\n";
    }

    void isFull() override {
        if (topIndex == size - 1)
            cout << "Stack is Full.\n";
        else
            cout << "Stack is NOT Full.\n";
    }
};


int main() {
    int n, choice, value;
    cout << "Enter stack size: ";
    cin >> n;

    Stack s(n);

    do {
        cout << "\n--- Stack Menu ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top\n";
        cout << "4. Check Empty\n";
        cout << "5. Check Full\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                s.push(value);
                break;

            case 2:
                s.pop();
                break;

            case 3:
                s.top();
                break;

            case 4:
                s.isEmpty();
                break;

            case 5:
                s.isFull();
                break;

            case 0:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}