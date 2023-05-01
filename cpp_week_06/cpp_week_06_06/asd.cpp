#include <iostream>
#include <random>
#include <ctime>
using namespace std;
int main()
{
    mt19937 gen(time(nullptr));                               // 시간을 이용해 난수 생성 엔진 초기화
    uniform_int_distribution<int> int_rd(100, 200);           // low~high 사이의 난수 분포 정의(int)
    uniform_real_distribution<double> double_rd(50.0, 300.0); // double
    cout << "int :" << int_rd(gen) << endl;                   // 난수 엔진을 전달하여 범위내 생성된 난수 출력
    cout << "double: " << double_rd(gen) << endl;
}
