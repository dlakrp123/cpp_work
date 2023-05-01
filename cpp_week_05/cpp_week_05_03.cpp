#include <iostream>

using namespace std;

int &largest(int &num1, int &num2, int &num3); //3개의 정수 중 가장 큰 값을 반환
int &larger(int &num1, int &num2); //2개의 정수 중 큰 값을 반환

int main(){
  
  int num1 = 7, num2 = 3, num3 = 9;
  cout << "3개의 정수에서 가장 큰 수 : ";
  cout << largest(num1, num2, num3);
  return 0;
}

int &largest(int &num1, int &num2, int &num3){
    larger(num1, num2);
    if(num1 >= num3){
        return num1;
    }
    else
        return num3;
}

int &larger(int &num1, int &num2){
    if(num1 >= num2){
        return num1;
    }
    else
        num1 = num2;
        return num1;

}
