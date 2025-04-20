#include "MyCircularQueue.h"
#include "Customer.h"
int main() {
	int size;
	cout << "Enter maximum number of Customers at a time: ";
	cin >> size;
    cin.ignore();
    MyCircularQueue <Customer> waitingQueue(size);
    
    Customer** allCustomers = new Customer * [size];//array of pointers
    for (int i = 0; i < size; ++i) {
        allCustomers[i] = nullptr;  // initialize all to nullptr
    }
        
    int currentAddedCustomers = 0;  // how many customers have been added
    string name;
    int choice;
    Customer* c;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add Customer to Queue\n";
        cout << "2. Remove First Customer from Queue\n";
        cout << "3. Display Number of Customers Waiting\n";
        cout << "4. View First Customer in Queue\n";
        cout << "5. View Last Customer in Queue\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
        case 1:
            if (currentAddedCustomers >= size) {
                cout << "All customers are already added. Cannot add more.\n";
                break;
            }
            cout << "Enter customer name: ";
            getline(cin, name);
            c = new Customer(name);
            allCustomers[currentAddedCustomers++] = c;
            waitingQueue.enqueue(c);
            break;

        case 2:

            c = waitingQueue.dequeue();//customer object address
            cout << "Removed customer: ";
            c->displayCustomer();
            currentAddedCustomers--;//imp
            break;

        case 3:
            cout << "Number of customers waiting: " << waitingQueue.sizeOfQueue() << endl;
            break;

        case 4:
            c = waitingQueue.frontPeek();//customer object address
            cout << "First customer ID: ";
            c->displayCustomer();
            
            break;

        case 5:
            c = waitingQueue.rearPeek();//customer object address
            cout << "Last customer ID: ";
            c->displayCustomer();
            break;

        case 6:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    //delete objects created on heap
    for (int i = 0; i < size; ++i) {
        delete allCustomers[i];
        allCustomers[i] = nullptr;  // initialize all to nullptr
    }
    delete [] allCustomers;
    allCustomers = nullptr;

	system("pause");
	return 0;
}