/************************
	Xcoders

	Dawson, Tallis
	Le, Emily
	Bostouros, Abanob
	Tran, Nathan

	CS A250 - Fall 2019

	Project 1
*************************/

#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

class CourseList
{
public:

	CourseList();
	CourseList(int); 
	CourseList(const CourseList&);

	void addCourse(const Course&);

	double getCourseUnits(const std::string&, int) const;

	bool searchCourse(const std::string&, int) const;

	CourseList& operator=(const CourseList&);

	~CourseList();

private:
	Course* courseList;	
	int totalCourses;
	int capacity;
	static const int CAP;

	void resize();
};

#endif