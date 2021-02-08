/************************
	Xcoders

	Dawson, Tallis
	Le, Emily
	Bostouros, Abanob
	Tran, Nathan

	CS A250 - Fall 2019

	Project 1
*************************/

#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class Course
{
public:
	
	Course();
	
	void setCourseInfo(const std::string&,
		const std::string&, int, double);
	
	std::string getCourseName() const;
	std::string getCoursePrefix() const;
	int getCourseNo() const;
	double getCourseUnits() const;

	void printCourseInfo() const;

	bool operator<(const Course&) const;

	~Course();

private:
	std::string courseName;
	std::string coursePrefix;
	int courseNo;
    double courseUnits;
};

#endif