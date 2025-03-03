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

    printChoices();
    cin >> userInp;

    string nameInp;
    string emailInp;
    int phoneNumberInp;
    int ageInp;
    string usernameInp;
    string passwordInp;
    
    do {
        

        switch (userInp) {
            case 1:
                exit;

                break;
            case 2:

                cout << "Please enter your name (first and last): " << endl;
                cin >> nameInp;

                cout << "Please enter your email: " << endl;
                cin >> emailInp;

                cout << "Please enter your phone number: " << endl;
                cin >> phoneNumberInp;

                cout << "Please enter your age " << endl;
                cin >> ageInp;

                cout << "Please enter your user name: " << endl;
                cin >> usernameInp;

                cout << "Please enter your passwrod: " << endl;
                cin >> passwordInp;

                std::cout << "name: " << nameInp << ". email: " << emailInp << ". phone number: " << phoneNumberInp << ". age: " << " email: " << emailInp
                 << ". username: " << usernameInp << ". password: " << passwordInp << std::endl;

                break;
            case 3:
                cout << "A";

                break;

            default:
                cout << "Other than A and B";
                break;
                return 0;
        }


    } while (userInp != 1);
    

    return 0;
}


