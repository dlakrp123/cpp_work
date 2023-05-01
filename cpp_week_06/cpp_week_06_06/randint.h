//randint.h
#ifndef RANDINT_H
#define RANDINT_H
#include <random>
#include <ctime>

class RandInt
{
private:
    int begin, end;
    std::string name;
    std::mt19937 gen;
    std::uniform_int_distribution<int> int_rd;
    int rd;
public:
    RandInt(int b, int e, std::string n);
    ~RandInt();
    void print() const;
};

#endif
