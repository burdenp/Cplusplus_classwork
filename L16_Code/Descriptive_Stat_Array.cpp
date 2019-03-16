#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;



double rnd() {
	double num  = (double)rand()/(double)RAND_MAX;
	return num;
}


int main()
{

// Initialize the random number generator.
srand(static_cast<unsigned int>(time(0)));
streamsize prec = cout.precision();
setprecision(5);

const int ARR=55;
double numbers[ARR];

for (size_t i =0;i<ARR;i++) 
	numbers[i]=(rnd()*i)+rnd();

for (size_t i =0;i<ARR;i++) 
	cout << numbers[i] << " ";
	cout << endl;

sort(begin(numbers),end(numbers));

double mean=0.0,sum=0.0;

for (size_t i =0;i<ARR;i++)  {
	sum+=numbers[i];
	cout << numbers[i] << " ";
}
	cout << endl;

	cout << numbers[0] << " min\n";
	cout << numbers[ARR-1] << " max\n";
	cout << numbers[ARR/2] << " median\n";
	cout << sum/ARR << " mean\n";
	cout << sum << " sum\n";

 cout << endl;
 return 0;
 
}