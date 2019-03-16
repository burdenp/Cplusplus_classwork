#include <iostream>
using namespace std;

int larger(int& m, int& n);

int main() {
  int value1 = 10;
  int value2 = 20;
  cout << "The larger of " << value1 << " and " << value2 << " is :" <<  endl;
  cout << larger(value1, value2) << endl;

  return 0;
}

// Function to the larger of two integers
int larger(int& m, int& n) {
  return m > n ? m : n;              // Return the larger value
}