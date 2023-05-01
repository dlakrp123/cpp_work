#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;

    while (true)
    {
        cout << "string input >> ";
        getline(cin, str);

        if(str == "exit"){
            cout<< "finish";
            break;
        }

        cout << "reverse string >> ";
        for (int i : str)
        {
            cout << str.back();
            str.pop_back();
        }
        cout << endl;
    }
    return 0;
}
