#include <iostream>
#include <random>
#include <ctime>
using namespace std;
int main()
{
    mt19937 gen(time(nullptr));                               // �ð��� �̿��� ���� ���� ���� �ʱ�ȭ
    uniform_int_distribution<int> int_rd(100, 200);           // low~high ������ ���� ���� ����(int)
    uniform_real_distribution<double> double_rd(50.0, 300.0); // double
    cout << "int :" << int_rd(gen) << endl;                   // ���� ������ �����Ͽ� ������ ������ ���� ���
    cout << "double: " << double_rd(gen) << endl;
}
