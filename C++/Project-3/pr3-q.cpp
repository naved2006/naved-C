#include <iostream>
#include <cstring>
using namespace std;



class Vehicle
{
protected:

    int vehicleID;
    char manufacturer[50];
    char model[50];
    int year;

    static int totalVehicles;

public:

    Vehicle()
    {
        vehicleID = 0;
        strcpy(manufacturer,"");
        strcpy(model,"");
        year = 0;

        totalVehicles++;
    }

    Vehicle(int id , const char man[] , const char mod[] , int y)
    {
        vehicleID = id;
        strcpy(manufacturer,man);
        strcpy(model,mod);
        year = y;

        totalVehicles++;
    }

    ~Vehicle()
    {
        totalVehicles--;
    }

    void setVehicleID(int id)
    {
        vehicleID = id;
    }

    int getVehicleID()
    {
        return vehicleID;
    }

    void inputVehicle()
    {
        cout<<"Enter Vehicle ID: ";
        cin>>vehicleID;

        cin.ignore();

        cout<<"Enter Manufacturer: ";
        cin.getline(manufacturer,50);

        cout<<"Enter Model: ";
        cin.getline(model,50);

        cout<<"Enter Year: ";
        cin>>year;
    }

    void displayVehicle()
    {
        cout<<"Vehicle ID: "<<vehicleID<<endl;
        cout<<"Manufacturer: "<<manufacturer<<endl;
        cout<<"Model: "<<model<<endl;
        cout<<"Year: "<<year<<endl;
    }

    static int getTotalVehicles()
    {
        return totalVehicles;
    }
};

int Vehicle::totalVehicles = 0;






class Car : public Vehicle
{
protected:

    char fuelType[20];

public:

    void inputCar()
    {
        inputVehicle();

        cin.ignore();

        cout<<"Enter Fuel Type: ";
        cin.getline(fuelType,20);
    }

    void displayCar()
    {
        displayVehicle();
        cout<<"Fuel Type: "<<fuelType<<endl;
    }
};





class ElectricCar : public Car
{
protected:

    int batteryCapacity;

public:

    void inputElectric()
    {
        inputCar();

        cout<<"Enter Battery Capacity: ";
        cin>>batteryCapacity;
    }

    void displayElectric()
    {
        displayCar();
        cout<<"Battery Capacity: "<<batteryCapacity<<endl;
    }
};





class SportsCar : public ElectricCar
{
    int topSpeed;

public:

    void inputSports()
    {
        inputElectric();

        cout<<"Enter Top Speed: ";
        cin>>topSpeed;
    }

    void displaySports()
    {
        displayElectric();
        cout<<"Top Speed: "<<topSpeed<<endl;
    }
};





class Sedan : public Car
{
public:

    void showSedan()
    {
        inputCar();
    }

    void displaySedan()
    {
        displayCar();
    }
};

class SUV : public Car
{
public:

    void showSUV()
    {
        inputCar();
    }

    void displaySUV()
    {
        displayCar();
    }
};





class Aircraft
{
protected:

    int flightRange;

public:

    void inputAircraft()
    {
        cout<<"Enter Flight Range: ";
        cin>>flightRange;
    }

    void displayAircraft()
    {
        cout<<"Flight Range: "<<flightRange<<endl;
    }
};





class FlyingCar : public Car , public Aircraft
{

public:

    void inputFlyingCar()
    {
        inputCar();
        inputAircraft();
    }

    void displayFlyingCar()
    {
        displayCar();
        displayAircraft();
    }
};





class VehicleRegistry
{

private:

    Vehicle vehicles[100];
    int count;

public:

    VehicleRegistry()
    {
        count = 0;
    }

    void addVehicle()
    {
        if(count < 100)
        {
            vehicles[count].inputVehicle();
            count++;
        }
        else
        {
            cout<<"Registry Full"<<endl;
        }
    }

    void displayVehicles()
    {
        if(count == 0)
        {
            cout<<"No vehicles stored"<<endl;
            return;
        }

        for(int i=0;i<count;i++)
        {
            cout<<"\nVehicle "<<i+1<<" details\n";
            vehicles[i].displayVehicle();
        }
    }

    void searchVehicle(int id)
    {
        for(int i=0;i<count;i++)
        {
            if(vehicles[i].getVehicleID() == id)
            {
                cout<<"Vehicle Found\n";
                vehicles[i].displayVehicle();
                return;
            }
        }

        cout<<"Vehicle not found\n";
    }
};






int main()
{

    VehicleRegistry reg;

    int choice;

    do
    {

        cout<<"\n----- Vehicle Registry Menu -----\n";
        cout<<"1 Add Vehicle\n";
        cout<<"2 Display Vehicles\n";
        cout<<"3 Search Vehicle by ID\n";
        cout<<"4 Exit\n";

        cout<<"Enter choice: ";
        cin>>choice;


        if(choice == 1)
        {
            reg.addVehicle();
        }

        else if(choice == 2)
        {
            reg.displayVehicles();
        }

        else if(choice == 3)
        {
            int id;

            cout<<"Enter vehicle ID: ";
            cin>>id;

            reg.searchVehicle(id);
        }

        else if(choice == 4)
        {
            cout<<"Exiting program\n";
        }

        else
        {
            cout<<"Wrong choice\n";
        }

    }while(choice != 4);


    return 0;
}