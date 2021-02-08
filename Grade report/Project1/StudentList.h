/************************
	Xcoders

	Dawson, Tallis
	Le, Emily
	Bostouros, Abanob
	Tran, Nathan

	CS A250 - Fall 2019

	Project 1
*************************/

#ifndef STUDENTLIST_H
#define STUDENTLIST_H

#include "Student.h"

#include <iostream>
#include <string>

class Node
{
public:
	Node( ): student( ), next(nullptr) {} 
    Node(const Student& newStudent, Node *newNext) 
		: student(newStudent), next(newNext){}
    Student getStudent( ) const { return student; }
	Node* getNext( ) const { return next; }	
    void setStudent(const Student& newStudent) { student = newStudent; }
	void setNext(Node *newNext) { next = newNext; }
private:
    Student student;	
    Node *next;		
};

class StudentList
{
public:

	StudentList();
	StudentList(const StudentList&);

	StudentList& operator=(const StudentList&);

	void addStudent(const Student&);

	int getNoOfStudents() const;
 
	void printStudentByID(int) const;
	void printStudentsByCourse(const std::string&, int) const;
	void printStudentByName(const std::string&) const;
	void printStudentsOnHold() const;
	void printAllStudents() const;

	void destroyStudentList();

	~StudentList();

private:
	Node *first;
	Node *last;
	int count;

	void copyCallingObjectEmpty(const StudentList&);
	void copyCallingObjectShorter(const StudentList&);
	void copyCallingObjectSameLen(const StudentList&);
	void copyCallingObjectLonger(const StudentList&);

};

#endif