#include <iostream>
#include <cmath> // For square root and power functions

using namespace std;

// Function Declarations
void displayMenu();
void add();
void subtract();
void multiply();
void divide();
void squareRoot();
void power();

int main() 
{
    int choice;
    do {
        // Display Menu
        displayMenu();
        cin >> choice;

        if (cin.fail()) 
        {
            cin.clear(); // Clear the error flag
            cin.ignore(10000, '\n'); // Discard invalid input
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: add(); break;
            case 2: subtract(); break;
            case 3: multiply(); break;
            case 4: divide(); break;
            case 5: squareRoot(); break;
            case 6: power(); break;
            case 7: cout << "Exiting calculator. Goodbye!\n"; break;
            default: cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}

// Function to display the calculator menu
void displayMenu() 
{
    cout << "\n=========================\n";
    cout << " Calculator Menu\n";
    cout << "=========================\n";
    cout << "1. Add\n";
    cout << "2. Subtract\n";
    cout << "3. Multiply\n";
    cout << "4. Divide\n";
    cout << "5. Square Root\n";
    cout << "6. Power (x^y)\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

// Function to perform addition
void add() 
{
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    if (cin.fail()) 
    {
        cout << "Error: Invalid input. Please enter numeric values.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    cout << "Result: " << num1 + num2 << endl;
}

// Function to perform subtraction
void subtract() 
{
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    if (cin.fail()) 
    {
        cout << "Error: Invalid input. Please enter numeric values.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    cout << "Result: " << num1 - num2 << endl;
}

// Function to perform multiplication
void multiply() 
{
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    if (cin.fail())
    {
        cout << "Error: Invalid input. Please enter numeric values.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    cout << "Result: " << num1 * num2 << endl;
}

// Function to perform division
void divide() 
{
    double num1, num2;
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;

    if (cin.fail()) 
    {
        cout << "Error: Invalid input. Please enter numeric values.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    if (num2 == 0) {
        cout << "Error: Division by zero is not allowed.\n";
        return;
    }

    cout << "Result: " << num1 / num2 << endl;
}

// Function to calculate square root
void squareRoot() 
{
    double num;
    cout << "Enter a number: ";
    cin >> num;

    if (cin.fail()) 
    {
        cout << "Error: Invalid input. Please enter a numeric value.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    if (num < 0) 
    {
        cout << "Error: Square root of a negative number is not defined.\n";
        return;
    }

    cout << "Square root: " << sqrt(num) << endl;
}

// Function to calculate power (x^y)
void power() 
{
    double base, exponent;
    cout << "Enter base and exponent: ";
    cin >> base >> exponent;

    if (cin.fail()) 
    {
        cout << "Error: Invalid input. Please enter numeric values.\n";
        cin.clear();
        cin.ignore(10000, '\n');
        return;
    }

    cout << "Result: " << pow(base, exponent) << endl;
}
