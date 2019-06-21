#pragma once
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include <iostream>
#include <string>
using namespace std;

class Roster {
public:
	//Array of pointers
	Student *classRosterArray[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };

	//Create a student object for each student using subclasses

	//Functions
	void add(string ID, string FN, string LN, string EM, int a, int t1, int t2, int t3, Degree d);
	void remove(string ID);							//removes student from roster by ID; if doesn't exist, create an error message
	void printAll();								//tab-separated list of student data using accessor functions
	void printDaysInCourse(string ID);				//correctly prints student's AVERAGE number of days in three courses
	void printInvalidEmails();						//verify student emails. display all invalid (must have @ and '.', no spaces)
	void printByDegreeProgram(int d);				//prints out student info 


	~Roster();
};