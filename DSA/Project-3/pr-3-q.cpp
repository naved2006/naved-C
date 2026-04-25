#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};


class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

   
    void insert_at_beginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }

    
    void append(int data) {
        Node* newNode = new Node(data);

        if (head == NULL) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    
    void search(int key) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->data == key) {
                cout << key << " found in the list." << endl;
                return;
            }
            temp = temp->next;
        }
        cout << key << " not found in the list." << endl;
    }

   
    void delete_node(int key) {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next != NULL && temp->next->data != key) {
            temp = temp->next;
        }

        if (temp->next == NULL) {
            cout << "Element not found." << endl;
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

   
    void reverse() {
        Node* prev = NULL;
        Node* current = head;
        Node* nextNode = NULL;

        while (current != NULL) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        head = prev;
    }
};


int main() {
    LinkedList list;

    list.append(10);
    list.append(20);
    list.append(30);

    cout << "Original List: ";
    list.display();

    list.insert_at_beginning(5);
    cout << "After Insert at Beginning: ";
    list.display();

    list.search(20);

    list.delete_node(20);
    cout << "After Deletion: ";
    list.display();

    list.reverse();
    cout << "After Reversing: ";
    list.display();

    return 0;
}