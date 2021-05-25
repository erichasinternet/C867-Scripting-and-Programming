#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student
{
public:
	const static int courseDaysArraySize = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int courseDays[courseDaysArraySize];
	DegreeProgram degreeProgram;

public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays[],
	        DegreeProgram degreeProgram);
	~Student();

	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setCourseDays(int courseDays[]);
	void setDegreeProgram(DegreeProgram degreeProgram);


	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int* getCourseDays();
	DegreeProgram getDegreeProgram() const;

	static void printHeader();

	void print();
};
