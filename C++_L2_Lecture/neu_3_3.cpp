/* cs31.5E.cpp
An example of looping thru an array of strings
*/
#include <iostream>
#include <string>
using namespace std;
int printArray(const string a1[], int n1);

int main()
{

	string simpsons[5] = {"homer", "marge", "bart", "lisa", "maggie" };
	printArray(simpsons, 5);
	
	return 0;
}

int printArray(const string a1[], int n1) {

    if (n1 < 0)
	return -1; // returns error if array size negative
	for (int i = 0; i < n1; i++)
	cout << "Array index " << i << " has value " << a1[i] << endl;
	
	return 1; // returns 1 if array size >= 0
}
/* Output

Array index 0 has value homer
Array index 1 has value marge
Array index 2 has value bart
Array index 3 has value lisa
Array index 4 has value maggie



*/
