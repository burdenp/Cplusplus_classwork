#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <list>
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
list<double> numbers;

for (size_t i =0;i<ARR;i++) 
	numbers.push_back((rnd()*i)+rnd());

 for (list<double>::iterator iter = numbers.begin();
         iter != numbers.end(); ++iter) {
             cout << *iter << " ";
         }
     cout << endl;


// sort(numbers.begin(),numbers.end());

numbers.sort();

double mean=0.0,sum=0.0;

 for (list<double>::iterator iter = numbers.begin();
         iter != numbers.end(); ++iter) {
	sum+=*iter;
	cout << *iter << " ";
}
	cout << endl;

list<double>::iterator b = numbers.begin();
list<double>::iterator e = numbers.end();


	cout << numbers.front() << " min\n";
	cout << numbers.back() << " max\n";
	cout << sum/ARR << " mean\n";
	cout << sum << " sum\n";


 for (list<double>::reverse_iterator riter = numbers.rbegin();
         riter != numbers.rend(); ++riter) {
             cout << *riter << " ";
         }

 cout << endl;
 numbers.pop_front();
 numbers.pop_back();

  for (list<double>::iterator iter = numbers.begin();
         iter != numbers.end(); ++iter) {
	cout << *iter << " ";
}
   cout << endl;
  numbers.reverse();

  for (list<double>::iterator iter = numbers.begin();
         iter != numbers.end(); ++iter) {
	cout << *iter << " ";
}
   cout << endl;
 return 0;

}
