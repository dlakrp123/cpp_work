#include <iostream>
using namespace std;

char &find2replace(char *fstr, char re, char replace , bool &success) {
    int i = 0;
    while (*fstr) {
        if (*fstr == re) {
            success = true; //발견함. 함수 성공
            *fstr = replace;
        }
        fstr++;
    }
    return *fstr;  //발견하지 못함, return 값 의미 없음
}

int main() {
    char str[] = "C++ programming";
    char has = '+';
    char replace = 'p';
    bool result = false;

    cout << "변경 전 문자열 = " << str << endl;
    
    find2replace(str, has, replace, result); //'+' 위치에  'p' 저장

    if (result == true) 
        cout << "변경 후 문자열 = " << str << endl;
    else 
        cout << str << "에서 " << has << "를 발견하지 못함." << endl;
    return 0;
}
