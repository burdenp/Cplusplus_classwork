using namespace std;

double change_it(double it);              // Function prototype

int main() {
  double it = 5.0;
  cout << "Before function execution, it = " << it     << endl;
  double result = change_it(it);

  cout << "After function execution, it = " << it     << endl
       << "Result returned is "             << result << endl;
  return 0;
}

// Function to attempt to modify an argument and return it
double change_it(double it) {
  it += 10.0;                            // This modifies the copy of the original
  cout << endl
       << "Within function, it = " << it << endl;
  return it;
}