#include <iostream>

using namespace std;

int main()
{
    int decimal;
    cout << "input a decimal : ";
    cin >> decimal;
    string str;
    cout << "print a radix oct(8) hex(16) digit(10)" << endl;
    while (true)
    {
        cout << "input the including radix : ";
        cin >> str;
        if (str == "16" || str == "hex")
        {
            cout << "hexadecimal : 0x" << hex << decimal << endl;
            continue;
        }
        else if (str == "8" || str == "oct")
        {
            cout << "octagon : 0" << oct << decimal << endl;
            continue;
        }
        else if (str == "10" || str == "digit")
        {
            cout << "decimal : " << dec << decimal << endl;
            continue;
        }
        else
        cout << "It dosen't exist.";
        break;
    }
}