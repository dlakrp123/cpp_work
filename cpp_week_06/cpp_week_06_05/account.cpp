//account.cpp
#include <iostream>
#include "account.h"

using namespace std;

Account::Account(string str, int n){
    owner = str;
    money = n;
}
string Account::getOwner(){
    return owner;
}
void Account::deposit(int n){
    money += n;
    
}
void Account::withdraw(int n){
    money-=n;
    
}
int Account::check(){
    return money;
}
