#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node *head;

public:

    LinkedList()
    {
        head = NULL;
    }


    void insertBeginning()
    {
        int value;

        cout << "Enter Value : ";
        cin >> value;

        Node *newNode = new Node(value);

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }

        cout << "Node Inserted At Beginning." << endl;
    }

    
    void insertEnd()
    {
        int value;

        cout << "Enter Value : ";
        cin >> value;

        Node *newNode = new Node(value);

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }

        cout << "Node Inserted At End." << endl;
    }


    void deleteBeginning()
    {
        if(head == NULL)
        {
            cout << "Linked List Is Empty." << endl;
        }
        else
        {
            Node *temp = head;

            cout << "Deleted Node : " << temp->data << endl;

            head = head->next;

            delete temp;
        }
    }

   
    void display()
    {
        if(head == NULL)
        {
            cout << "Linked List Empty." << endl;
        }
        else
        {
            Node *temp = head;

            cout << "Linked List : ";

            while(temp != NULL)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }

            cout << endl;
        }
    }
};

int main()
{
    LinkedList obj;

    int choice;

    do
    {
        cout << "\nLINKED LIST MENU " << endl;

        cout << "1. Insert At Beginning" << endl;
        cout << "2. Insert At End" << endl;
        cout << "3. Delete From Beginning" << endl;
        cout << "4. Display" << endl;
        cout << "0. Exit" << endl;

        cout << "Enter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                obj.insertBeginning();
                break;

            case 2:
                obj.insertEnd();
                break;

            case 3:
                obj.deleteBeginning();
                break;

            case 4:
                obj.display();
                break;

            case 0:
                cout << "Program Ended." << endl;
                break;

            default:
                cout << "Invalid Choice." << endl;
        }

    } while(choice != 0);

    return 0;
}