
**Academic Record Tracking CLI System**
  A menu-driven C++ console application for managing student academic
  records. The system lets users enter student details, view records,
  search for a student by ID, and review overall class performance.

**Features**
  - Add student records with student ID, full name, and marks
  - Automatically assign grades based on marks
  - Display student records in a formatted table
  - Search for a student using their ID
  - Generate a class performance summary
  - Calculate total marks, class average, highest marks, and lowest marks
  - Count passed and failed students
  - Display grade distribution
  - Validate user input for menu choices, IDs, and marks

**Grading Criteria**
    Marks       Grade
    80--100     A
    70--79.99   B
    60--69.99   C
    50--59.99   D
    Below 50    F
  A student passes with marks of 50 or above.
  
**Technologies and Concepts**
  - C++
  - Structures (struct)
  - Standard Template Library (vector)
  - Functions
  - Loops and conditional statements
  - Input validation
  - Formatted console output
    
**How to Run**
  1. Clone or download this repository.
  2. Open Academic Record Tracking CLI System.sln in Visual Studio, or
   create a C++ console project and add Task.cpp.
  3. Build the project.
  4. Run the application and use the menu to select an operation.
     
**Menu Options**
  1. Enter Student Records
  2. Display Student Records
  3. Show Class Performance Summary
  4. Search Student by ID
  5. Exit
     
**Notes**
  - Student records are stored in memory while the program is running.
  - Records are not saved to a file or database, so they are lost when
    the application closes.
  - The program accepts marks from 0 to 100 and supports up to 100
    students per entry operation.

**Purpose**
  This project was developed for academic practice to demonstrate
  fundamental C++ programming concepts through a practical student-record
  management application.
