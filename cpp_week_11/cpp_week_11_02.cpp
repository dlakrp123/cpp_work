#include <iostream>

using namespace std;

class Matrix{
  int ar[4];

public:
  Matrix(int a1 = 0, int a2 = 0, int b1 = 0, int b2 = 0);
  void show(string &&matrix);
  Matrix& operator >> (int[]);
  Matrix& operator << (int[]);
  Matrix operator+(const Matrix& op2);
  Matrix& operator+=(const Matrix& op2);
};
Matrix::Matrix(int a1, int a2, int b1, int b2){
    ar[0] = a1;
    ar[1] = a2;
    ar[2] = b1;
    ar[3] = b2;    
}
void Matrix::show(string &&matrix){
    for(int i = 0 ; i < size(ar) ; i ++){
        cout << ar[i] << " ";
    }
    cout << endl;
}

Matrix &Matrix::operator>>(int m[]){
    for(int i = 0 ; i<size(ar);i++){
        m[i] = ar[i];
    }
    return *this;
}
Matrix &Matrix::operator<<(int m[]){
    for(int i = 0; i<size(ar);i++){
        ar[i] = m[i];
    }
    return *this;
}
Matrix Matrix::operator+(const Matrix& op2){
    Matrix tmp;
    for(int i = 0 ; i < size(ar) ; i++){
        tmp.ar[i] = ar[i] + op2.ar[i];
    }
    return tmp;
}

Matrix &Matrix::operator+=(const Matrix& op2){
    for(int i = 0 ; i <size(ar) ; i++){
        this->ar[i] += op2.ar[i];
    }
    return *this;
}


int main(){
  Matrix a{1, 2, 3, 4}, b{2, 3, 4, 5}, c;
  c = a + b;
  a += b;
  a.show("matrix a");
  b.show("matrix b");
  c.show("matrix c");

  int x[4], y[4] = {5, 6, 7, 8};
  a >> x; // a의 각 원소를 배열 x에 복사.
  b << y; // 배열 y의 원소 값을 b의 각 원소에 설정

  cout << ">> 배열 x의 원소 출력 << " << endl;
  for (int i = 0; i < 4; i++)
    cout << x[i] << ' '; 
  cout << endl;
  cout << ">> 배열 y -> 배열b로 복사 후  << " << endl;
  b.show("matrix b");
}
