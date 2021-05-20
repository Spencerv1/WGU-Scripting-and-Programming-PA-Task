// C867ClassRosterProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "student.h"
#include "roster.h"

int main() {
    
    // Requirement F1:

    cout << setfill('-') << setw(47) << "" << endl;
    cout << "C867: Scripting and Programming - Applications" << endl;
    cout << "Programming language used: C++" << endl;
    cout << "WGU Student ID: 001293944" << endl;
    cout << "Programmed by Spencer Verhoff" << endl;
    cout << setfill('-') << setw(47) << "" << endl;
    cout << endl;


    // Requirement F2 & F3: Create instance of the Roster class called classRoster
    // Roster constructor adds all students from studentData to classRoster

    Roster* classRoster = new Roster();


    // Requirement F4: Pseudo code correctly converted

    classRoster->printAll();
    classRoster->printInvalidEmails();

    // Loop through classRosterArray and printAverageDaysInCourse() for each student, using an accessor to get each student's ID
    int i;
    int studentDataLength = sizeof(studentData) / sizeof(studentData[0]);
    for (i = 0; i < studentDataLength; ++i) {

        string studentID = classRoster->classRosterArray[i]->getStudentID();
        classRoster->printAverageDaysInCourse(studentID);

    }
    cout << endl;

    classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);
    cout << endl;
    
    classRoster->remove("A3");
    classRoster->printAll();
    classRoster->remove("A3");
    // Expected: the above line should print a message saying such a student with this ID was not found.


    delete classRoster;
    return 0;
}
