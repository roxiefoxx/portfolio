#ifndef NETWORK_H
#define NETWORK_H
#pragma once
#include "student.h"
class networkStudent :	public Student {
public:
	networkStudent();
	networkStudent(string ID, string FN, string LN, string EM, int a, int *t, Degree d);
	virtual Degree getDegreeProgram();
	~networkStudent();
private:
	Degree degreeType = NETWORKING;
};

#endif


