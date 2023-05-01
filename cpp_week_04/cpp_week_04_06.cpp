#include <iostream>
#include <string>

using namespace std;

int main()
{
    char a;
    int b;
    string str;
    cout << "input string >> ";
    getline(cin, str);

    cout << "input a character you want to find >> ";
    cin >> a ;
    cout << endl;

    for(int i = 0 ; i < str.length() ; i++){
        if(a == str[i])
            b++;
    }

    cout << "문자 " << a << "는 " << b << "개 있습니다.";
    return 0;
}
