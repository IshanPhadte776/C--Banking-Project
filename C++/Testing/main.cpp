#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

#include "Customer.h"
#include "Account.h"

//source https://stackoverflow.com/questions/16029324/splitting-a-string-into-an-array-in-c-without-using-vector 

using namespace std;



string* createUserData(string textOnLine) {

    string arrayToStoreCustomerDataForObject[5];
    int i = 0;
    stringstream ssin(textOnLine);
    while (ssin.good() && i < 5){
        ssin >> arrayToStoreCustomerDataForObject[i];
        ++i;
    }

    return arrayToStoreCustomerDataForObject;
}


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


int main() {
    string username = "sallydally"; 
    string password = "Password124";
    string customerDataObject[5];

    /*
    cout << "Insert your username ";
    cin >> username; 
    cout << "Insert your password ";
    cin >> password; 
    */


   //https://stackoverflow.com/questions/13035674/how-to-read-a-file-line-by-line-or-a-whole-text-file-at-once
    std::ifstream file("customerStorage.txt");
    //text On a line
    std::string textOnLine;
    //Recreating the file
    std::string file_contents;
    while (std::getline(file, textOnLine)){
        
        if (verifyUserNamePassword(textOnLine, username,password) == 1){
            //Start of the createUserDataMethod
            int i = 0;
            stringstream sssin(textOnLine);
            while (sssin.good() && i < 5){
                sssin >> customerDataObject[i];
                cout << customerDataObject[i] + "\n";
                ++i;
            ;}
            //End of the createUserDataMethod

            Customer customer1 = new Customer(customerDataObject[1],Account(0),customerDataObject[3],customerDataObject[4]);

        }
    ;}

}