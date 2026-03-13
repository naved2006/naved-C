#include <iostream>
using namespace std;

class LibraryItem {
protected:
    string title;
    string author;
    string dueDate;

public:
    LibraryItem(string t, string a, string d) {
        title = t;
        author = a;
        dueDate = d;
    }

    string getTitle() { return title; }
    string getAuthor() { return author; }
    string getDueDate() { return dueDate; }

    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setDueDate(string d) { dueDate = d; }

    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void displayDetails() = 0;

    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
public:
    Book(string t, string a, string d) : LibraryItem(t, a, d) {}

    void checkOut() {
        cout << "Book Checked Out\n";
    }

    void returnItem() {
        cout << "Book Returned\n";
    }

    void displayDetails() {
        cout << "Book: " << title << " Author: " << author << " Due: " << dueDate << endl;
    }
};

class DVD : public LibraryItem {
    int duration;

public:
    DVD(string t, string a, string d, int dur) : LibraryItem(t, a, d) {
        duration = dur;
    }

    void checkOut() {
        cout << "DVD Checked Out\n";
    }

    void returnItem() {
        cout << "DVD Returned\n";
    }

    void displayDetails() {
        cout << "DVD: " << title << " Author: " << author << " Duration: " << duration << " mins\n";
    }
};

class Magazine : public LibraryItem {
    int issueNumber;

public:
    Magazine(string t, string a, string d, int issue) : LibraryItem(t, a, d) {
        issueNumber = issue;
    }

    void checkOut() {
        cout << "Magazine Checked Out\n";
    }

    void returnItem() {
        cout << "Magazine Returned\n";
    }

    void displayDetails() {
        cout << "Magazine: " << title << " Author: " << author << " Issue: " << issueNumber << endl;
    }
};

int main() {

    const int MAX_ITEMS = 10;
    LibraryItem* libraryItems[MAX_ITEMS];
    int count = 0;

    int choice;

    do {
        cout << "\n1 Add Book";
        cout << "\n2 Add DVD";
        cout << "\n3 Add Magazine";
        cout << "\n4 Display Items";
        cout << "\n5 Checkout Item";
        cout << "\n6 Return Item";
        cout << "\n7 Exit\n";

        cin >> choice;

        if(choice == 1) {
            string title, author, due;
            cout<<"Enter Title: ";
            cin>>title;
            cout<<"Enter Author: ";
            cin>>author;
            cout<<"Enter Due Date: ";
            cin>>due;

            libraryItems[count++] = new Book(title,author,due);
        }

        else if(choice == 2) {
            string title, author, due;
            int duration;

            cout<<"Enter Title: ";
            cin>>title;
            cout<<"Enter Author: ";
            cin>>author;
            cout<<"Enter Due Date: ";
            cin>>due;
            cout<<"Enter Duration: ";
            cin>>duration;

            libraryItems[count++] = new DVD(title,author,due,duration);
        }

        else if(choice == 3) {
            string title, author, due;
            int issue;

            cout<<"Enter Title: ";
            cin>>title;
            cout<<"Enter Author: ";
            cin>>author;
            cout<<"Enter Due Date: ";
            cin>>due;
            cout<<"Enter Issue Number: ";
            cin>>issue;

            libraryItems[count++] = new Magazine(title,author,due,issue);
        }

        else if(choice == 4) {
            for(int i=0;i<count;i++) {
                libraryItems[i]->displayDetails();
            }
        }

        else if(choice == 5) {
            int id;
            cout<<"Enter Item Index: ";
            cin>>id;
            libraryItems[id]->checkOut();
        }

        else if(choice == 6) {
            int id;
            cout<<"Enter Item Index: ";
            cin>>id;
            libraryItems[id]->returnItem();
        }

    } while(choice != 7);

    for(int i=0;i<count;i++) {
        delete libraryItems[i];
    }

    return 0;
}