#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string removeChar(string str, char c){

    for(int i = str.length()-1;i>=0;i--){
        if(str[i] == c){
            str.erase(find(str.begin(),str.end(), c));
        }
    }
    return str;
}

string findAndReplace(string str, string olds, string news){
    str.replace(str.find(olds),olds.length(),news);
    return str;
}


int main() {
    string str;
    char c;

    cout << "문자열 입력: ";
    getline(cin, str);
    cout << "삭제하고자 하는 문자 입력 : ";
    cin >> c;
    cout << "삭제 후 문자열 = " << removeChar(str, c) << endl
    << endl;

    string str1 = "an old string";
    string str2("an old");
    string str3("a new");

    cout << str1 << "에서 ";
    string strnew = findAndReplace(str1, str2, str3);
    cout << str2 << " 문자열을 " << str3 << "로 교체 후 문자열 = " << strnew << endl;
    
    return 0;
}
