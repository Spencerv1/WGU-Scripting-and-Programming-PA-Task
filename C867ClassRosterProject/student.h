#pragma once

#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <array>
#include "degree.h"
using namespace std;

// Requirement D1: Student class

class Student {
	public:

		// Overloaded constructor 
		Student(
			string studentID, 
			string firstName, 
			string lastName, 
			string emailAddress, 
			int age, 
			string daysInCourses, 
			DegreeProgram degreeProgram
		);

		// Default constructor
		Student();


		// Requirement D2A: Accessors 

		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmailAddress();
		int getAge();
	    string getDaysInCourses();
		DegreeProgram getDegreeProgram();


		// Requirement D2B: Mutators 

		void setStudentID(string studentID);
		void setFirstName(string firstName);
		void setLastName(string lastName);
		void setEmailAddress(string emailAddress);
		void setAge(int age);
		void setDaysInCourses(string daysInCoursesd);
		void setDegreeProgram(DegreeProgram degreeProgram);

		void print();

	private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int age;
		string daysInCourses;
		DegreeProgram degreeProgram;
};

#endif