#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
        string value;
        while (1)
   
    {
                cout << "input a positive-number: ";
                cin >> value; // 문자열 value를 생성하고 입력받는다.
                string rev = value;
                reverse(rev.begin(), rev.end()); // 변수 value와 비교할 문자열 rev를 생성하고 reverse함수를 이용한다.
                if (rev.compare(value) == 0)
            cout << value << " is a palindrome." << endl;
                else             cout << value << " is not a palindrome." << endl; // 문자열을 비교하여 값에따라 결과를 출력한다.(값이 같을시 0, 아닐시 0이 아님)
           
    }
        return 0;
}
