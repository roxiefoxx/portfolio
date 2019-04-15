#include "pch.h"
#include "student.h"

//constructor
Student::Student()
{
}
//mutator
void Student::setStudentID(string ID) {
	studentID = ID;
}
//accessor
void Student::getStudentID() {
	return studentID;
}
//destructor
Student::~Student()
{
}
