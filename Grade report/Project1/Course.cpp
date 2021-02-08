/************************
	Xcoders

	Dawson, Tallis
	Le, Emily
	Bostouros, Abanob
	Tran, Nathan

	CS A250 - Fall 2019

	Project 1
*************************/

#include "Course.h"

using namespace std;

Course::Course() 
{
	courseNo = 0;
	courseUnits = 0.0;
}

void Course::setCourseInfo(const string& newName, 
	const string& newPrefix, int newNo, double newUnits) 
{
	courseName = newName;
	coursePrefix = newPrefix;
	courseNo = newNo;
	courseUnits = newUnits;
}


string Course::getCourseName() const 
{
	return courseName;
}


string Course::getCoursePrefix() const 
{
	return coursePrefix;
}


int Course::getCourseNo() const 
{
	return courseNo;
}


double Course::getCourseUnits() const 
{
	return courseUnits;
}


void Course::printCourseInfo() const 
{
	cout << setw(3) << coursePrefix;
	cout << setw(4) << courseNo;
	cout << fixed << showpoint << setprecision(2);
	cout << setw(8) << courseUnits;
}

bool Course::operator<(const Course& otherCourse) const
{
	if (coursePrefix == otherCourse.coursePrefix)
	{
		return (courseNo < otherCourse.courseNo);
	}
	else
	{
		return (coursePrefix < otherCourse.coursePrefix);
	}
}

Course::~Course() {}