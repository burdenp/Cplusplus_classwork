#include <iostream>
using namespace std;


int main() {
  int fact = 0;
  cout << endl << "What upper limit would you like? ";
  cin >> fact;

  for(long n = 1, sum = 0, factorial = 1 ; n <= fact ; n++) {
    sum += n;                     // Accumulate sum to current n
    factorial *= n;               // Calculate n!
    cout << "Factorial of " << n << " is " << factorial << endl;
  }
  return 0;
}
