//account.h
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

enum class MENU{DEPOSIT = 1, WITHDRAW, CHECK, QUIT};

class Account{
    int money;
    std::string owner;
public:
    Account(std::string str, int n);
    std::string getOwner();
    void deposit(int n);
    void withdraw(int n);
    int check();
};

#endif