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
    string  arrayToStoreCustomerData[5];
     

    int i = 0;
    stringstream ssin(textOnLine);
    while (ssin.good() && i < 5){
        ssin >> arrayToStoreCustomerData[i];
        ++i;
    }
    
    if (arrayToStoreCustomerData[3] == username && arrayToStoreCustomerData[4] == password){
        return true;
    }

    else {
        return false;
    }
}

//The method logic works, just the return types are messed up
string* createUserData(string textOnLine) {

    //I understand u should work with pointers
    string arrayToStoreCustomerDataForObject[5];
    int i = 0;
    stringstream sssin(textOnLine);
    while (sssin.good() && i < 5){
        sssin >> arrayToStoreCustomerDataForObject[i];
        ++i;
    }

    return arrayToStoreCustomerDataForObject;
}



int findAccountBalance (string accountName){
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

        if (arrayToStoreAccountData[0] == accountName) {
            MyAccountFile.close();
            ss << arrayToStoreAccountData[1];
            ss >> balance;
            return balance;
        }
    }
}

int main() {
    string username; 
    string password;
    string customerDataObject[5];
    bool loggedIntoAccount = false;
    
   //https://stackoverflow.com/questions/13035674/how-to-read-a-file-line-by-line-or-a-whole-text-file-at-once
    std::ifstream file("customerStorage.txt");
    //text On a line
    std::string textOnLine;
    //Recreating the file
    std::string file_contents;   

    cout << "Hello User";

    while (!loggedIntoAccount)
    {
        //This insert username / password portion works 
        cout << "Insert your username";
        cin >> username; 
        cout << "Insert your password";
        cin >> password; 

        //This portion works (getting data line by line)
        while (std::getline(file, textOnLine))
            if (loggedIntoAccount) {
                break;
            }

            //This if statement works
            if (verifyUserNamePassword(textOnLine, username,password) == 1){
                //Left side is incorrect
                //I made a work around (Don't use a method, just run the functionally of the code here)
                customerDataObject = createUserData(textOnLine);

                string nameOfObject = customerDataObject[0];

                //IDK how to create Objects of custom classes and assign attitudes to them
                Customer nameOfObject = Customer(customerDataObject[1],Account(0),customerDataObject[3],customerDataObject[4]);

                nameOfObject.name = customerDataObject[1];
                customerDataObject[0].account = customerDataObject[2];
                customerDataObject[0].username = customerDataObject[3];
                customerDataObject[0].password = customerDataObject[4];


                //Fix this later
                customerDataObject[2].balance = findAccountBalance(customerDataObject[2]);

                loggedIntoAccount = true;
                
            }

        }

    
}
