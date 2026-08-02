// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

struct Student {
    string name;
    int id;
    vector<double> scores;
};

double calculateAverage(const vector<double>& scores) {
    if (scores.empty()) {
        return 0.0;
    }
    double sum = 0.0;
    for (double s : scores) {
        sum += s;
    }
    return sum / scores.size();
}

void addStudent(vector<Student>& students) {
    Student s;

    cout << "Student name: ";
    getline(cin, s.name);

    cout << "Student ID: ";
    cin >> s.id;
    cin.ignore();

    int count;
    cout << "How many scores? ";
    cin >> count;

    if (count <= 0) {
        cout << "Error: Number of scores must be positive. Student not added." << endl;
        cin.ignore();
        return;
    }

    for (int i = 0; i < count; i++) {
        double score;
        cout << "Enter score " << (i + 1) << ": ";
        cin >> score;
        s.scores.push_back(score);
    }
    cin.ignore();

    students.push_back(s);
    cout << "Student \"" << s.name << "\" added successfully." << endl;
}

void displayAllStudents(const vector<Student>& students) {
    if (students.empty()) {
        cout << "No students have been added yet." << endl;
        return;
    }

    cout << fixed << setprecision(2);
    cout << left << setw(20) << "Name" << setw(12) << "ID"
         << setw(10) << "Average" << "Scores" << endl;
    cout << "--------------------------------------------------------" << endl;

    for (const Student& s : students) {
        cout << left << setw(20) << s.name << setw(12) << s.id
             << setw(10) << calculateAverage(s.scores);
        for (size_t i = 0; i < s.scores.size(); i++) {
            cout << s.scores[i];
            if (i < s.scores.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }
}

void calculateAverageForStudent(const vector<Student>& students) {
    int id;
    cout << "Enter student ID: ";
    cin >> id;
    cin.ignore();

    for (const Student& s : students) {
        if (s.id == id) {
            cout << fixed << setprecision(2);
            cout << s.name << "'s average score: " << calculateAverage(s.scores) << endl;
            return;
        }
    }

    cout << "Error: Student ID " << id << " not found." << endl;
}

void printMenu() {
    cout << "\n================================" << endl;
    cout << "   STUDENT RECORD SYSTEM MENU" << endl;
    cout << "================================" << endl;
    cout << "1. Add student" << endl;
    cout << "2. Display all students" << endl;
    cout << "3. Calculate average score" << endl;
    cout << "4. Quit" << endl;
    cout << "Enter your choice (1-4): ";
}

int main() {
    vector<Student> students;
    int choice;
    bool running = true;

    while (running) {
        printMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayAllStudents(students);
                break;
            case 3:
                calculateAverageForStudent(students);
                break;
            case 4:
                cout << "Goodbye!" << endl;
                running = false;
                break;
            default:
                cout << "Error: Invalid choice. Please enter 1-4." << endl;
        }
    }

    return 0;
}

