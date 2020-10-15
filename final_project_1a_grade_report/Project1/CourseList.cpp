/************************
	Xcoders

	Dawson, Tallis
	Le, Emily
	Bostouros, Abanob
	Tran, Nathan

	CS A250 - Fall 2019

	Project 1
*************************/

#include "CourseList.h"

using namespace std;

const int CourseList::CAP = 10;

CourseList::CourseList() 
{
	capacity = CAP;
	totalCourses = 0;
	courseList = new Course[capacity];
}

CourseList::CourseList(int newCap) 
{
	capacity = newCap;
	totalCourses = 0;
	courseList = new Course[capacity];
}

CourseList::CourseList(const CourseList& otherList) 
{
	capacity = otherList.capacity;
	totalCourses = otherList.totalCourses;
	courseList = new Course[capacity];

	for (int i = 0; i < capacity; i++) 
	{
		courseList[i] = otherList.courseList[i];
	}
}

void CourseList::addCourse(const Course& newCourse)
{
	if (totalCourses + 1 >= capacity) 
	{
		resize();
	}

	courseList[++totalCourses] = newCourse;
}

double CourseList::getCourseUnits(const string& prefix,
	int number) const
{
	for (int i = 0; i < capacity; i++) 
	{
		if (courseList[i].getCoursePrefix() == prefix
			&& courseList[i].getCourseNo() == number) 
		{
			return courseList[i].getCourseUnits();
		}
	}

	return 0.0;
}

bool CourseList::searchCourse(const string& prefix, int number) const 
{
	int i = 0;
	while (i < capacity) 
	{
		if (courseList[i].getCoursePrefix() == prefix
			&& courseList[i].getCourseNo() == number)
		{
			return true;
		}

		i++;
	}

	return false;
}

CourseList& CourseList::operator=(const CourseList& otherList)
{
	if (&otherList != this)
	{
		if (capacity != otherList.capacity)
		{
			delete[] courseList;
			courseList = new Course[otherList.capacity];
			capacity = otherList.capacity;
		}

		for (int i = 0; i < capacity; i++)
		{
			courseList[i] = otherList.courseList[i];
		}

		totalCourses = otherList.totalCourses;
	}
	else
	{
		cerr << "Attempted assignment to self.";
	}

	return *this;
}

CourseList::~CourseList() 
{
	delete[] courseList;
	courseList = nullptr;
}

void CourseList::resize() 
{
	Course* temp = new Course[capacity * 2];
	for (int i = 0; i < capacity; i++) 
	{
		temp[i] = courseList[i];
	}

	delete[] courseList;
	courseList = temp;
	temp = nullptr;
	capacity *= 2;
}