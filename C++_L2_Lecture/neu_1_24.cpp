#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int randInt(int limit);

int main()
{
      // Initialize random number generator

    srand(time(0));
    cout << "Enter an integer: ";
    int maxInt;
    cin >> maxInt;
	cout << "Max integer: " << maxInt << endl;
	cout << "Random integer between 0 and " << maxInt << " is " << randInt(maxInt) <<  endl;		

   // system("PAUSE"); uncomment this for Windows systems
   return 0;

	
}	

  // Return random int from 0 to limit-1
int randInt(int limit)
{
    if (limit < 1)
        return 0;
    return rand() % limit;
}