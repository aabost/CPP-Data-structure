/************************
	Xcoders

	Dawson, Tallis
	Le, Emily
	Bostouros, Abanob
	Tran, Nathan

	CS A250 - Fall 2019

	Project 1
*************************/

#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include "Course.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <map>
#include <iterator>
#include <fstream>
#include <string>

class Student: public Person
{
public:

	Student();

	void setStudentInfo(const std::string&, const std::string&, 
		int, bool, const std::multimap<Course, char>&);

	int getID() const;
	int getNumberOfCourses() const;
	double getUnitsCompleted() const;
	double getGpa() const;
 
	bool isTuitionPaid() const;
	bool courseIsCompleted(const std::string&, int) const;

	void printStudent() const;
	void printStudentInfo() const;

	~Student();

private:
    int studentID;				
    bool tuitionWasPaid;
	int totalCourses;
	std::multimap<Course, char> coursesCompleted;
};

#endif