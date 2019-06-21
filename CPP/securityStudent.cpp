#include "pch.h"
#include "securityStudent.h"


securityStudent::securityStudent(){}

securityStudent::securityStudent(string ID, string FN, string LN, string EM, int a, int *t, Degree d)
	: Student(ID, FN, LN, EM, a, t) {
	degreeType = d;
}

Degree securityStudent::getDegreeProgram() {
	return degreeType;
}

securityStudent::~securityStudent(){}
