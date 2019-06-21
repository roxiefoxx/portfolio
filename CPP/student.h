#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <iostream>
#include <string>
using namespace std;

class Student{
public:
	//CONSTRUCTOR
	Student();				//Do I want to make this an abstract class?
	Student(string ID, string FN, string LN, string EM, int a, int *t);

	//ACCESSORS
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int *getDaysInCourse();
	Degree getDegreeType();

	//MUTATORS
	void setStudentID(string ID);
	void setFirstName(string FN);
	void setLastName(string LN);
	void setEmailAddress(string EM);
	void setAge(int a);
	void setDaysInCourse(int *t);
	void setDegreeType(Degree d);

	//OTHER FUNCTIONS
	virtual void print();
	virtual Degree getDegreeProgram();

	//DESTRUCTOR
	~Student();
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	int daysInCourse1;
	int daysInCourse2;
	int daysInCourse3;
	Degree degreeType = NONE;		//This will be replaced by subclass. Should it be a pure virtual function?
};

#endif