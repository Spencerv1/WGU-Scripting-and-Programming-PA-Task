#pragma once
#include <string>
#include "student.h"
using namespace std;




const string studentData[] =
{ 
"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
"A5,Spencer,Verhoff,spencer@verhoff.net,19,25,30,20,SOFTWARE",
};


class Roster {
public:

	// Requirement E1: Array of pointers to hold studentData Table
	Student* classRosterArray[sizeof(studentData) / sizeof(studentData[0])] = { nullptr, nullptr, nullptr, nullptr, nullptr };

	Roster();

	~Roster();

	void add(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysInCourse1,
		int daysInCourse2,
		int daysInCourse3,
		DegreeProgram degreeprogram
	);

	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);

};