#include <iostream>
using namespace std;

class Account;


class Customer: public Human {       

  private:
    string name;
    Account account;
    string username;
    string password;

  public:             
    Customer (string listedName, Account acc, string usrname, string pword) {
      name = listedName;
      account = acc;
      username = usrname;
      password = pword;
    }

    ~Customer() {
      cout << "Calling the Destructor" <<endl
    ;}
};



