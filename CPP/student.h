#pragma once
#include <iostream>
#include <string>
using namespace std;

class Student{
	public:
		Student();				//default constructor
		~Student();				//default destructor

		void setStudentID();
		string getStudentID();

	private:
		string studentID;

};

