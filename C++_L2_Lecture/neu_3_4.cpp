/*
An example of matching an element in an array of strings
cs31.5F.cpp
*/
#include <iostream>
#include <string>
using namespace std;
int match(const string a1[], int n1, const string target);

int main()
{

	string simpsons[5] = {"homer", "marge", "bart", "lisa", "maggie" };
	match(simpsons, 5, "bart");
	match(simpsons, 5, "Bart");
	return 0;
}

int match(const string a1[], int n1, const string target) {

    if (n1 < 0)
	return -1; // returns error if array size negative
	for (string::size_type i = 0; i < n1; i++) {
	if (a1[i] == target) {
	cout << "Array index " << i << " has value " << a1[i] << " and matches the target " << target << endl;
	}
	} 
	
	return 1; // returns 1 if array size >= 0
}
/* Output
Array index 2 has value bart and matches the target bart

*/
