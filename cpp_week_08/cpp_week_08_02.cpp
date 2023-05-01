#include <iostream>

using namespace std;

class MyClass
{
    int size;
    int *element;

public:
    MyClass(int size);              // size ũ���� ������ �����ϴ� �迭�� ���� ������ �� 0���� �ʱ�ȭ
    MyClass(const MyClass &my);     // ���� ������
    MyClass(MyClass &&my) noexcept; // �̵� ������
    ~MyClass();
    void change(int, int);       // �迭 ���� ����
    void write(const string &&); // �迭 ���� ���
};

MyClass::MyClass(int size){
    element = new int[size];
    for(int i = 0 ; i<size ; i++){
        element[i] = 0;
    }
}
MyClass::MyClass(const MyClass &my){

}

void MyClass::write(const string&&){
    cout << my << 
}

int main()
{
    MyClass my{5};
    my.write("original(my)");
    my.change(2, 30);
    my.change(4, 15);
    my.write("change(my)");
    MyClass copy(my); // MyClass copy{move(my)} �� ���� �� ���� ��� ?

    copy.write("copy after");
    my.write("original(my)");
    copy.change(1, 23);
    copy.change(4, 61);
    print(move(copy), "change(copy)");
}