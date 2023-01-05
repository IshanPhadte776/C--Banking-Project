#include <iostream>
#include "Account.h"
using namespace std;

class Account {      


  Account::Account(int money) {
    balance = money;
  } 

  Account::~Account() {
    cout << "Calling the Destructor" <<endl
  ;}

  int Account::getBalance(){
    return balance;
  }

  void Account::incrementBalance(){
    
  }



};

