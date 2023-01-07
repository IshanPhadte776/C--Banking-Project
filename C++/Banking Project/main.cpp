#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Customer.cpp"
#include "Account.cpp"


//source https://stackoverflow.com/questions/16029324/splitting-a-string-into-an-array-in-c-without-using-vector 

using namespace std;

//This method works (returns 0 and 1)
bool verifyUserNamePassword (string textOnLine, string username, string password){
    string arrayToStoreCustomerData[4];

    int i = 0;
    stringstream ssin(textOnLine);
    while (ssin.good() && i < 4){
        ssin >> arrayToStoreCustomerData[i];
        ++i;
    }


    if (arrayToStoreCustomerData[2] == username && arrayToStoreCustomerData[3] == password){
        return true;
    }

    else {
        return false;
    }
}

//The method logic works, just the return types are messed up
string* createUserData(string textOnLine) {

    //I understand u should work with pointers
    static string arrayToStoreCustomerDataForObject[4];
    int i = 0;
    stringstream sssin(textOnLine);
    while (sssin.good() && i < 4){
        sssin >> arrayToStoreCustomerDataForObject[i];
        ++i;
    }

    return arrayToStoreCustomerDataForObject;
}



int findAccountBalance (string accountID){
    ifstream MyAccountFile("accountStorage.txt");
    string textOnAccountLine;
    stringstream ss;
    int balance;

    while (getline (MyAccountFile, textOnAccountLine)) {
        string arrayToStoreAccountData[2];
        int i = 0;
        stringstream accountStream(textOnAccountLine);
            while (accountStream.good() && i < 2){
                accountStream >> arrayToStoreAccountData[i];
                ++i;
            }

        if (arrayToStoreAccountData[0] == accountID) {
            MyAccountFile.close();
            ss << arrayToStoreAccountData[1];
            ss >> balance;
            return balance;
        }
    }
}

void loggedInLoop(Customer customer, Account account) {

    string userInput = "";
    int intOnLine;
    int newBalance;
    bool actionCompleted = false;

    //allows user to input text in terminal to add/subtract money from account
    while (userInput != "quit" && actionCompleted == false){
            cout << "Hello " + customer.getName() + "\n";
            cout << "Type 'quit' to finish working with the account \n" ;
            cout << "Type 'deposit' to deposit money to the account \n" ;
            cout << "Type 'withdraw' to withdraw money to the account where n is dollar amount \n" ;
            cin >> userInput; 

            
            if (userInput == "deposit") { 
                cout << "Type in the amount of money you want to deposit to the account \n" ;
                cin >> intOnLine; 


                //checks if the input was an int 
                if (intOnLine) {
                    //account.balance =+ intOnLine;

                    newBalance = account.getBalance() + intOnLine;

                    //account.increaseBalance(intOnLine);
                    cout << "Your new balance is " + to_string(newBalance);
                    cout << "\n";
                    actionCompleted = true;
                }

                else {
                    cout << "Type in a valid input \n" ;
                }

            }

            else if (userInput == "withdraw") {
                cout << "Type in the amount of money you want to withdraw to the account \n" ;
                cin >> intOnLine; 

                if (intOnLine) {
                    if (intOnLine > account.getBalance()){
                        cout << "You can't withdraw more money then what is already in the account \n" ;
                    }

                    else {
                        account.decreaseBalance(intOnLine);
                        cout << "Your new balance is " + account.getBalance();
                        cout << "\n";
                        actionCompleted = true;

                    }
                }

                else {
                    cout << "Type in a valid input \n" ;
                }

            }

    }
}

int main() {
    string username; 
    string password;
    string* customerDataObject;
    Customer customer;
    Account account;
    bool loggedIntoAccount = false;
    
   //https://stackoverflow.com/questions/13035674/how-to-read-a-file-line-by-line-or-a-whole-text-file-at-once
    std::ifstream file("customerStorage.txt");
    //text On a line
    std::string textOnLine;
    //Recreating the file
    std::string file_contents;   

    cout << "Hello User \n";

    //while loop to log the user in
    while (!loggedIntoAccount)
    {
        //This insert username / password portion works 
        cout << "Insert your username: ";
        cin >> username; 
        cout << "Insert your password ";
        cin >> password;

        cout << username + "\n";
        cout << password + "\n";

 

        //This portion works (getting data line by line)
        while (std::getline(file, textOnLine)) {
            if (loggedIntoAccount) {
                break;
            }



            //This if statement works
            if (verifyUserNamePassword(textOnLine, username,password) == 1){

                //Left side is incorrect
                //I made a work around (Don't use a method, just run the functionally of the code here)
                customerDataObject = createUserData(textOnLine);

                /*
               	for(i=0 ; i<5; i++) {
		            cout<<customerDataObject[i]<<"\t"; //ptr[i] is equivalent to *(ptr+i)
		
                }
                */



                string accountID = customerDataObject[0];

                Account account = Account(findAccountBalance(accountID));

                Customer customer = Customer(customerDataObject[0],customerDataObject[1],customerDataObject[2],customerDataObject[3]);
                //Fix this later
                loggedIntoAccount = true;

                //call loggedInWhileLoopHere

                loggedInLoop(customer,account);
                
            }



        }


        if (!loggedIntoAccount){
            cout << "Insert a valid set of username and password \n";
        }

    }    

    cout << "Good Bye" + customer.getName() + "\n";
    
}