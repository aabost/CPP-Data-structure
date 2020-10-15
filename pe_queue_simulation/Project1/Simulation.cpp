#include "Simulation.h"

#include <cstdlib>
#include <iomanip>
#include <cmath>

using namespace std;

void runSimulation()
{
	int  simulationTime, numOfServers,
		transactionTime, timeBetweenCustomerArrival;
	int custmerNumber, totalWaitingTime, aveWatitngTime, clock;
	int numberofCustmersArrived = 0, numberofCustmerServed = 0;
	int	leftWithservers = 0, servedWaitTime = 0, leftInQueue = 0;
	
	setSimulationParameters(simulationTime, numOfServers,
		transactionTime, timeBetweenCustomerArrival);

	queue<CustomerType> CustomersQueue;
	ServerList servers(numOfServers);

	for (clock = 1; clock <= simulationTime; ++clock)
	{
		servers.updateServers();
		
		if(!CustomersQueue.empty())
			updateCustQueue(CustomersQueue);
		if (isCustomerArrived(timeBetweenCustomerArrival))
		{
			CustomerType customer(CustomersQueue.size() + 1, clock,
				0, transactionTime);
			CustomersQueue.push(customer);
			numberofCustmerServed++;
			cout << "Customer number " << numberofCustmerServed
				<< " arrived at time unit " << clock << endl;
		}
		int freeServerID = servers.getFreeServerID();
		if (freeServerID != -1 && !CustomersQueue.empty())
		{
			CustomerType customer = CustomersQueue.front();
			CustomersQueue.pop();
			servedWaitTime += customer.getWaitingTime();
			servers.setServerBusy(freeServerID, customer);
		}
	}
	printSimulationParameters(simulationTime, numOfServers,
		transactionTime,
		timeBetweenCustomerArrival);
	generateStatistics(servers,
		CustomersQueue,
		numberofCustmersArrived,
		servedWaitTime);
}

void setSimulationParameters(int& simulationTime, int& numOfServers,
	int& transactionTime,
	int& timeBetweenCustomerArrival)
{
	cout << "Enter the simulation time: " << flush;
	cin >> simulationTime;
	cout << endl;

	cout << "Enter the number of servers: " << flush;
	cin >> numOfServers;
	cout << endl;

	cout << "Enter the transaction time: " << flush;
	cin >> transactionTime;
	cout << endl;

	cout << "Enter the time between customer arrivals: " << flush;
	cin >> timeBetweenCustomerArrival;
	cout << endl;
}

bool isCustomerArrived(double arrivalTimeDifference)
{
	double value = 0.0;

	value = static_cast<double> (rand()) / static_cast<double>(RAND_MAX);

	return (value > exp(-1.0 / arrivalTimeDifference));
}


void generateStatistics(ServerList& serverList,
	queue<CustomerType>& customerQueue,
	int numOfCustomersArrived,
	int waitTimeServedCustomers)
{
	int customersLeftInQueue = 0;

	int totalWaitTime = waitTimeServedCustomers;

	CustomerType customer;

	while (!customerQueue.empty())
	{
		customer = customerQueue.front();
		customerQueue.pop();
		totalWaitTime = totalWaitTime + customer.getWaitingTime();
		customersLeftInQueue++;
	}

	//Find number of customers left in servers
	int customersLeftInServers = serverList.getNumberOfBusyServers();
	//Find number of customers completely served
	int numberOfCustomersServed = numOfCustomersArrived -
		customersLeftInServers -
		customersLeftInQueue;

	double averageWaitTime = 0;

	cout << "Total wait time: " << totalWaitTime << endl;
	cout << "Number of customers who completed a transaction: "
		<< numberOfCustomersServed << endl;
	cout << "Number of customers left in the servers: "
		<< customersLeftInServers << endl;
	cout << "Number of customers left in the queue: " << customersLeftInQueue
		<< endl;

	if (numOfCustomersArrived > 0)  // If number of customers arrived is > 0
		averageWaitTime = (static_cast<double>(totalWaitTime)) / numOfCustomersArrived;

	cout << fixed << showpoint;
	cout << setprecision(2);
	cout << "Average wait time: " << averageWaitTime << endl;

	cout << "\n************** END SIMULATION *************" << endl;

}

void updateCustQueue(queue<CustomerType>& customerQueue)
{
	CustomerType customer;

	customer.setWaitingTime(-1);
	int wTime = 0;

	customerQueue.push(customer);

	while (wTime != -1)
	{
		customer = customerQueue.front();
		customerQueue.pop();
		wTime = customer.getWaitingTime();
		if (wTime != -1)
		{
			customer.incrementWaitingTime();
			customerQueue.push(customer);
		}
	}
}

void printSimulationParameters(int simulationTime, int numOfServers,
	int transactionTime,
	int timeBetweenCustomerArrival)
{
	cout << "Simulation ran for " << simulationTime << " time units\n";
	cout << "Number of servers: " << numOfServers << endl;
	cout << "Average transaction time: " << transactionTime << endl;
	cout << "Average arrival time difference between customers: "
		<< timeBetweenCustomerArrival << endl;
}