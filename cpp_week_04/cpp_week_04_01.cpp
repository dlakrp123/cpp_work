#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    array<int, 5> farr;

    cout << "input a integer : " << endl;
    for(int i = 0 ; i<farr.size() ; i++){
        cin >> farr[i];
    }

    cout << "배열에 저장된 내용: ";
    for(int i : farr){
        cout << i << " ";
    }
    cout << endl;

    sort(farr.begin(), farr.end());
    
    cout << "배열 오름차순 정렬 : ";
    for(int i : farr){
        cout << i << " ";
    }

    return 0;
}
