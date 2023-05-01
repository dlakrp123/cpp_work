//randint.cpp
#include "randint.h"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

RandInt::RandInt(int begin, int end, string name) : begin(begin), end(end), name(name){
    gen = mt19937(time(nullptr));
    int_rd = uniform_int_distribution<int> (begin, end);
    rd = int_rd(gen);    
}

RandInt::~RandInt(){
    cout << name << "°´Ã¼ ¼Ò¸ê" << endl;
}

void RandInt::print() const{
    cout << "Random number between " << begin << " and " << end << " : " << rd <<endl;
}