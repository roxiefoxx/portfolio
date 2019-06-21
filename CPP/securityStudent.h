#pragma once
#ifndef SECURITY_H
#define SECURITY_H
#include "student.h"
class securityStudent :	public Student {
public:
	securityStudent();
	securityStudent(string ID, string FN, string LN, string EM, int a, int *t, Degree d);
	virtual Degree getDegreeProgram();
	~securityStudent();
private:
	Degree degreeType = SECURITY;
};

#endif