#include <string>
#include <array>
#include <iostream>
#include "student.h"
using namespace std;


// Requirement D2D: Constructor

// Default constructor definition
Student::Student() {
	setStudentID("");
	setFirstName("");
	setLastName("");
	setEmailAddress("");
	setAge(0);
	setDaysInCourses("");
	return;
}

// Overloaded constructor definition
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, string daysInCourses, DegreeProgram degreeProgram) {
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setDaysInCourses(daysInCourses);
	setDegreeProgram(degreeProgram);
	return;
}


// Requirement D2C: Accessor definitions

string Student::getStudentID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmailAddress() {
	return emailAddress;
}

int Student::getAge() {
	return age;
}

string Student::getDaysInCourses() {
	return daysInCourses;
}

DegreeProgram Student::getDegreeProgram() {
	return degreeProgram;
}


// Requirement D2C: Mutator definitions

void Student::setStudentID(string studentID) {
	this->studentID = studentID;
	return;
}

void Student::setFirstName(string firstName) {
	this->firstName = firstName;
	return;
}

void Student::setLastName(string lastName) {
	this->lastName = lastName;
	return;
}

void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
	return;
}

void Student::setAge(int age) {
	this->age = age;
	return;
}

void Student::setDaysInCourses(string daysInCourses) {
	this->daysInCourses = daysInCourses;
	return;
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
	return;
}


// D2E: Printing student data

void Student::print() {
	cout << getStudentID() << '\t';
	cout << "First Name: " << getFirstName() << '\t';
	cout << "Last Name: " << getLastName() << '\t';
	cout << "Email: " << getEmailAddress() << '\t';
	cout << "Age: " << getAge() << '\t';
	cout << "daysInCourse: {" << getDaysInCourses() << "}";

	switch (static_cast<int>(getDegreeProgram())) {
	case 0:
		cout << "SECURITY";
		break;
	case 1:
		cout << "NETWORK";
		break;
	case 2:
		cout << "SOFTWARE";
		break;
	default:
		cout << "No Degree Program";
		break;
	}

	cout << endl;
	return;
}