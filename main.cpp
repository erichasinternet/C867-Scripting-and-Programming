#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"


int main()
{
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Eric,Lawson,elaws21@wgu.edu,23,32,19,21,SOFTWARE"
	};

	const auto numStudents = 5;

	auto* classRoster = new Roster(numStudents);


	cout << "C867 Scripting and Programming Applications" << endl;

	cout << "Programmed in C++ by Eric Lawson - Student ID: #001009860" << endl;

	cout << endl;

	for (const auto& i : studentData)
	{
		classRoster->parseAndAdd(i);
	}

	cout << "Students:" << endl;
	classRoster->printAll();


	cout << endl;

	cout << "Invalid student emails:" << endl;
	classRoster->printInvalidEmails();

	cout << endl;

	cout << "Average days in course:" << endl;
	for (auto i = 0; i < numStudents; i++)
	{
		classRoster->printAverageDaysInCourse(classRoster->getStudentAt(i)->getStudentID());
	}

	cout << endl;

	cout << "Students studying software: " << endl;
	classRoster->printByDegreeProgram(SOFTWARE);

	cout << endl;

	classRoster->remove("A3");

	cout << endl;

	classRoster->printAll();

	cout << endl;

	classRoster->remove("A3");

	system("pause");

	return 0;
}
