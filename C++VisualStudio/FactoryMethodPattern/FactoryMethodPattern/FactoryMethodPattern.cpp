// FactoryMethodPattern.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
using namespace std;

class vehicle {
public:
    vehicle() {
        cout << "Vehicle Created \n";
    }
    virtual ~vehicle() {
        cout << "Vehicle Destroyed \n";
    }

    virtual void Print() {
        cout << "Vehicle \n";
    }
};

class Car : public vehicle {
public:
    Car() {
        cout << "Car Created " << endl;
    }

    ~Car() {
        cout << "Car Destroyed " << endl;
    }

    void Print() {
        cout << "Car " << endl;
    }
};

class Bike : public vehicle {
public:
    Bike() {
        cout << "Bike created" << endl;
    }

    ~Bike() {
        cout << "Bike is destroyed" << endl;
    }

    void Print() {
        cout << "Bike" << endl;
    }
};

enum VehicleClass {
    CAR = 0,
    BIKE = 1
};

class VehicleFactory {
public:
    VehicleFactory() {
        cout << "Vehicle Factory is created" << endl;
    }

    ~VehicleFactory() {
        cout << "Vechicle Factory is destroyed" << endl;
    }


    vehicle* CreateVehicle(enum VehicleClass arg) {
        vehicle* tmpVeh = nullptr;
        switch (arg){
        case CAR:
            tmpVeh = (vehicle*) new Car();
            break;
        case BIKE:
            tmpVeh = (vehicle*) new Bike();
            break;
        default:
            cout << "Invalid Vehicle" << endl;
            break;
        }

        return tmpVeh;
    }
};


int main()
{
    std::cout << "Factory design pattern implementation \n";
    unique_ptr<VehicleFactory> Fac(new VehicleFactory());
    cout << "Creating Car \n";
    unique_ptr<vehicle> myCar = (unique_ptr<vehicle>)Fac->CreateVehicle(CAR);
    cout << "Creating bike \n";
    unique_ptr<vehicle> myBike = (unique_ptr<vehicle>) Fac->CreateVehicle(BIKE);

    cout << " exiting" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
