// degree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "roster.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include "stdafx.h"
using namespace std;

Student *classRosterArray[5] = {nullptr, nullptr, nullptr, nullptr, nullptr};

const int ARRAY_SIZE = 5; //sizeof(classRosterArray) / sizeof(classRosterArray[0]);

void Roster::add(string ID, string FN, string LN, string EM, int a, int t1, int t2, int t3, Degree d) {
	int t[3] = { t1, t2, t3 };
	for (int i = 0; i < ARRAY_SIZE; i++) {		//check to see if ++i or i++
		if (classRosterArray[i] == nullptr) {
			if (d == SECURITY) {
				classRosterArray[i] = new securityStudent(ID, FN, LN, EM, a, t, d);
			}
			else if (d == NETWORKING) {
				classRosterArray[i] = new networkStudent(ID, FN, LN, EM, a, t, d);
			}
			else if (d == SOFTWARE) {
				classRosterArray[i] = new softwareStudent(ID, FN, LN, EM, a, t, d);
			}
			else {
				classRosterArray[i] = new Student(ID, FN, LN, EM, a, t);
			}
			break;
		}
	}
}

void Roster::remove(string ID) {					//removes student from roster by ID; if doesn't exist, create an error message
	bool studentExists = false;
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if ((classRosterArray[i] != nullptr) && (classRosterArray[i]->getStudentID() == ID)) {
			classRosterArray[i] = nullptr;
			studentExists = true;
			break;
		}

	}
	if (studentExists == false) {
		std::cout << "**ERROR: Student #" << ID << " was removed or does not exist.**" << endl;
	}
	else { std::cout << "Student #" << ID << " was removed from roster." << endl; }
}

void Roster::printAll() {								//tab-separated list of student data using accessor functions
	std::cout << "Printing all student data..." << endl;
	
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (classRosterArray[i] != nullptr) {
			cout << i + 1 << "\t";
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

void Roster::printDaysInCourse(string ID) {		//correctly prints student's AVERAGE number of days in three courses
	int daySum = 0;							//FIXME: check if this goes inside FOR or IF statement or not
	float days = 3;
	float dayAvg = 0.00;
		for (int i = 0; i < ARRAY_SIZE; i++)			//i is student index
			if (classRosterArray[i] != nullptr && classRosterArray[i]->getStudentID() == ID) {
				int *studentsDays = classRosterArray[i]->getDaysInCourse();	//runs the function for chosen student and returns it as a pointer array
				for (int j = 0; j < days; j++) {		//iterates through days or just make a sum
					daySum += studentsDays[j];
				}
				dayAvg = daySum/days;						//This goes here to stay in scope.
				std::cout << "Average days in a course for student #" << ID << " is " << fixed<< setprecision(1) << dayAvg << "." << endl;
			}
}

void Roster::printInvalidEmails() {						//verify student emails. display all invalid (must have @ and '.', no spaces)
	for (int i = 0; i < ARRAY_SIZE; i++) {		//i is index for students
		string EM = "";
		if (classRosterArray[i] != nullptr) {	//error check
			EM = classRosterArray[i]->getEmailAddress();
			int emailLen = EM.length();
			bool validEM = true;				//assuming the email is correct

			for (int j = 0; j < emailLen; j++) {
				if (EM.find('@') == string::npos) {			//Go through letters and find if '@' is missing
					validEM = false;
				}
				if (EM.find(' ') != string::npos) { 		//Go through letters and find if ' 'exists 
					validEM = false;
				}
				if (EM.find('.', EM.find('@')) == string::npos) {			//Go through letters after '@' and find if '.' is missing
					validEM = false;
				}
			}
			if (!validEM) {								//Print out if FALSE, TRUE, FALSE
				std::cout << "Please check invalid email address: '"<<EM << "'"<< endl;
			}
		}
	}
	cout << endl;
}

void Roster::printByDegreeProgram(int d) {	//prints out student info 
	std::cout << "Students in selected program [ "<< d << " ]:" << endl;
	Degree check = NONE;
	if (d == 0) {
		check = SECURITY;
	}
	if (d == 1) {
		check = NETWORKING;
	}
	if (d == 2) {
		check = SOFTWARE;
	}
	for (int i = 0; i < ARRAY_SIZE; i++) {
		if (check == classRosterArray[i]->getDegreeProgram()) {
			cout << i + 1 << "\t";
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

Roster::~Roster(){
	cout << endl << "Class 'Roster' memory released." << endl;
}

int main() {
//1) Print out to screen the course title, programming language used, studentID and name
	std::cout <<  "***Scripting and Programming Applications - C867 Final**" << endl;
	std::cout <<  "***Written in C++ by SID #001027260 - Roxanne Aniceto***" << endl << endl;;

//2) create an roster object
	Roster classRoster;

//3) Add each student to classRoster
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Roxanne,Aniceto,ranicet@wgu.edu,33,17,14,90,SOFTWARE"
	};

	for (int i = 0; i < ARRAY_SIZE; i++) {
		string line = studentData[i];
		istringstream ss(line);
		string tempItem;
		string holdStuff[9];
		int count = 0;

		while (getline(ss, tempItem, ',')) {
			holdStuff[count] = tempItem;
			count+=1;
		}
		
	//FIXME: do stuff to convert strings into proper types (int, Degree)
		Degree whatDegree;
		if (holdStuff[8] == "SECURITY") {
			whatDegree = SECURITY;		}
		else if (holdStuff[8] == "NETWORK") {
			whatDegree = NETWORKING;	}
		else if (holdStuff[8] == "SOFTWARE") {
			whatDegree = SOFTWARE;		}
		else { whatDegree = NONE; }
	
		classRoster.add(holdStuff[0], holdStuff[1], holdStuff[2], holdStuff[3], stoi(holdStuff[4]), stoi(holdStuff[5]), stoi(holdStuff[6]), stoi(holdStuff[7]), whatDegree);
	}
	//Convert the pseudocode
	classRoster.printAll();
	classRoster.printInvalidEmails();
	//loop through classRosterArray and for each element:
		for (int i = 0; i < ARRAY_SIZE; i++) {
	
			classRoster.printDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
		}
		cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
