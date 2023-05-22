#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0);
  Circle& operator++();
  Circle operator++(int x);
  Circle operator+(int op2);
	void show();
};

Circle::Circle(int radius):radius{radius}{}

Circle& Circle::operator++(){
  radius++;
  return *this;
}

Circle Circle::operator++(int x){
  Circle tmp = *this;
  radius++;
  return tmp;
}

Circle Circle::operator+(int op2){
  Circle tmp;
  tmp.radius = radius + op2;
  return tmp;
}
void Circle::show(){
  cout << "radius = " << radius << endl;
}
int main() {
  Circle a{5}, b{4};
  cout << "Circle 객체 : a" << endl;
  a.show();
  cout << "Circle 객체 : b" << endl;
  b.show();
  ++a; // 반지름을 1 증가 시킨다.
  cout << "Circle 객체 : ++a" << endl;
  a.show();

  cout << "Circle 객체 : b=a++" << endl;
  b = a++; // 반지름을 1 증가 시킨다.
  cout << "Circle 객체 : a" << endl;
  a.show();
  cout << "Circle 객체 : b" << endl;
  b.show();

  b = a + 3; // b의 반지름을 a의 반지름에 1을 더한 것으로 변경
  cout << "Circle 객체 : b = a + 3" << endl;
  b.show();
}
