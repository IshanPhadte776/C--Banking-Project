#include <iostream>
using namespace std;

class Account {      
  public:             
    int balance;  

  Account(int money) {
    balance = money;
  }

  Account (){

  } 

  ~Account() {
    //cout << "Calling the Account Destructor" <<endl
  ;}

  int getBalance(){
    return balance;
  }

  void increaseBalance(int addedMoney){
    cout << "in the method";
    cout << addedMoney;
    cout << balance;

    balance = balance + addedMoney;
    cout << balance;

  }

  void decreaseBalance(int addedMoney){
    balance = balance - addedMoney;
  }

};