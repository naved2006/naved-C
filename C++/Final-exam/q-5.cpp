
#include <iostream>
using namespace std;


class Animal {
public:

    virtual void makeSound() = 0;
    virtual void move() = 0;
};

class Lion : public Animal {
public:
    void makeSound() {
        cout << "Lion roars" << endl;
    }

    void move() {
        cout << "Lion runs on land" << endl;
         cout << "------------------" << endl;
    }
};


class Fish : public Animal {
public:
    void makeSound() {
        cout << "Fish makes bubbling sound" << endl;
    }

    void move() {
        cout << "Fish swims in water" << endl;
    }
};

int main() {
    Lion l1;
    Fish f1;

   
    Animal* animals[2];

    animals[0] = &l1;
    animals[1] = &f1;

   
    for (int i = 0; i < 2; i++) {
        animals[i]->makeSound();
        animals[i]->move();
        
    }

    return 0;
}