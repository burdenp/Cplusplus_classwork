#include <iostream>
using namespace std;
int main()
{
      // Get a name
    cout << "Name: ";
    string name;
    getline(cin, name);
    if (name == "")
    {
        cout << "!!\nYou must enter a name" << endl;
        return 1;
    }

return 0;
}
