#include <iostream>

using namespace std;

class Circle {
	int radius;
public:
	Circle(int radius = 0) { this->radius = radius; }
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
	double getArea() { return 3.14*radius*radius; };
};

class NamedCircle:public Circle{
    string name;
public:
    NamedCircle() = default;
    NamedCircle(int r, string name):Circle(r),name{name}{}
	string getName(){ return name; }
	void set(int r, string name){
		this->name = name;
		setRadius(r); 
	}
};

string biggest(NamedCircle *c, int size){
		NamedCircle max = c[0];
		double maxArea = c[0].getArea();

		for(int i = 0; i < size ; i ++){
			if(c[i].getArea() > maxArea){
				maxArea = c[i].getArea();
				max = c[i];
			}
		}
		return max.getName();
	}
int main() {
	NamedCircle c[5];
	cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
	for (int i = 0; i < 5; i++) {
		int r;
		string name;
		cout << i + 1 << ">> ";
		cin >> r;
		getline(cin, name);
		if (r <= 0) {
			cout << "다시 입력하세요" << endl;
			i--;
			continue;
		}
		c[i].set(r, name);
	}
	cout << "가장 면적이 큰 피자는 " << biggest(c, size(c)) << " 입니다" << endl;
}//한글 깨짐(영어로 작성바람)
