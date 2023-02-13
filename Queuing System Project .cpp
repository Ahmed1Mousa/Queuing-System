#include<iostream>
using namespace std;
#include<queue>
class Customer {
public:
    // Constructor for the Customer class
    Customer ( int expected_arrival_time, int transaction_time ) : expected_arrival_time_ ( expected_arrival_time ), transaction_time_ ( transaction_time ) {}

    // Getter for the expected arrival time
    int getExpectedArrivalTime ( ) const { return expected_arrival_time_; }

    // Getter for the transaction time
    int getTransactionTime ( ) const { return transaction_time_; }

private:
    int expected_arrival_time_;  // expected arrival time of the customer
    int transaction_time_;       // service time, or the time it takes to serve the customer
};

// Server class represents an object that provides service to customers
class Server {
public:
    // Constructor for the Server class
    Server ( ) : transaction_time_ ( 0 ) {}

    // Getter for the transaction time
    int getTransactionTime ( ) const { return transaction_time_; }

    // Setter for the transaction time
    void setTransactionTime ( int transaction_time ) { transaction_time_ = transaction_time; }

    // Serve the customer
    void serve ( Customer& customer ) {
        // Update the transaction time for this server
        transaction_time_ = customer.getTransactionTime ( );
        // Serve the customer
        // ...
    }

private:
    int transaction_time_;  // service time, or the time it takes to serve a customer
};

// Customer class represents an object that receives service from a server


// Queue class represents a FIFO queue of customers waiting to be served
class Queue {
public:
    // Push a customer into the queue
   // queue
    void push ( const Customer& customer ) {
        queue_.push_back ( customer );
    }

    // Pop a customer from the queue
    Customer pop ( ) {
        Customer customer = queue_.front ( );
        queue_.pop_front ( );
        return customer;
    }

    // Check if the queue is empty
    bool empty ( ) const {
        return queue_.empty ( );
    }

    int size ( ) {
        return queue_.size ( );
    }

private:
    std::deque<Customer> queue_;  // internal queue data structure
};

// Model class represents the queuing system that consists of a list of servers and a waiting queue
class Model {
public:
    // Constructor for the Model class
    Model ( int num_servers, int time_between_arrivals ) : num_servers_ ( num_servers ), time_between_arrivals_ ( time_between_arrivals ), time_ ( 0 ) {
        for ( int i = 0; i < num_servers; i++ ) {
            Server server;
            available_servers_.push_back ( server );
        }
    }

    // Add a customer to the system
    void addCustomer (  Customer& customer ) {
        // Check if there are any available servers
        if ( available_servers_.empty ( ) ) {
            // If there are no available servers, add the customer to the waiting queue
            waiting_queue_.push ( customer );
        }
        else {
            // If there is an available server, get the next available server and serve the customer
            Server& server = available_servers_.front ( );
            available_servers_.pop_back ( );
            server.serve ( customer );
            working_servers_.push_front ( server );
        }
    }
    void updateServer ( ) {
        std::deque<Server> temp;
        Server server;
        while ( !available_servers_.empty ( ) && !waiting_queue_.empty() )
        {
            server = available_servers_.front ( );
            available_servers_.pop_front ( );
            Customer c = waiting_queue_.pop ( );
            server.serve ( c );
            working_servers_.push_back ( server );
        }
        while ( !working_servers_.empty ( ) ) {
            server = working_servers_.front ( );
            server.setTransactionTime ( server.getTransactionTime ( ) - 1 );
            if ( server.getTransactionTime ( ) == 0 )
            {
                available_servers_.push_back ( server );
            }
            else
            {
                temp.push_back ( server );
            }
            working_servers_.pop_front ( );
        }
        while ( !temp.empty ( ) ) {
            server = temp.front ( );
            working_servers_.push_back ( server );
            temp.pop_front ( );
        }
    }

    void printData ( ) {
        cout << "Number of Available Servers = " << available_servers_.size ( ) << endl;
        cout << "Number of Busy Servers =      " << working_servers_.size ( ) << endl;
        cout << "Number of Waiting Cutomers =  " << waiting_queue_.size ( ) << endl;
        cout << "----------------------------------------------------------------" << endl;
    }
private:
    std::deque<Server> available_servers_;
    std::deque<Server> working_servers_;

    Queue waiting_queue_;
    int num_servers_;
    int time_between_arrivals_;
    int time_;
};



int main( ){
    int clk = 0;
    int num_servers;
    int time_between_arrivals;
    cout << "Please enter number of servers: ";
    cin >> num_servers;
    cout << "Please enter time between arrivals in miutes: ";
    cin >> time_between_arrivals;

    Model m ( num_servers, time_between_arrivals );
    Customer c ( 20, 20 );

    cout << "Press enter to simulate the system" << endl;
    cin.get ( );
    while ( true ) {
        if ( clk % time_between_arrivals == 0 )
        {
            m.addCustomer ( c );
        }
        if ( clk % 10 == 0 )
        {
            cout << endl;
            cin.get ( );
            cout << "After " << clk << " minutes" << endl;
            m.printData ( );

        }
        m.updateServer ( );
        clk++;

    }

    return 0;
}
