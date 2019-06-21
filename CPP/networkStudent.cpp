#include "pch.h"
#include "networkStudent.h"


networkStudent::networkStudent(){}

networkStudent::networkStudent(string ID, string FN, string LN, string EM, int a, int *t, Degree d)
	: Student(ID, FN, LN, EM, a, t) {
	degreeType = d;
}

Degree networkStudent::getDegreeProgram() {
	return degreeType;
}

networkStudent::~networkStudent(){}
