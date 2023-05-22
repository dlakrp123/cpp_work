#include <iostream>

using namespace std;

class MyClass
{
    int size;
    int *element;

public:
    MyClass(int size);              // size 크기의 정수를 저장하는 배열을 동적 생성한 후 0으로 초기화
    MyClass(const MyClass &my);     // 복사 생성자
    MyClass(MyClass &&my) noexcept; // 이동 생성자
    ~MyClass();
    void change(int, int);       // 배열 원소 변경
    void write(const string &&); // 배열 원소 출력
    
};

MyClass::MyClass(int size):size{size}{
    element = new int[size];
    for(int i = 0 ; i<size ; i++){
        element[i] = 0;
    }
}
MyClass::MyClass(const MyClass &my) : size{my.size}, element{my.element}{
}
MyClass::MyClass(MyClass &&my) noexcept{
    size = my.size;
    element = my.element;
    my.element = nullptr;
    my.size = 0;
}
MyClass::~MyClass(){
    delete[] element;
}
void MyClass::change(int index, int value){
    element[index] = value;
}

void MyClass::write(const string&& output){ 
    cout << "======\t" << output <<"\t======" << endl;

    for(int i = 0 ; i < size ; i ++){
        cout << element[i] << "\t";
    } 
    cout<<endl;
}

void print(MyClass &&my, const string&& output){
    my.write(move(output));
}
int main()
{
    MyClass my{5};
    my.write("original(my)");
    my.change(2, 30);
    my.change(4, 15);
    my.write("change(my)");
    MyClass copy(my); // MyClass copy{move(my)} 로 수정 후 실행 결과 ?

    copy.write("copy after");
    my.write("original(my)");
    copy.change(1, 23);
    copy.change(4, 61);
    print(move(copy), "change(copy)");
}
