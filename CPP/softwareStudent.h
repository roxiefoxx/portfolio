#pragma once
#ifndef SOFTWARE_H
#define SOFTWARE_H
#include "student.h"
class softwareStudent :	public Student {
public:
	softwareStudent();
	softwareStudent(string ID, string FN, string LN, string EM, int a, int *t, Degree d);
	virtual Degree getDegreeProgram();
	~softwareStudent();
private:
	Degree degreeType = SOFTWARE;
};

#endif