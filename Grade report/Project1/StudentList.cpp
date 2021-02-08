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

using namespace std;

StudentList::StudentList() 
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

StudentList::StudentList(const StudentList& list)
{
	first = nullptr;
	last = nullptr;
	count = list.count;
	copyCallingObjectEmpty(list);
}

StudentList& StudentList::operator=(const StudentList& list)
{
	if (&list != this) // make sure objects are distinct
	{
		// parameter object is empty
		if (list.first == nullptr)
			destroyStudentList();
		// calling object is empty
		else if (first == nullptr)
			copyCallingObjectEmpty(list);
		// lists have the SAME number of nodes
		else if (count == list.count)
			copyCallingObjectSameLen(list);
		// calling object has MORE nodes than the parameter object
		else if (count > list.count)
			copyCallingObjectLonger(list);
		// calling object has LESS nodes than the parameter object
		else
			copyCallingObjectShorter(list);

		count = list.count;
	}
	else
		cerr << "Attempted assignment to itself." << endl;

	return *this;
}

void StudentList::addStudent(const Student& newStudent)
{
	if (count == 0)
	{
		first = new Node(newStudent, nullptr);
		last = first;
	}
	else
	{
		first = new Node(newStudent, first);
	}

	++count;
}

int StudentList::getNoOfStudents() const
{
	return count;
}

void StudentList::printStudentByID(int studentID) const
{
	if (count == 0)
	{
		cerr << "List is empty.";
	}
	else
	{
		Node* current = first;
		bool found = false;

		while (current != nullptr)
		{
			if ((current->getStudent()).getID() == studentID)
			{
				(current->getStudent()).printStudentInfo();
				current = nullptr;
				found = true;
			}
			else
				current = current->getNext();
		}

		if (!found)
		{
			cout << "No student with ID " <<
				studentID << " found in the list." << endl;
		}
	}
}

void StudentList::printStudentsByCourse(const string& cPre, 
	int cNum) const
{
	if (count == 0)
		cerr << "List is empty.";
	else
	{
		Node* curr = first;
		bool found = false;

		while (curr != nullptr)
		{
			if (curr->getStudent().getNumberOfCourses() > 0)
			{
				if (curr->getStudent().courseIsCompleted(cPre, cNum))
				{
					curr->getStudent().printStudent(); 
					found = true;
				}
			}

			curr = curr->getNext();
		}

		if (!found) cout << "No student completed " << cNum << endl;
	}
}

void StudentList::printStudentByName(const string& lastName) const
{
	if (count == 0)
	{
		cerr << "List is empty.";
	}
	else
	{
		Node* current = first;
		bool found = false;

		while (current != nullptr)
		{
			if ( (current->getStudent()).Person::getLastName() == lastName)
			{
				(current->getStudent()).printStudent();
				found = true;
			}

			current = current->getNext();
		}

		if (!found)
		{
			cout << "No student with last name " 
				<< lastName << " is in the list." <<endl;
		}
	}
}

void StudentList::printStudentsOnHold() const
{
	if (count == 0)
		cerr << "List is empty.";
	else
	{
		Node* curr = first;
		bool found = false;

		while (curr != nullptr)
		{
			if (!(curr->getStudent().isTuitionPaid()))
			{
				curr->getStudent().printStudentInfo(); 
				found = true;
			}

			curr = curr->getNext();
		}

		if (!found) cout << "There are no students on hold." << endl;
	}
}

void StudentList::printAllStudents() const
{
	if (count == 0)
		cerr << "List is empty.";
	else
	{
		Node* curr = first;

		while (curr != nullptr)
		{
			curr->getStudent().printStudentInfo();
			curr = curr->getNext();
		}
	}
}

void StudentList::destroyStudentList()
{
	last = first;

	while (first != nullptr)
	{
		first = first->getNext();
		delete last;
		last = first;
	}

	count = 0;
}

StudentList::~StudentList()
{
	destroyStudentList();
}

void StudentList::copyCallingObjectEmpty(const StudentList& list)
{
	Node* temp = list.first;

	while (temp != nullptr)
	{
		addStudent(temp->getStudent());
		temp = temp->getNext();
	}
}

void StudentList::copyCallingObjectSameLen(const StudentList& list)
{
	Node* myTemp = first;
	Node* listTemp = list.first;

	while (listTemp != nullptr)
	{
		myTemp->setStudent(listTemp->getStudent());
		myTemp = myTemp->getNext();
		listTemp = listTemp->getNext();
	}
}

void StudentList::copyCallingObjectShorter(const StudentList& list)
{
	Node* myTemp = first;
	Node* listTemp = list.first;

	for (int i = count; i > 0; i--)
	{
		myTemp->setStudent(listTemp->getStudent());
		myTemp = myTemp->getNext();
		listTemp = listTemp->getNext();
	}

	do
	{
		addStudent(listTemp->getStudent());
		listTemp = listTemp->getNext();
	} while (listTemp != nullptr);
}

void StudentList::copyCallingObjectLonger(const StudentList& list)
{
	Node* temp = first;
	Node* trailTemp = list.first;

	while (trailTemp != nullptr)
	{
		temp->setStudent(trailTemp->getStudent());
		trailTemp = trailTemp->getNext();
		if (trailTemp != nullptr) temp = temp->getNext();
	}

	last = temp;

	temp = temp->getNext();
	trailTemp = temp;

	last->setNext(nullptr);

	// Using the ptr used to point to the other list in deleting the extra nodes 

	while (trailTemp != nullptr)
	{
		trailTemp = trailTemp->getNext();
		delete temp;
		temp = trailTemp;
	}

}