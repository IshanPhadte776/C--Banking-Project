#include <iostream>
using namespace std;
#ifndef Account_H
#define Account_H


class Account {      
  public:             
    Account(int money);
    ~Account();
    int getBalance();
    void incrementBalance(int increment);

private:
    int balance;
};

#endif