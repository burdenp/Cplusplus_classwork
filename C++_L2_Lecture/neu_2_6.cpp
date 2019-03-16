#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{

	string love = "I love C++";
	string trueLove = "No, no really I do.";
	const string empty;     // define empty string
	cout << "The value of const string empty is: " <<  empty << endl;
	cout << "The length of const string empty is: " <<  empty.size() << endl;

	cout << "The value of love is: " << love << endl;
	cout << "The value of trueLove is: " << trueLove << endl;

	cout << "Subscript love[0] is: " << love[0] << endl;  // Subscript
	cout << "love.length() is: " << love.length() << endl;  // shows love.length()
	cout << "love.size() is: " << love.size() << " which is the same as love.length(), which is " << love.length() << endl;  // sshows love.length () love.size()  

	if(love.empty()) {
	cout << "love is empty if(love.empty())" <<  endl;  // 
	} else {
	cout << "love is not empty if(love.empty())" <<  endl;  // 
	}

	if(love == empty) {
	cout << "love is empty if(love == empty)" <<  endl;  // 
	} else {
	cout << "love is not empty if(love == empty)" <<  endl;  // 
	}

	if(empty.empty()) {
	cout << "empty is empty if(empty.empty())" <<  endl;  // 
	} else {
	cout << "empty is not empty if(empty.empty())" <<  endl;  // 
	}
	
	if(love < trueLove) {
	cout << "love < trueLove" <<  endl;  // 
	} else {
	cout << "love >= trueLove" <<  endl;  // 
	}

	cout << "love.substr(1,5) is: " << love.substr(1,5) << endl;
	cout << "love.replace(2,3,x) is: " << love.replace(2,3,"x") << endl;


	return 0;
}
