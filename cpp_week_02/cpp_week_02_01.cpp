#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    string value;
    cout << "input a three-digit integer: ";
    cin >> value; // 문자열 value를 생성한 후 3자리 정수를 입력받는다.
    cout << "Original Integer: " << value << endl;
    reverse(value.begin(), value.end());
    cout << "Reversed Integer: " << value << endl; // algorithm에 내장된 reverse함수를 이용하고 출력한다.
    return 0;
}
