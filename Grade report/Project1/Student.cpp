/************************
	Xcoders

	Dawson, Tallis
	Le, Emily
	Bostouros, Abanob
	Tran, Nathan

	CS A250 - Fall 2019

	Project 1
*************************/

#include "Student.h"

using namespace std;

Student::Student()
{
	studentID = 0;
	totalCourses = 0;
	tuitionWasPaid = false;
}

void Student::setStudentInfo(const string& fName, const string& lName,
	int id, bool tPaid, const multimap<Course, char>& nCourse)
{
	Person::setName(fName, lName);
	studentID = id;
	coursesCompleted = nCourse;
	totalCourses = static_cast<int>(coursesCompleted.size());
	tuitionWasPaid = tPaid;
}

int Student::getID() const 
{
	return studentID;
}

int Student::getNumberOfCourses() const 
{
	return totalCourses;
}

double Student::getUnitsCompleted() const 
{
	double totalUnits = 0;
	for(auto elem : coursesCompleted) 
	{
		totalUnits += elem.first.getCourseUnits();
	}

	return totalUnits;
}

// summation ( units for every course *  course grade 
// ( ex. if A = 4, B = 3 ) )/ total units  
double Student::getGpa() const 
{
	double credErned = 0.0;
	for (auto elem : coursesCompleted)
	{
		switch (elem.second)
		{
			case 'A': credErned += 
				((elem.first.getCourseUnits()) * 4.0);
				break;
			case 'B': credErned += 
				((elem.first.getCourseUnits()) * 3.0);
				break;
			case 'C': credErned += 
				((elem.first.getCourseUnits()) * 2.0);
				break;
			case 'D': credErned += 
				((elem.first.getCourseUnits()) * 1.0);
				break;
			case 'F': credErned += 0.0;
				break;
			default: cerr << "Invalid Course Grade" << endl;
		}
	}

	return credErned / getUnitsCompleted();
}

bool Student::isTuitionPaid() const 
{
	return tuitionWasPaid;
}

bool Student::courseIsCompleted(const string& prefix, int number) const 
{
	bool found = false;
	auto courseIter = coursesCompleted.begin();
	auto courseEnd = coursesCompleted.end();

	while(!found && courseIter != courseEnd) 
	{
		found = (courseIter->first.getCoursePrefix() == prefix
			&& courseIter->first.getCourseNo() == number);
		++courseIter;
	}

	return found;
}

void Student::printStudent() const 
{
	cout << studentID << " - ";
	Person::printName();
}

void Student::printStudentInfo() const 
{
	cout << "Student Name: ";
	Person::printName();
	cout << endl;
	cout << "Student ID: " << studentID << endl;
	cout << "Number of courses completed: " << totalCourses << endl;
	cout << endl;
	cout << "Course";
	cout << setw(9) << "Units";
	cout << setw(10) << "Grade";
	cout << endl;

	if(tuitionWasPaid)
	{
		for (auto elem : coursesCompleted) 
		{
			elem.first.printCourseInfo();
			cout << setw(8) << elem.second;
			cout << endl;
		}
	}
	else 
	{
		for (auto elem : coursesCompleted) 
		{
				elem.first.printCourseInfo();
				cout << setw(10) << "***";
				cout << endl;
		}
	}
	cout << endl;

	cout << "Total number of unit hours: ";
	cout << static_cast<int>(getUnitsCompleted());
	cout << endl;

	if (tuitionWasPaid) 
	{
		cout << "Current Term GPA: ";
		cout << fixed << showpoint << setprecision(2);
		cout << showpoint << getGpa() << endl;
	}
	else 
	{
		cout << "*** Grades are being held "
			<< "for not paying the tuition. ***";
		cout << endl;
	}

	cout << endl;
	cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-";
	cout << endl;
	
}

Student::~Student() {}