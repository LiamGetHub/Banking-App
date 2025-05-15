// Header file for input output functions
#include <iostream>
#include "User.h"
#include "stdlib.h"
#include "Helper.h"
#include "Bank.h"
#include "Saving.h"

using namespace std;

// main() function: where the execution of
// C++ program begins
int main() {

    User testUser;
    int userInp;

    printChoices();
    std::cin >> userInp;

    string nameInp;
    string lastNameInp;
    string emailInp;
    int phoneNumberInp;
    int ageInp;
    string usernameInp;
    string passwordInp;

    //bank
    Bank bank;
    
    do {
        

        switch (userInp) {
            case 1:
                exit;

                break;
            case 2:
                User* userPtr; // pointer to user to be returned by createAccount()

                askUserAcctQuestions(nameInp, lastNameInp,emailInp,phoneNumberInp,ageInp, usernameInp,passwordInp);
                userPtr = createAccount(nameInp, lastNameInp,emailInp,phoneNumberInp,ageInp, usernameInp,passwordInp);  // need to add to some type of db
                bank.addUser(userPtr);
                
                break;
            case 3:
                int acctInp;

                cout << "Open a bank acount"<<endl;

                //what account would the user like to open
                acountCreationChoices();

                cin >> acctInp;

                if (acctInp == 1) {
                  createNewSavingAccount();

                } else if ( acctInp == 2) {
                    //checkings

                } else {
                    // enter correct input

                }
                
                
                //create that acount
                // add to user object?

                break;
            
            case 4:
                cout << "A";

                break;

            case 5:
                cout << "A";

                break;

            case 6:
                //show user
                bank.printAllUsers();

                break;
            
            case 7:

                break;

            case 8:
                cout << "A";

                break;

            case 9:
                cout << "A";

                break;

            case 10:
                cout << "A";

                break;

            default:
                cout << "Other than A and B";
                break;
                return 0;
        }

        printChoices();
        cin >> userInp;

    } while (userInp != 1);
    

    return 0;
}