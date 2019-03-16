#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	// ask for the person's name
	cout << "Please enter your name and last name: ";
	// read the name
	string name;     // define `name'
	string exclamationMark = "!";     // define exclamation mark
	// write a greeting
	cin >> name;     // read into `name'

	cout << "Hello, " << name  + exclamationMark << endl; // notice what name  + exclamationMark does
	cout << "Hi again, " << name  << "!!!!" << endl; 
	cout << name << " is " << name.size() << " characters long." << endl;  // notice name.size()
  
  
	return 0;
}

