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
};


class Laptop : public Device {
public:
    void displayLaptop() {
        cout << "Laptop Brand: " << getBrand() << endl;
        cout << "Power Consumption: " << getPowerConsumption() << " W" << endl;
        cout << "Device Type: Laptop" << endl;
        cout << "----------------------" << endl;
    }
};


class Smartphone : public Device {
public:
    void displaySmartphone() {
        cout << "Smartphone Brand: " << getBrand() << endl;
        cout << "Power Consumption: " << getPowerConsumption() << " W" << endl;
        cout << "Device Type: Smartphone" << endl;
        cout << "----------------------" << endl;
    }
};

int main() {
    Laptop l1;
    Smartphone s1;

   
    l1.setBrand("Dell");
    l1.setPowerConsumption(65);

    s1.setBrand("Samsung");
    s1.setPowerConsumption(15);

    
    l1.displayLaptop();
    s1.displaySmartphone();

    return 0;
}