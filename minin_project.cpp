#include<iostream>
using namespace std;

// Constant string for rent prompt
const string rentPrompt = " Would you like to rent this vehicle?";

// Base class for all vehicles
class vehicle{
public:
    // Greeting function
    virtual void greeting(){
        cout << "Welcome to the advanced vehicle rental system:\n";
    }
    // Ask for vehicle type
    virtual void fav(){
        cout << "Which vehicle would you like to rent?\n";
    }
    // Ask for company/brand
    virtual void liked(){
        cout << "Which company vehicle would you like to rent?" << endl;
    }
    // Payment process for renting
    virtual void pay(){
        string n, M;
        cout << "Do you want to proceed with the rental? (YES or NO): ";
        cin >> n;
        cout << endl;
        if(n == "YES"){
            cout << "The payment id is: 89255****@ptamy" << endl;
            cout << "If your payment is done then enter YES: ";
            cin >> M;
            if (M == "YES"){
                cout << "Rental successful! Enjoy your ride." << endl;
            }
            else {
                cout << "Something went wrong, please exit the system." << endl;
            }
        } else {
            cout << "THANK YOU SO MUCH FOR YOUR TIME!" << endl;
        }
    }
};

// Derived class for bikes
class BIKE : public vehicle {
public:
    int n = 2;
    string choices = "BIKE";
    // Constructor for BIKE
    BIKE(string regNo, double rate, string name){
        cout << "\nRegistration No: " << regNo << endl
             << "Rental Rate: " << rate << endl
             << "Bike Name: " << name << endl;
    }
};

// Derived class for cars
class CAR : public vehicle {
public:
    int n = 2;
    string choices = "CAR";
    // Constructor for CAR
    CAR(string regNo, double rate, string name){
        cout << "\nRegistration No: " << regNo << endl
             << "Rental Rate: " << rate << endl
             << "Car Name: " << name << endl;
    }
};

int main(){
    // Create base vehicle object and greet user
    vehicle obj1;
    obj1.greeting();
    obj1.fav();

    // Show options to user
    cout << "Here are some options\n 1) CAR\n 2) BIKE\n";
    string choicess;
    cout << "Enter your vehicle choice: ";
    cin >> choicess;

    // If user chooses BIKE
    if(choicess == "BIKE"){
        // Create array of bikes
        BIKE obj[] = {
            BIKE("MH12AB1234", 1500.0, "YAMAHA"),
            BIKE("MH12AB5678", 2000.0, "BMW")
        };
        cout << endl;
        obj[0].liked(); // Ask for brand
        string name;
        cout << "Enter bike name: ";
        cin >> name;
        // If user selects YAMAHA
        if(name == "YAMAHA"){
            BIKE("MH12AB1234", 1500.0, "YAMAHA");
            cout << rentPrompt << endl;
            obj1.pay();
        }
        // If user selects BMW
        else if (name == "BMW"){
            BIKE("MH12AB5678", 2000.0, "BMW");
            cout << rentPrompt << endl;
            obj1.pay();
        }
        // If bike not found
        else {
            cout << "Bike not found!" << endl;
        }
    }
    // If user chooses CAR
    else if (choicess == "CAR"){
        // Create array of cars
        CAR obj[] = {
            CAR("MH12AB4321", 1800.0, "SWIFT"),
            CAR("MH12AB8765", 2500.0, "BMW")
        };
        cout << endl;
        obj[0].liked(); // Ask for brand
        string name;
        cout << "Enter car name: ";
        cin >> name;
        // If user selects SWIFT
        if(name == "SWIFT"){
            CAR("MH12AB4321", 1800.0, "SWIFT");
            cout << rentPrompt << endl;
            obj1.pay();
        }
        // If user selects BMW
        else if (name == "BMW"){
            CAR("MH12AB8765", 2500.0, "BMW");
            cout << rentPrompt << endl;
            obj1.pay();
        }
        // If car not found
        else {
            cout << "Car not found!" << endl;
        }
    }
    // If user enters invalid choice
    else{
        cout << "Error: Enter correct details in CAPS." << endl;
    }
}