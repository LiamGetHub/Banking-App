// Header file for input output functions
#include <iostream>
#include "User.h"
#include "stdlib.h"
#include "Helper.h"

using namespace std;

// main() function: where the execution of
// C++ program begins
int main() {

    User testUser;
    int userInp;
    
    while(userInp != 1){
        
        printChoices();
        cin >> userInp;

        switch (userInp) {
            case 1:
                exit;

                break;
            case 2:
                cout << "Please enter your name: " << endl;

                break;
            case 3:
                cout << "A";

                break;

            default:
                cout << "Other than A and B";
                break;
                return 0;
        }
    }

    return 0;
}


