#include <iostream>
using namespace std;

class SortedArray {
	int size; // 현재 배열의 크기
	int *p; // 정수 배열에 대한 포인터

	void sort(); // 정수 배열을 오름차순으로 정렬

public:
	SortedArray(); // p는 nullptr, size는 0으로 초기화
	SortedArray(const SortedArray& src); // 복사 생성자
	SortedArray(int p[], int size); // 생성자. 정수 배열과 크기를 전달받음
	~SortedArray(); // 소멸자

	SortedArray operator+(const SortedArray& op2) const;
	SortedArray& operator=(const SortedArray& op2); // 현재 배열에 op2 배열을 복사

	void show() const; // 배열의 원소 출력
};

SortedArray::SortedArray() : size{0}, p{nullptr} {}

SortedArray::SortedArray(const SortedArray& src) {
	size = src.size;
	p = new int[size];
	for (int i = 0; i < size; i++) {
		p[i] = src.p[i];
	}
}

SortedArray::SortedArray(int p[], int size) : size(size) {
	this->p = new int[size];
	for (int i = 0; i < size; i++) {
		this->p[i] = p[i];
	}
	sort();
}

SortedArray::~SortedArray() {
	delete[] p;
}

SortedArray SortedArray::operator+(const SortedArray& op2) const {
	int newSize = size + op2.size;
	int* newArr = new int[newSize];
	for (int i = 0; i < size; i++) {
		newArr[i] = p[i];
	}
	for (int i = 0; i < op2.size; i++) {
		newArr[size + i] = op2.p[i];
	}
	SortedArray result(newArr, newSize);
	delete[] newArr;
	return result;
}

SortedArray& SortedArray::operator=(const SortedArray& op2) {
	if (this == &op2) {
		return *this;
	}
	delete[] p;
	size = op2.size;
	p = new int[size];
	for (int i = 0; i < size; i++) {
		p[i] = op2.p[i];
	}
	return *this;
}

void SortedArray::sort() {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (p[j] > p[j + 1]) {
				int temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

void SortedArray::show() const {
	for (int i = 0; i < size; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}

int main() {
	int n[] = { 2, 20, 6 };
	int m[] = { 10, 7, 8, 30 };
	SortedArray a(n, 3), b(m, 4), c;

	c = a + b;
	a.show();
	b.show();
	c.show();

	return 0;
}
