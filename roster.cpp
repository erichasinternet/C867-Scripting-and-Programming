#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <iostream>
#include <utility>


Roster::Roster()
{
	this->index = -1;
	this->rosterSize = 0;
	this->classRosterArray = nullptr;
}

Roster::Roster(int rosterSize)
{
	this->rosterSize = rosterSize;
	this->index = -1;
	this->classRosterArray = new Student*[rosterSize];
}

void Roster::parseAndAdd(const string& row)
{
	if (index < rosterSize)
	{
		index++;
	}

	int rLimit = row.find(',');
	const auto studentID = row.substr(0, rLimit);

	auto lLimit = rLimit + 1;
	rLimit = row.find(',', lLimit);
	const auto firstName = row.substr(lLimit, rLimit - lLimit);

	lLimit = rLimit + 1;
	rLimit = row.find(',', lLimit);
	const auto lastName = row.substr(lLimit, rLimit - lLimit);

	lLimit = rLimit + 1;
	rLimit = row.find(',', lLimit);
	const auto emailAddress = row.substr(lLimit, rLimit - lLimit);

	lLimit = rLimit + 1;
	rLimit = row.find(',', lLimit);
	const auto tempAge = row.substr(lLimit, rLimit - lLimit);
	const auto age = stoi(tempAge);

	lLimit = rLimit + 1;
	rLimit = row.find(',', lLimit);
	const auto daysInCourse1 = stoi(row.substr(lLimit, rLimit - lLimit));

	lLimit = rLimit + 1;
	rLimit = row.find(',', lLimit);
	const auto daysInCourse2 = stoi(row.substr(lLimit, rLimit - lLimit));

	lLimit = rLimit + 1;
	rLimit = row.find(',', lLimit);
	const auto daysInCourse3 = stoi(row.substr(lLimit, rLimit - lLimit));

	lLimit = rLimit + 1;
	rLimit = row.find(',', lLimit);
	DegreeProgram degreeProgram;
	const auto degreeStr = row.substr(lLimit, rLimit - lLimit);
	if (degreeStr == "NETWORK")
	{
		degreeProgram = NETWORK;
	}
	else if (degreeStr == "SECURITY")
	{
		degreeProgram = SECURITY;
	}
	else if (degreeStr == "SOFTWARE")
	{
		degreeProgram = SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

bool Roster::remove(const string& studentID)
{
	auto found = false;
	for (auto i = 0; i < index; ++i)
	{
		if (classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			delete this->classRosterArray[i];
			cout << "Student with ID " << studentID << " removed." << endl;
			classRosterArray[i] = classRosterArray[index];
			index--;
		}
	}
	if (!found)
	{
		cout << "Student with ID " << studentID << " not found." << endl;
	}
	return found;
}

void Roster::printAll() const
{
	for (auto i = 0; i <= index; ++i)
	{
		classRosterArray[i]->print();
	}
}

void Roster::printAverageDaysInCourse(const string& studentID) const
{
	auto average = 0;

	for (auto i = 0; i < 5; ++i)
	{
		auto tempID = classRosterArray[i]->getStudentID();
		if (tempID == studentID)
		{
			average = ((classRosterArray[i]->getCourseDays()[0] + classRosterArray[i]->getCourseDays()[1] +
				classRosterArray[i]->getCourseDays()[2]) / 3);
			cout << "Student ID " << studentID << " average: " << average << endl;
		}
	}
}

void Roster::printInvalidEmails() const
{
	for (auto i = 0; i < 5; ++i)
	{
		auto tempEmail = classRosterArray[i]->getEmailAddress();
		if ((tempEmail.find('@') == string::npos || tempEmail.find('.') == string::npos) || (tempEmail.find(' ') !=
			string::npos))
		{
			cout << tempEmail << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degree) const
{
	for (auto i = 0; i < 5; ++i)
	{
		const auto tempDegree = classRosterArray[i]->getDegreeProgram();
		if (tempDegree == degree)
		{
			classRosterArray[i]->print();
		}
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,
                 int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) const
{
	int daysInCourse[Student::courseDaysArraySize];

	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;

	classRosterArray[index] = new Student(std::move(studentID), std::move(firstName), std::move(lastName),
	                                      std::move(emailAddress), age, daysInCourse,
	                                      degreeProgram);
}

Student* Roster::getStudentAt(int index) const
{
	return classRosterArray[index];
}

Roster::~Roster()
{
	for (auto i = 0; i < 5; ++i)
	{
		delete classRosterArray[i];
	}
	delete classRosterArray;
}
