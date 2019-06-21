#include "pch.h"
#include "student.h"

Student::Student(){}

Student::Student(string ID, string FN, string LN, string EM, int a, int *t)
	: 
	studentID(ID),
	firstName(FN),
	lastName(LN),
	emailAddress(EM),
	age(a)
{
	setDaysInCourse(t);
}
//ACCESSORS
string Student::getStudentID() {
	return studentID;
};
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
int * Student::getDaysInCourse() {
	return daysInCourse;
}
Degree Student::getDegreeType() {
	return degreeType;
}

//MUTATORS
void Student::setStudentID(string ID) {
	studentID = ID;
}
void Student::setFirstName(string FN) {
	firstName = FN;
}
void Student::setLastName(string LN) {
	lastName = LN;
}
void Student::setEmailAddress(string EM) {
	emailAddress = EM;
}
void Student::setAge(int a) {
	age = a;
}
void Student::setDaysInCourse(int *t) {		//sets the array
	for (int i = 0; i < 3; i++) {
		daysInCourse[i] = t[i];
	}
	daysInCourse1 = t[0];
	daysInCourse2 = t[1];
	daysInCourse3 = t[2];
}

void Student::setDegreeType(Degree d) {
	degreeType = d;
}

//OTHER FUNCTIONS
void Student::print() {
	int *daysInCourse = getDaysInCourse();
	//cout << getStudentID() << "\t";	//Class req E.3.a does not indicate studentID
	cout << "First Name: " << getFirstName() << "\t";
	cout << "Last Name: " << getLastName() << "\t";
	cout << "Age: " << getAge() << "\t";
	cout << "daysInCourse: {" << daysInCourse[0] << "," << daysInCourse[1] << "," << daysInCourse[2] << "}  ";
	cout << "Degree Program: ";			//Class req E.3.b does not show [tab] before this object
	switch (getDegreeProgram()) {
	case 0: cout << "Security";
		break;
	case 1: cout << "Networking";
		break;
	case 2: cout << "Software";
		break;
	case 3: cout << "None";
		break;
	}
	cout << endl;
}
Degree Student::getDegreeProgram() {
	return NONE;		//This will check if the subclasses override this function
}


Student::~Student()
{
}
