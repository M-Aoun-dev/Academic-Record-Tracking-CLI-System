// |---------------- Academic Record Tracking CLI System ----------------|

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

// |---------------------- Structures ----------------------|

struct Student {
    int studentID;
    string fullName;
    double marks;
    string grade;
};

// |---------------------- Helper Functions ----------------------|

void printLine(char ch = '-', int len = 70) {
    for (int i = 0; i < len; i++) {
        cout << ch;
    }
    cout << endl;
}

void printHeader(const char title[]) {
    cout << endl;
    printLine();
    cout << "  " << title << endl;
    printLine();
}

void clearInput() {
    cin.clear();
    cin.ignore(10000, '\n');
}

// Getting INT input
int getIntInput(const char message[], int min, int max) {
    int value;

    while (true) {
        cout << message;
        if (cin >> value && value >= min && value <= max) {
            cin.ignore(10000, '\n');
            return value;
        }

        if (cin.fail()) {
            clearInput();
        }
        else {
            cin.ignore(10000, '\n');
        }

        cout << "Invalid Input! Enter a number between " << min << " and " << max << "." << endl;
    }
}

// Getting DOUBLE input
double getDoubleInput(const char message[], double min, double max) {
    double value;

    while (true) {
        cout << message;

        if (cin >> value && value >= min && value <= max) {
            cin.ignore(10000, '\n');
            return value;
        }

        if (cin.fail()) {
            clearInput();
        }
        else {
            cin.ignore(10000, '\n');
        }

        cout << "Invalid Marks! Enter marks between "
            << min << " and " << max << "." << endl;
    }
}

// Getting Grades
string getGrade(double marks) {
    if (marks >= 80) {
        return "A";
    }
    else if (marks >= 70) {
        return "B";
    }
    else if (marks >= 60) {
        return "C";
    }
    else if (marks >= 50) {
        return "D";
    }
    else {
        return "F";
    }
}

// |---------------------- Input Student Records ----------------------|

void inputStudents(vector<Student>& students) {
    printHeader("ENTER STUDENT RECORDS");

    int totalStudents = getIntInput(
        "Enter Number of Students (1-100): ",
        1, 100
    );

    for (int i = 0; i < totalStudents; i++) {
        Student s;

        cout << endl;
        cout << "Student " << i + 1 << endl;
        printLine('-', 30);

        s.studentID = getIntInput(
            "Enter Student ID: ",
            1, 999999
        );

        cout << "Enter Full Name: ";
        getline(cin, s.fullName);

        while (s.fullName.empty()) {
            cout << "Name cannot be empty. Enter Full Name: ";
            getline(cin, s.fullName);
        }

        s.marks = getDoubleInput(
            "Enter Marks (0-100): ",
            0, 100
        );

        s.grade = getGrade(s.marks);

        students.push_back(s);

        cout << "Student Record Added Successfully!" << endl;
    }
}

// |---------------------- Display Student Records ----------------------|

void displayStudents(const vector<Student>& students) {
    printHeader("STUDENT ACADEMIC RECORDS");

    if (students.empty()) {
        cout << "No Student Records Found." << endl;
        return;
    }

    cout << left
        << setw(15) << "Student ID"
        << setw(30) << "Full Name"
        << setw(12) << "Marks"
        << setw(10) << "Grade"
        << endl;

    printLine('-', 60);

    cout << fixed << setprecision(2);

    for (int i = 0; i < students.size(); i++) {
        cout << left
            << setw(15) << students[i].studentID
            << setw(30) << students[i].fullName.substr(0, 29)
            << setw(12) << students[i].marks
            << setw(10) << students[i].grade
            << endl;
    }

    printLine('-', 60);
}

// |---------------------- Class Performance Summary ----------------------|

void showClassSummary(const vector<Student>& students) {
    printHeader("CLASS PERFORMANCE SUMMARY");

    if (students.empty()) {
        cout << "No Student Records Available for Summary." << endl;
        return;
    }

    double totalMarks = 0;
    double highMarks = students[0].marks;
    double lowMarks = students[0].marks;
    int passCount = 0;
    int failCount = 0;
    int gradeA = 0;
    int gradeB = 0;
    int gradeC = 0;
    int gradeD = 0;
    int gradeF = 0;

    for (int i = 0; i < students.size(); i++) {
        totalMarks += students[i].marks;

        if (students[i].marks > highMarks) {
            highMarks = students[i].marks;
        }

        if (students[i].marks < lowMarks) {
            lowMarks = students[i].marks;
        }

        if (students[i].marks >= 50) {
            passCount++;
        }
        else {
            failCount++;
        }

        if (students[i].grade == "A") {
            gradeA++;
        }
        else if (students[i].grade == "B") {
            gradeB++;
        }
        else if (students[i].grade == "C") {
            gradeC++;
        }
        else if (students[i].grade == "D") {
            gradeD++;
        }
        else {
            gradeF++;
        }
    }

    double average = totalMarks / students.size();

    cout << fixed << setprecision(2);
    cout << "Total Students       : " << students.size() << endl;
    cout << "Total Marks          : " << totalMarks << endl;
    cout << "Class Average        : " << average << endl;
    cout << "Highest Marks        : " << highMarks << endl;
    cout << "Lowest Marks         : " << lowMarks << endl;
    cout << "Passed Students      : " << passCount << endl;
    cout << "Failed Students      : " << failCount << endl;

    cout << endl;
    cout << "Grade Distribution" << endl;
    printLine('-', 30);
    cout << "Grade A (80-100)      : " << gradeA << endl;
    cout << "Grade B (70-79.99)    : " << gradeB << endl;
    cout << "Grade C (60-69.99)    : " << gradeC << endl;
    cout << "Grade D (50-59.99)    : " << gradeD << endl;
    cout << "Grade F (Below 50)    : " << gradeF << endl;
}

// |---------------------- Find Student ----------------------|

void searchStudent(const vector<Student>& students) {
    printHeader("SEARCH STUDENT");

    if (students.empty()) {
        cout << "No Student Records Found." << endl;
        return;
    }

    int searchID = getIntInput(
        "Enter Student ID to Search: ",
        1, 999999
    );

    bool found = false;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].studentID == searchID) {
            cout << endl;
            cout << "Student Found!" << endl;
            printLine('-', 40);
            cout << "Student ID : " << students[i].studentID << endl;
            cout << "Full Name  : " << students[i].fullName << endl;
            cout << fixed << setprecision(2);
            cout << "Marks      : " << students[i].marks << endl;
            cout << "Grade      : " << students[i].grade << endl;
            cout << "Result     : "
                << (students[i].marks >= 50 ? "Pass" : "Fail")
                << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student ID Not Found." << endl;
    }
}

// |---------------------- Main Menu ----------------------|

void showMenu() {
    cout << endl;
    cout << "|---------------------------------------------------------------------| " << endl;
    cout << "              ACADEMIC RECORD TRACKING SYSTEM" << endl;
    cout << "|---------------------------------------------------------------------| " << endl;

    cout << "[1] Enter Student Records" << endl;
    cout << "[2] Display Student Records" << endl;
    cout << "[3] Show Class Performance Summary" << endl;
    cout << "[4] Search Student by ID" << endl;
    cout << "[0] Exit" << endl;

    printLine('-', 70);
}

// |---------------------- Main Function ----------------------|

int main() {
    vector<Student> students;
    int choice;

    while (true) {
        showMenu();

        choice = getIntInput(
            "Enter Your Choice: ",
            0, 4
        );

        switch (choice) {
        case 1:
            inputStudents(students);
            break;

        case 2:
            displayStudents(students);
            break;

        case 3:
            showClassSummary(students);
            break;

        case 4:
            searchStudent(students);
            break;

        case 0:
            cout << endl;
            cout << "Thank You for Using Academic Record Tracking System!" << endl;
            return 0;
        }
    }

    return 0;
}
