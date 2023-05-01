#include <iostream>

using namespace std;

class Person{
    string name;
    int age;
public:
    Person(){
        this->name = "Anonymous";
        this->age = 0;
        cout << "생성자 수행 " << this->name <<", "<<this->age << endl;
    }
    Person(string n, int a){
        this->name = n;
        this->age = a;
        cout << "생성자 수행 " << this->name <<", "<<this->age << endl;
    }
    ~Person(){
        cout << "소멸자 수행 " << this->name << endl;
    }
    string getName(){
        return this->name;
    }
};

int main()
{
    Person baby;
    Person child("benny", 10);
    cout << "baby name = " << baby.getName() << endl;
    cout << "child name = " << child.getName() << endl;

    return 0;
}
