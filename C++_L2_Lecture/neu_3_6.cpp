/*
An example of reverseing an element in an array of strings
cs31.5F.cpp
*/
#include <iostream>
#include <string>
using namespace std;
int countDown(int n1);
int countUp(int n1);

int main()
{

	cout << "countDown " << endl;
	countDown(5);
	cout << "countUp " << endl;
	countUp(5);
	return 0;
}

int countDown(int n1) {
    if (n1 < 0)
	return -1; // returns error if array size negative
	for (int i = 0; i < n1; i++)
	cout << "In loop " << i << endl;
	
	return 1; // returns 1 if array size >= 0
}


int countUp(int n1) {
    if (n1 < 0)
	return -1; // returns error if array size negative
	for (int i = (n1 -1); i > -1; i--)
	cout << "In loop " << i << endl;
	
	return 1; // returns 1 if array size >= 0
}


/* Output

Array index 0 has value homer
Array index 1 has value marge
Array index 2 has value bart
Array index 3 has value lisa
Array index 4 has value maggie


*/

