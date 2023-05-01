#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double score1 = 0.0, score2 = 0.0, score3 = 0.0;

    cout << "input grades of quiz, mid exam, final exam: ";
    cin >> score1 >> score2 >> score3;//변수 3개를 생성하여 실수를 입력받는다.

    double total = 0.0, average = 0.0;

    total = score1 + score2 + score3;//합
    average = total/3.0;//평균
    cout << fixed;
    cout.precision(2);//소수점 2자리수까지 반올림하여 결과를 출력한다.

    cout << "total : " << total << endl;
    cout << "avarage : " << average <<endl;

    return 0;
}