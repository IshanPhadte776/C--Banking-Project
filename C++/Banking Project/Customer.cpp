#include <iostream>
using namespace std;
#include "Human.cpp"

class Account;


class Customer: public Human {       

  private:
    string accountID;
    string name;
    string username;
    string password;

  public:             
    Customer (string uniqueAccountID,string listedName, string usrname, string pword) {
      accountID = uniqueAccountID;
      name = listedName;
      username = usrname;
      password = pword;
    }

    Customer () {
      //accountID = uniqueAccountID;
      //name = listedName;
    //  username = usrname;
      //password = pword;
    }

    ~Customer() {
      cout << "Calling the Destructor" <<endl
    ;}

    string getName() {
      return name;
    }
};



