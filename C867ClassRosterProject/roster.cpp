#include <sstream>
#include <iostream>
#include <string>
#include <list>
#include "roster.h"
using namespace std;


// Requirement E3A: Add functions sets instance variables (from studentData Table), and adds students to the roster
// Requirement E2 & F3: Populate each student and add them to classRoster

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
	
	string day1 = to_string(daysInCourse1);
	string day2 = to_string(daysInCourse2);
	string day3 = to_string(daysInCourse3);

	int arraySize = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	int i;

	for (i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); ++i) {

		if (classRosterArray[i] == nullptr) {

			classRosterArray[i] = new Student(studentID, firstName, lastName, emailAddress, age, (day1 + ", " + day2 + ", " + day3), degreeprogram);
			return;
		}

	}

	cout << "No open slots in classRosterArray" << endl;
	return;
};


// Requirement E3B: Remove function that removes students from roster by student ID

void Roster::remove(string studentID) {
	
	int arraySize = sizeof(classRosterArray) / sizeof(classRosterArray[0]);
	
	int i;
	for (i = 0; i < arraySize; ++i) {

		if (classRosterArray[i] != nullptr) {
			if (classRosterArray[i]->getStudentID() == studentID) {

				delete classRosterArray[i];
				classRosterArray[i] = nullptr;
				cout << "Student " << studentID << " deleted from the class roster." << endl;
				cout << endl;
				
				return;
			}	
		}
	}
	
	cout << "Error: StudentID " << studentID << " not found." << endl;
	cout << endl;
	return;
};


// Requirement E3C: Prints tab-separated list of student data
// loops through all of the students in the students in the student list, calls print() for each

void Roster::printAll() {
	
	int i;
	for (i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); ++i) {
		if (classRosterArray[i] != nullptr) {
			classRosterArray[i]->print();
		}
	}

	cout << endl;
	return;
};



// Requirement E3D: Prints a student's average number of days in the 3 courses by student ID.

void Roster::printAverageDaysInCourse(string studentID) {

	int i;
	for (i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); ++i) {

		if (classRosterArray[i]->getStudentID() == studentID) {
			string daysString = classRosterArray[i]->getDaysInCourses();

			stringstream s_stream(daysString);
			int ints[3] = { 0, 0, 0 };
			
			int j;
			for (j = 0; j < 3; ++j) {
				string substr;
				getline(s_stream, substr, ',');
				ints[j] = stoi(substr);
			}

			int k;
			int sum = 0;
			for (k = 0; k < 3; ++k) {
				sum += ints[k];
			}

			cout << "Student " << studentID << " average number of days in three courses: " << sum / 3 << endl;
			return;
		}
	}

	cout << "Error: StudentID " << studentID << " not found." << endl;
	return;
};


// Requirement E3E: Verifies all student email addresses and displays all invalid email addresses to the user
// isValidEmail() checks if a string is a vaild email, printValidEmails() prints if this functions returns true

bool isValidEmail(string email) {

	bool atSymbol = false;
	bool period = false;

	int i;
	for (i = 0; i < email.length(); ++i) {
		
		if (email.at(i) == ' ') {
			return false;
		}

		else if (email.at(i) == '@') {
			atSymbol = true;
		}

		else if (email.at(i) == '.') {
			period = true;
		}
	}

	return atSymbol && period;

}

void Roster::printInvalidEmails() {
	
	int i;
	for (i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); ++i) {
		
		string email = classRosterArray[i]->getEmailAddress();
		if (!isValidEmail(email)) {
			
			cout << "Student "<< classRosterArray[i]->getStudentID() << "'s email: '" << email << "' is invalid." << endl;
		}
	}

	cout << endl;
	return;
};


// Requirement E3F: Print out student information for a degree program specified by an enumerated type

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	
	int i;
	for (i = 0; i < sizeof(classRosterArray) / sizeof(classRosterArray[0]); ++i) {
		DegreeProgram checkProgram = classRosterArray[i]->getDegreeProgram();

		if (checkProgram == degreeProgram) {
			classRosterArray[i]->print();

		}
	}
	return;
};


// Requirement E2A & E2B: Parse the strings in studentData array
// Populate classRosterArray with student objects using add()

Roster::Roster() {

	string data[9];
	int ints[4] = {0, 0, 0, 0};
	DegreeProgram studentDegree;

	int i;
	int j;
	for (j = 0; j < sizeof(classRosterArray) / sizeof(classRosterArray[0]); ++j) {

		stringstream s_stream(studentData[j]);

		for (i = 0; i < 9; ++i) {

			string substr;
			getline(s_stream, substr, ',');
			data[i] = substr;

			if ((i > 3) && (i < 8)) {
				ints[i - 4] = stoi(data[i]);
			}

			else if (i == 8) {
				if (data[i] == "SECURITY") {
					studentDegree = DegreeProgram::SECURITY;
				}
				else if (data[i] == "NETWORK") {
					studentDegree = DegreeProgram::NETWORK;
				}
				else if (data[i] == "SOFTWARE") {
					studentDegree = DegreeProgram::SOFTWARE;
				}
				else {
					cout << "Invalid degree program" << endl;
				}
			}
		}

		this->add(data[0], data[1], data[2], data[3], ints[0], ints[1], ints[2], ints[3], studentDegree);
	}
};


// Requirement F5: Roster memory released with destructor

Roster::~Roster() {
	
	int i;
	for (i = 0; i < (sizeof(classRosterArray) / sizeof(classRosterArray[0])); ++i) {
		delete classRosterArray[i];
	}

}

