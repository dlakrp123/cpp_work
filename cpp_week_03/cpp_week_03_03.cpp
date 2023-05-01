#include <iostream>
using namespace std;

int main()
{
    double realNumber;

    cout << "enter a realnumber: ";
    cin >> realNumber;

    cout << "Integer Part : " <<  static_cast<int>(realNumber) << endl;
    cout << "decimal Part : " << realNumber - static_cast<int>(realNumber) <<endl;
    
    return 0;
}

