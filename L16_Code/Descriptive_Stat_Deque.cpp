#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <deque>
using namespace std;

double binarySearch(const deque<double> d, double k);

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
deque<double> numbers;

for (size_t i =0;i<ARR;i++) 
	numbers.push_back((rnd()*i)+rnd());

for (int i = 0; i < numbers.size(); ++i) {
	cout << numbers[i] << " ";
}
	cout << endl;


sort(numbers.begin(),numbers.end());

double mean=0.0,sum=0.0;

for (int i = 0; i < numbers.size(); ++i) {
	sum+=numbers[i];
	cout << numbers[i] << " ";
}
	cout << endl;

	cout << numbers[0] << " min\n";
	cout << numbers[ARR-1] << " max\n";
	cout << numbers[ARR/2] << " median\n";
	cout << sum/ARR << " mean\n";
	cout << sum << " sum\n";

 for (deque<double>::iterator iter = numbers.begin();
         iter != numbers.end(); ++iter) {
             cout << *iter << " ";
         }

     cout << endl;

 for (deque<double>::reverse_iterator riter = numbers.rbegin();
         riter != numbers.rend(); ++riter) {
             cout << *riter << " ";
         }
  cout << endl;
 int r = rand()%numbers.size();
 cout << "r " << r << " numbers[r] " << numbers[r] << endl;
 cout << "binarySearch(numbers,r) " <<  binarySearch(numbers,r) << endl;
 cout << "binarySearch(numbers,numbers[r]) " <<  binarySearch(numbers,numbers[r]) << endl;
  cout << endl;
 numbers.push_back(3.14159265359);
 numbers.push_front(1.41421356237);
 numbers.push_back(2.7182818284590452);
 cout << endl;
  cout << endl;
 for (deque<double>::reverse_iterator riter = numbers.rbegin();
         riter != numbers.rend(); ++riter) {
             cout << *riter << " ";
         }
 
  cout << endl;
   cout << endl;
 numbers.pop_back();
 numbers.pop_front();
 for (deque<double>::reverse_iterator riter = numbers.rbegin();
         riter != numbers.rend(); ++riter) {
             cout << *riter << " ";
         }
  cout << endl;
 cout << endl;
 return 0;

}

double binarySearch(const deque<double> d, double k)
{
    deque<double> deq=d;
	sort(deq.begin(),deq.end());
    int first = 0;
    int last = deq.size()-1;
    while (first <= last) {
        int mid = (first + last) / 2;
        if (k > deq[mid]) {
            first = mid + 1;
        } else if (k < deq[mid]) {
            last = mid - 1;
        } else {
            return deq[mid];
        }
    }
    return -1.0;
}