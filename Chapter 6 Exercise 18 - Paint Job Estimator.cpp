// Chapter 6 Exercise 18 - Paint Job Estimator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Programmer: Brenna Meyer
//Date: March 29th, 2025
// Requiremetns:Paint Job Estimator A painting company has determined that for every 110 square feet of wall space,
// 1 gallon of paint and 8 hours of labor will be required.The company charges $25.00 per hour for labor.
// Write a modular program that allows the user to enter the number of rooms that are to be painted and the price
// of the paint per gallon.It should also ask for the square feet of wall space in each room.It should then display the following data :
//The number of gallons of paint required
//The hours of labor required
//The cost of the paint
//The labor charges
//The total cost of the paint job

#include <iostream>
#include <string>
using namespace std;

// Function prototypes
double getValidInput(const string& prompt, double minValue);
void getRoomInfo(double& rooms, double& totalSqft);
void calculateCosts(double sqft, double pricePerGallon);
bool askToContinue();

//Main
int main() {
    do {
        double numRooms, pricePerGallon, totalSqft = 0;

        cout << " Paint Job Estimator \n";
        getRoomInfo(numRooms, totalSqft);
        pricePerGallon = getValidInput("Price of paint per gallon (minimum $10.00): $", 10.00);

        calculateCosts(totalSqft, pricePerGallon);

    } while (askToContinue());

    cout << "Done.\n";
    return 0;
}

// Gets and validates user input 
double getValidInput(const string& prompt, double minValue) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;

        if (cin.fail()) {
            cin.clear();
            while (cin.get() != '\n') continue;
            cout << "Invalid input. Please enter a valid number.\n";
        }
        else if (value < minValue) {
            cout << "Error: Price must be at least $" << minValue << ".\n";
            while (cin.get() != '\n') continue;
        }
        else {
            while (cin.get() != '\n') continue;
            return value;
        }
    }
}

// Gets information about rooms to paint
void getRoomInfo(double& rooms, double& totalSqft) {
    rooms = getValidInput("Number of rooms to paint: ", 1);

    for (int i = 0; i < rooms; i++) {
        string prompt = "Sq. Ft. of wall space in room " + to_string(i + 1) + ": ";
        totalSqft += getValidInput(prompt, 0);
    }
}

// Calculates and displays all costs
void calculateCosts(double sqft, double pricePerGallon) {
    const double SqftPerGallon = 110.0;
    const double hoursPerGallon = 8.0;
    const double laborRate = 25.00;

    double gallonsNeeded = sqft / SqftPerGallon;
    double laborHours = gallonsNeeded * hoursPerGallon;
    double paintCost = gallonsNeeded * pricePerGallon;
    double laborCost = laborHours * laborRate;
    double totalCost = paintCost + laborCost;

    cout << "\nCost Estimate\n"
        << "Total SqFt to paint: " << sqft << "\n"
        << "Gallons required: " << gallonsNeeded << "\n"
        << "Hours required: " << laborHours << "\n"
        << "Paint cost: $" << paintCost << "\n"
        << "Labor cost: $" << laborCost << "\n"
        << "Total Cost: $" << totalCost << "\n";
}
// Asks user if they want to perform another calculation
bool askToContinue() {
    char choice;
    cout << "Would you like to calculate another paint job? (Y/N): ";
    cin >> choice;
    while (cin.get() != '\n') continue; 

    choice = toupper(choice);
    while (choice != 'Y' && choice != 'N') {
        cout << "Please enter Y or N: ";
        cin >> choice;
        while (cin.get() != '\n') continue; 
        choice = toupper(choice);
    }

    return choice == 'Y';
}

