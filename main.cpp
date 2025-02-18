// Header file for input output functions
#include <iostream>
#include "User.h"

using namespace std;

// main() function: where the execution of
// C++ program begins
int main() {
  
    // This statement prints "Hello World"
    //cout << "Hello World";

    User u1;

    std::string NAME = "test name john";

    u1.setName("NAME");

    cout << u1.getName() << endl;

    //cout << "test" << endl;

    return 0;
}
