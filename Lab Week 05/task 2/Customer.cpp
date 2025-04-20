#include "Customer.h"
Customer::Customer(string n) {
	name = n;
}
void Customer::displayCustomer() {
	cout << "\nName: " << name;
}