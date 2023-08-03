# Queuing-System
This is a C++ program that simulates a queuing system with multiple servers and a waiting queue. Customers arrive at the system at regular intervals and are served by available servers. If there are no available servers, the customer joins the waiting queue until a server becomes available.

## Overview
This queuing system simulation project demonstrates how customers are served by servers in a First-In-First-Out (FIFO) manner. The project includes classes for Customer, Server, Queue, and Model. It also contains a main function to run the simulation.

## Classes
#### Customer Class
Represents a customer with an expected arrival time and transaction time.

Constructor
cpp
Copy code
Customer(int expected_arrival_time, int transaction_time);
Public Methods
int getExpectedArrivalTime() const: Returns the expected arrival time of the customer.
int getTransactionTime() const: Returns the transaction time (service time) for the customer.
Server Class
Represents a server that provides service to customers.

Constructor
cpp
Copy code
Server();
Public Methods
int getTransactionTime() const: Returns the remaining transaction time for the server.
void setTransactionTime(int transaction_time): Sets the transaction time (remaining service time) for the server.
void serve(Customer& customer): Serves a customer by updating the server's transaction time.
Queue Class
Represents a FIFO queue of customers waiting to be served.

Public Methods
void push(const Customer& customer): Adds a customer to the end of the queue.
Customer pop(): Removes and returns the first customer from the queue.
bool empty() const: Checks if the queue is empty.
int size(): Returns the number of customers in the queue.
Model Class
Represents the queuing system that consists of a list of servers and a waiting queue.

Constructor
cpp
Copy code
Model(int num_servers, int time_between_arrivals);
Public Methods
void addCustomer(Customer& customer): Adds a customer to the system, either serving them immediately or adding them to the waiting queue if no servers are available.
void updateServer(): Updates the transaction time for servers and moves them between available and working states based on the remaining transaction time.
void printData(): Prints the current system data, including the number of available servers, busy servers, and waiting customers.
How to Run
Clone the repository to your local machine.
Navigate to the project directory in the terminal.
Compile the C++ code using a C++ compiler:
bash
Copy code
g++ main.cpp -o queuing_system_simulation
Run the executable:
bash
Copy code
./queuing_system_simulation
Follow the on-screen instructions to input the number of servers and the time between customer arrivals.
The simulation will start, and you will see the system's state displayed at regular intervals (every 10 minutes in this example).
Contributions
Contributions to this queuing system simulation project are welcome. Feel free to create issues, fork the repository, and submit pull requests to propose changes or enhancements.

License
This project is licensed under the MIT License - see the LICENSE file for details.

Disclaimer: This code is provided as a basic simulation example and might not cover all real-world scenarios. Use it for educational and learning purposes only.




