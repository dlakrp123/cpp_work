#include <iostream>
#include <array>
#include <initializer_list>

using namespace std;

struct result
{
    int value;
    int cnt;
};

result list_exam(initializer_list<int> ilist)
{
    array<int,20> arr = {0};
    for (auto num : ilist)//반복문으로 리스트에 있는 원소 하나당 num번째 항 배열에 추가한다. 
    {
        if(num>=1 && num<=20)//1부터 20까지의 원소만 저장.
            arr[num]++;
    }
    int value = 0;
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > cnt)
        {
            cnt = arr[i];
            value = i;//앞서 1부터 20까지 나오는 수의 빈도수를 저장한 배열을 반복문으로 비교한다.
            // 가장 큰 빈도수(arr[i] 항)를 cnt에 저장하고 그 숫자를 value에 저장한다. 
        }
    }
    return {value, cnt};
}

int main()
{
    auto [value, cnt] = list_exam({2, 4, 12, 8, 10, 11, 12, 3, 12, 18, 19, 12});
    cout << "가장 많은 원소 : " << value << ",   개수 :" << cnt << endl;

    return 0;
}
