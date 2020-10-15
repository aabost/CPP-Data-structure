#include "ServerType.h"

#include <iostream>

using namespace std;

	//setBusy
void ServerType::setBusy()
{
	status = "busy";
}

	//setFree
void ServerType::setFree()
{
	status = "free";
}

	//setTransactionTime
void ServerType::setTransactionTime(int t)
{
	transactionTime = t;
}

	//setTransactionTime
void ServerType::setTransactionTime()
{
	transactionTime = currentCustomer.getTransactionTime();
}

	//setCurrentCustomer
void ServerType::setCurrentCustomer(const CustomerType& theCurrentCustomer)
{
	currentCustomer = theCurrentCustomer;
}

	//getCurrentCustomerNumber
int ServerType::getCurrentCustomerNumber() const
{
	return currentCustomer.getCustomerNumber();
}

	//getCurrentCustomerArrivalTime
int ServerType::getCurrentCustomerArrivalTime() const
{
	return currentCustomer.getArrivalTime();
}

	//getCurrentCustomerWaitingTime
int ServerType::getCurrentCustomerWaitingTime() const
{
	return currentCustomer.getWaitingTime();
}

	//getCurrentCustomerTransactionTime
int ServerType::getCurrentCustomerTransactionTime() const
{
	return currentCustomer.getTransactionTime();
}

	//getRemainingTransactionTime
int ServerType::getRemainingTransactionTime() const
{
	return transactionTime;
}

	//decreaseTransactionTime
void ServerType::decreaseTransactionTime()
{
	transactionTime--;
}

	//isFree
bool ServerType::isFree() const
{
	return (status == "free");
}

	//destructor
ServerType::~ServerType()
{}