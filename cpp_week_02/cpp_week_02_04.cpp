#include <iostream>
using namespace std;


void swapArray(int *p, int *q, int size);//swapArray 함수 선언

void printArray(int *p, int size);//printArraty 함수 선언

int main(){
    int size = 5;
    int a[] = {1,2,3,4,5};
    int b[] = {9,8,7,6,5};
    
    cout << "Array A = " ;
    printArray(a,size);
    cout << "Array B = ";
    printArray(b,size);//printArray함수를 이용하여 배열 원소 교환전 출력

    swapArray(a, b, size);//배열교환 함수

    cout << "Array A = " ;
    printArray(a,size);
    cout << "Array B = ";
    printArray(b,size);//swapArray함수 사용 후 출력
    
    return 0;   
}

void swapArray(int *p, int *q, int size){
    int temp;
    for (int i = 0;i<size;i++){
        temp = p[i];
        p[i] = q[i];
        q[i] = temp;//정수 변수를 하나 생성하여 서로의 배열 원소를 바꿔줌.
    }
}

void printArray(int *p, int size){
    for (int i = 0;i<size;i++){
        cout << p[i] << " ";
    }
    cout << endl;//size크기의 배열 원소를 출력한다.
}
