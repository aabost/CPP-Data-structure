/************************
	Xcoders

	Dawson, Tallis
	Le, Emily
	Bostouros, Abanob
	Tran, Nathan

	CS A250 - Fall 2019

	Project 1
*************************/

#include "Person.h"

using namespace std;

Person::Person() 
{
	firstName = "N/A";
	lastName = "N/A";
}

Person::Person(const string& newFirst, const string& newLast) 
{
	firstName = newFirst;
	lastName = newLast;
}

void Person::setName(const string& newFirst, const string& newLast) 
{
	firstName = newFirst;
	lastName = newLast;
}

string Person::getLastName() const 
{
	return lastName;
}

void Person::printName() const 
{
	cout << lastName << ", " << firstName << endl;
}
 
Person::~Person() {}