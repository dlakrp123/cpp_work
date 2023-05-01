#include <iostream>
#include <string>

using namespace std;

int main()
{
    string strg{"ABCDEFGH"};
    /*strg.erase(0,1);*/
    strg.erase(0, strg.length()-1);
    cout << strg << endl;

    return 0;


}

