#include "pch.h"
#include "softwareStudent.h"


softwareStudent::softwareStudent(){}

softwareStudent::softwareStudent(string ID, string FN, string LN, string EM, int a, int *t, Degree d) 
	: Student(ID, FN, LN, EM, a, t) {
	degreeType = d;
}

Degree softwareStudent::getDegreeProgram() {
	return degreeType;
}

softwareStudent::~softwareStudent(){}
