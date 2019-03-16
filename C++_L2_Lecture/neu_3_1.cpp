// Looping thru an array of strings
#include <iostream>
#include <string>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() {
  const int max_strings = 4;                           // Maximum number of strings
  string  string_array[max_strings];                           // Array of strings
  int count = 0;                                     // Number of strings
  char answer = 0;                                   // Response to a prompt

  do {
    cout << "Enter a string: ";
    cin >>  string_array[count++];                           // Read a string

    cout << "Do you want to enter another string? (y/n): ";
    cin >> answer;                                   // Read response
  } while(count < max_strings && std::tolower(answer) == 'y');

  // Indicate when array is full
  if(count == max_strings)
    cout << endl << "Maximum string count reached." << endl;

  for(int i = 0 ; i < count ; i++) {
   cout << endl
       << "The string with index " << i << " is " <<  string_array[i]; 
  }
  
   cout << endl;

  return 0;
}

// My output:
//  [shell]$ g++ array_of_strings.cpp
//  [shell]$ ./a.out
//  Enter a string: Nik
//  Do you want to enter another string? (y/n): y
//  Enter a string: Zoe
//  Do you want to enter another string? (y/n): y
//  Enter a string: Bob
//  Do you want to enter another string? (y/n): y
//  Enter a string: Joey
//  Do you want to enter another string? (y/n): Zak
//  
//  Maximum string count reached.
//  
//  The string with index 0 is Nik
//  The string with index 1 is Zoe
//  The string with index 2 is Bob
//  The string with index 3 is Joey

