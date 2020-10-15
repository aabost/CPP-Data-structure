/************************
	Xcoders

	Dawson, Tallis
	Le, Emily
	Bostouros, Abanob
	Tran, Nathan

	CS A250 - Fall 2019

	Project 1
*************************/

#include "StudentList.h"
#include "CourseList.h"
#include "Course.h"
#include "Student.h"

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>

using namespace std;

const char COURSE_DATA[] = "courses.txt";
const char STUDENT_DATA[] = "students.txt";

void createCourseList(ifstream& infileCourses, CourseList& courseList)
{
	string courseName, coursePrefix;
	int courseNo = 0;
	double courseUnits = 0.0;
	Course tempCourse;

	infileCourses >> courseName;

	while (courseName != "END")
	{
		infileCourses >> coursePrefix >> courseNo >> courseUnits;

		tempCourse.setCourseInfo(courseName, coursePrefix, 
			courseNo, courseUnits);
		courseList.addCourse(tempCourse);

		infileCourses >> courseName;
	}
}
void createStudentList(ifstream& infileStudents, 
	StudentList& studentList, CourseList& courseList)
{
	string fName, lName, courseName, coursePrefix;
	int id = 0,
		courseNo = 0,
		noOfCourses = 0;
	double courseUnits = 0.0;
	char isPaid = 'N', grade = 'N';
	bool isTuitionPaid = false;
	multimap<Course, char> coursesCompleted;

	Course tempCourse;
	Student tempStudent;
	
	infileStudents >> fName;

	while(fName != "END")
	{
		infileStudents >> lName >> id >> isPaid;

		isTuitionPaid = (isPaid == 'Y');

		infileStudents >> noOfCourses;

		for(int i = 0; i < noOfCourses; ++i)				
		{
			infileStudents >> courseName >> coursePrefix >> courseNo 
				>> courseUnits >> grade;
			tempCourse.setCourseInfo(courseName, coursePrefix, 
				courseNo, courseUnits);
			coursesCompleted.insert(make_pair(tempCourse, grade));
		}

		tempStudent.setStudentInfo(fName, lName, id, 
			isTuitionPaid, coursesCompleted);	
		studentList.addStudent(tempStudent);					
		
		coursesCompleted.clear();

		infileStudents >> fName;
	}
}

void readData(CourseList& courseList, StudentList& studentList)
{
	ifstream infileCourses;
	infileCourses.open(COURSE_DATA);
	if (!infileCourses)
	{
		cerr << "Courses input file does not exist." << endl;
		system("Pause");
		exit(1);
	}

	createCourseList(infileCourses, courseList);
	infileCourses.close();

	ifstream infileStudents;
	infileStudents.open(STUDENT_DATA);
	if(!infileStudents)
	{
		cerr << "Student input file does not exist." << endl;
		system("Pause");
		exit(1);
	}

	createStudentList(infileStudents, studentList, courseList);
	infileStudents.close();
}
