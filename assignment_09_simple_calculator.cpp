// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 9
// =============================================================================
//
// TASK: Console-Based Simple Calculator
//
// Build a calculator program that runs in the console and performs basic
// arithmetic operations based on the user's input.
//
// -----------------------------------------------------------------------------
// OPERATIONS YOUR CALCULATOR MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Addition          ( + )    e.g.  10 + 3  =  13
//   2. Subtraction       ( - )    e.g.  10 - 3  =  7
//   3. Multiplication    ( * )    e.g.  10 * 3  =  30
//   4. Division          ( / )    e.g.  10 / 3  =  3.33
//   5. Modulus           ( % )    e.g.  10 % 3  =  1  (remainder)
//   6. Exponentiation    ( ^ )    e.g.  2 ^ 8   =  256
//   7. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        SIMPLE CALCULATOR
//   ============================
//   1. Addition
//   2. Subtraction
//   3. Multiplication
//   4. Division
//   5. Modulus
//   6. Exponentiation
//   7. Quit
//   Select an operation (1-7):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Select an operation (1-7): 4
//   Enter first number : 10
//   Enter second number: 3
//   Result: 10 / 3 = 3.33
//
//   Select an operation (1-7): 4
//   Enter first number : 5
//   Enter second number: 0
//   Error: Cannot divide by zero.
//
//   Select an operation (1-7): 7
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Each arithmetic operation MUST be written as its own function.
// - Use a loop so the calculator keeps running until the user selects Quit.
// - Division by zero must be caught and handled with a clear error message
//   (do NOT let the program crash).
// - Use fixed and setprecision(2) to display results to 2 decimal places.
// - Handle invalid menu choices gracefully.
// - For exponentiation use a loop or the pow() function from <cmath>.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b, bool& success) {
    if (b == 0) {
        success = false;
        return 0.0;
    }
    success = true;
    return a / b;
}

double modulo(double a, double b, bool& success) {
    if (b == 0) {
        success = false;
        return 0.0;
    }
    success = true;
    return fmod(a, b);
}

double exponent(double base, double exp) {
    return pow(base, exp);
}

void printMenu() {
    cout << "\n============================" << endl;
    cout << "     SIMPLE CALCULATOR" << endl;
    cout << "============================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Modulus" << endl;
    cout << "6. Exponentiation" << endl;
    cout << "7. Quit" << endl;
    cout << "Select an operation (1-7): ";
}

int main() {
    int choice;
    bool running = true;

    cout << fixed << setprecision(2);

    while (running) {
        printMenu();
        cin >> choice;

        if (choice == 7) {
            cout << "Goodbye!" << endl;
            running = false;
            continue;
        }

        if (choice < 1 || choice > 7) {
            cout << "Error: Invalid choice. Please enter 1-7." << endl;
            continue;
        }

        double a, b;
        cout << "Enter first number : ";
        cin >> a;
        cout << "Enter second number: ";
        cin >> b;

        bool success = true;
        double result = 0.0;
        char symbol = ' ';

        switch (choice) {
            case 1:
                result = add(a, b);
                symbol = '+';
                break;
            case 2:
                result = subtract(a, b);
                symbol = '-';
                break;
            case 3:
                result = multiply(a, b);
                symbol = '*';
                break;
            case 4:
                result = divide(a, b, success);
                symbol = '/';
                if (!success) {
                    cout << "Error: Cannot divide by zero." << endl;
                    continue;
                }
                break;
            case 5:
                result = modulo(a, b, success);
                symbol = '%';
                if (!success) {
                    cout << "Error: Cannot divide by zero." << endl;
                    continue;
                }
                break;
            case 6:
                result = exponent(a, b);
                symbol = '^';
                break;
        }

        cout << "Result: " << a << " " << symbol << " " << b << " = " << result << endl;
    }

    return 0;
}

