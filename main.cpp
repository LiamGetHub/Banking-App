// Header file for input output functions
#include <iostream>
#include "User.h"

using namespace std;

// main() function: where the execution of
// C++ program begins
int main() {

    User testUser;

    string name;
  
    cout << "what is your name?: " << endl;
    cin >> name;

    testUser.setName(name);
    cout << "Hello " << testUser.getName() <<"!" << endl;

    return 0;
}
