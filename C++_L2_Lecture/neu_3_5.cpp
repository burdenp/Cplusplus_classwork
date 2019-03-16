/*
An example of reversing an element in an array of strings
cs31.5G.cpp
*/
#include <iostream>
#include <string>
using namespace std;
int reverse(string a1[], int n1);
int printArray(const string a1[], int n1);

int main()
{

	string simpsons[5] = {"homer", "marge", "bart", "lisa", "maggie" };
	printArray(simpsons, 5);
	reverse(simpsons, 5);
	cout << "reverse(simpsons, 5);" << endl;
	printArray(simpsons, 5);
	return 0;
}

int reverse(string a1[], int n1) {
    if (n1 < 0)
	return -1; // returns error if array size negative
	const int N1_SIZE = n1;
	string temp[N1_SIZE];
//	string temp[n1] some compilers don't like string temp[n1] so need to declare const int N1_SIZE = n1
	int cnt = 0;
	for (int i = (n1 -1); i > -1; i--) {
	temp[cnt] = a1[i];
	cnt++;
	}
	for (int i = 0; i < n1; i++) {
	a1[i] = temp[i];
	}
	return 1; // returns 1 if array size >= 0
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
reverse(simpsons, 5);
Array index 0 has value maggie
Array index 1 has value lisa
Array index 2 has value bart
Array index 3 has value marge
Array index 4 has value homer



*/

