/************************
	Xcoders

	Dawson, Tallis
	Le, Emily
	Bostouros, Abanob
	Tran, Nathan

	CS A250 - Fall 2019

	Project 1
*************************/

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

class Person
{
public:

	Person();
	Person(const std::string&, const std::string&);
	
	void setName(const std::string&, const std::string&);
	
	std::string getLastName() const;

	void printName() const;

	~Person();

private:
	std::string firstName;
	std::string lastName;
};

#endif 