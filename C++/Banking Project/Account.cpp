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
    cout << "Calling the Destructor" <<endl
  ;}

  int getBalance(){
    return balance;
  }

  void increaseBalance(int addedMoney){
    balance = balance + addedMoney;
  }

  void decreaseBalance(int addedMoney){
    balance = balance - addedMoney;
  }

};