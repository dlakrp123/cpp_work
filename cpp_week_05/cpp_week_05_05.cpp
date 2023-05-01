#include <iostream>
#include <array>

using namespace std;

void swapArray(array<int, 5> &p, array<int, 5> &q); // 매개변수로 받은 배열 원소 교환
void printArray(array<int, 5> &p);                  // 매개변수로 받은 배열 원소 출력
void swap(int &p, int &q);                          // 참조 매개변수로 받은 값을 교환

int main()
{
    array<int, 5> a{1, 2, 3, 4, 5};
    array<int, 5> b{9, 8, 7, 6, 5};

    cout << "swapArray() 실행 전 ..." << endl;
    cout << "배열 a : ";
    printArray(a);
    cout << "배열 b : ";
    printArray(b);

    cout << "swapArray() 실행.." <<endl;
    swapArray(a,b);
    cout << "swapArray() 실행 후 ..." << endl; 
    
    cout << "배열 a : ";
    printArray(a);
    cout << "배열 b : ";
    printArray(b);
 }

void printArray(array<int, 5> &p){
    for(auto i : p){
        cout << i << " ";
    }
    cout << endl;
}

void swap(int &p, int &q){
    int tmp;
    tmp = p;
    p = q;
    q = tmp;
}

void swapArray(array<int, 5> &p, array<int, 5> &q){
    for(int i = 0 ; i < p.size() ; i++){
        swap(p[i], q[i]);
    }
}