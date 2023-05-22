#include <iostream>

using namespace std;

class BaseArray {
private:
	int capacity; // 동적 할당된 메모리 용량
	int *mem;
protected:
	BaseArray(int capacity=100) {
		this->capacity = capacity; 
        mem = new int [capacity];
	}
	~BaseArray() { delete [] mem; }
	void put(int index, int val) { mem[index] = val; }
	int get(int index) const{ return mem[index]; }
	int getCapacity() { return capacity; }
};

class MyQueue : public BaseArray{
	int size;
	int val;
public:
	MyQueue(int size = 0):BaseArray(100), size{size}{
		for(int i = 0 ; i < size ; i ++){
			cout << (i+1) << ") ";
			cin >> val;
			put(i, val);
		}
	}
	void poll(){
		cout << "큐의 원소를 순서대로 제거하며 출력 >> ";
		for(int i = 0; i < size ; i ++){
			cout << get(i) << " ";
		}
		cout << endl;
		size = 0;
	}

	void show(){
		cout << "큐의 용량 : " << getCapacity() << ", 큐의 크기 : " << size << endl;
		poll();
		cout << "큐의 현재 크기 : " << size << endl;
	}
};

int main()
{
	int s;
	cout << "큐에 삽입할 정수개수를 입력하시오 >> " ;
	cin >> s;
	MyQueue mq{s};
	cout << endl;
	mq.show();

    return 0;
}
