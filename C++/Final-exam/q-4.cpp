#include <iostream>
#include <string>
using namespace std;

class Device {
private:
    string brand;
    int powerConsumption;

public:
   
    void setBrand(string b) {
        brand = b;
    }

    void setPowerConsumption(int p) {
        powerConsumption = p;
    }

    
    string getBrand() {
        return brand;
    }

    int getPowerConsumption() {
        return powerConsumption;
    }


    virtual void calculateDiscount() {
        cout << "Device Discount Calculation" << endl;
    }
};


class Laptop : public Device {
public:
    void calculateDiscount() {
        cout << "Laptop Brand: " << getBrand() << endl;
        cout << "Laptop Discount: 15%" << endl;
        cout << "---------------------" << endl;
    }
};


class Smartphone : public Device {
public:
    void calculateDiscount() {
        cout << "Smartphone Brand: " << getBrand() << endl;
        cout << "Smartphone Discount: 10%" << endl;
        cout << "---------------------" << endl;
    }
};

int main() {

    Laptop l1;
    Smartphone s1;

    l1.setBrand("Dell");
    s1.setBrand("Samsung");

    
    Device* devices[2];

    devices[0] = &l1;
    devices[1] = &s1;

    for (int i = 0; i < 2; i++) {
        devices[i]->calculateDiscount();
    }

    return 0;
}