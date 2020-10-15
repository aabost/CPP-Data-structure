#ifndef SIMULATION_H
#define SIMULATION_H

#include "ServerList.h"
#include <queue>

void setSimulationParameters(int& simulationTime, int& numOfServers,
	int& transactionTime,
	int& timeBetweenCustomerArrival);

bool isCustomerArrived(double arrivalTimeDifference);

void generateStatistics(ServerList& serverList,
	std::queue<CustomerType>& customerQueue,
	int numOfCustomersArrived,
	int waitTimeServedCustomers);

void runSimulation();

void updateCustQueue(std::queue<CustomerType>& customerQueue);
void printSimulationParameters(int simulationTime, int numOfServers,
	int transactionTime,
	int timeBetweenCustomerArrival);
#endif SIMULATION_H