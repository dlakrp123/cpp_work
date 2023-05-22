#include <iostream>
#include <memory>
#include <random>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
    unique_ptr<double[]> arr = nullptr;
    double *dptr = nullptr;
    
    mt19937 gen(time(nullptr));
    uniform_real_distribution<double> double_rd(10.0, 20.0);
    int n;

    cout << "스마트 포인터로 생성하는 배열(double)의 크기를 입력하세요 >> ";
    cin >> n;
    arr = make_unique<double[]>(n);

    for (int i = 0; i < n; i++)
    {
        arr[i] = double_rd(gen);
        cout << fixed;
        cout.precision(2);
        cout << i << " ] " << arr[i] << endl;
    }

    cout << "new 연산자로 생성하는 배열(double) 크기를 입력하세요 >> ";
    cin >> n;
    dptr = new double [n];

    for (int i = 0; i < n; i++)
    {
        dptr[i] = double_rd(gen);
        cout << i << " ] " << dptr[i] << endl;
    }
    return 0;
}
