#include "student.h"
#include <iostream>
#include <utility>

Student::Student()
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (auto& courseDay : this->courseDays) courseDay = 0;
	this->degreeProgram = UNDECIDED;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int courseDays[],
                 DegreeProgram degreeProgram)
{
	this->studentID = std::move(studentID);
	this->firstName = std::move(firstName);
	this->lastName = std::move(lastName);
	this->emailAddress = std::move(emailAddress);
	this->age = age;
	for (auto i = 0; i < courseDaysArraySize; ++i) this->courseDays[i] = courseDays[i];
	this->degreeProgram = degreeProgram;
}

Student::~Student()
= default;

string Student::getStudentID() const { return this->studentID; }
string Student::getFirstName() const { return this->firstName; }
string Student::getLastName() const { return this->lastName; }
string Student::getEmailAddress() const { return this->emailAddress; }
int Student::getAge() const { return this->age; }
int* Student::getCourseDays() { return this->courseDays; }
DegreeProgram Student::getDegreeProgram() const { return this->degreeProgram; }

void Student::setStudentID(string studentID) { this->studentID = std::move(studentID); }
void Student::setFirstName(string firstName) { this->firstName = std::move(firstName); }
void Student::setLastName(string lastName) { this->lastName = std::move(lastName); }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = std::move(emailAddress); }
void Student::setAge(int age) { this->age = age; }

void Student::setCourseDays(int courseDays[])
{
	for (auto i = 0; i < courseDaysArraySize; i++) this->courseDays[i] = courseDays[i];
}

void Student::setDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::printHeader()
{
	cout << "Output format: Student ID|First Name|Last Name|Email Address|Age|Course Days|Degree Program" << '\t';
}

void Student::print()
{
	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getCourseDays()[0] << '\t';
	cout << this->getCourseDays()[1] << '\t';
	cout << this->getCourseDays()[2] << '\t';
	cout << DegreeProgramString[this->getDegreeProgram()] << '\t';
}
