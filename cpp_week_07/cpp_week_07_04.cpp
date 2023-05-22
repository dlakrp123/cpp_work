#include <iostream>
#include <memory>
using namespace std;

class Employee
{
    int year;    // 입사연도
    string name; // 이름
    string dept; // 소속
public:
    Employee()=default;
    Employee(string name, string dept, int year);
    void setEmployee(string name, string dept, int year); // 입사연도, 이름, 소속을 설정
    int getYear() const { return year; }                  // 입사연도 반환
    string getName() const { return name; }               // 이름 반환
    string getDept() const { return dept; }               // 소속 반환
    void disPlay();                                       // 개인정보 출력
                                       
};
Employee::Employee(string name, string dept, int year) : name(name), dept(dept), year(year) {}
void Employee::setEmployee(string name, string dept, int year)
{
    this->name = name;
    this->dept = dept;
    this->year = year;
}

void Employee::disPlay()
{
    cout << "name : " << this->name << ", dept : " << this->dept << ", year : " << year << endl;
}

class Manager
{
    unique_ptr<Employee[]> p; // Employee 배열 선언, 스마트포인터 또는 new 연산자 사용하여 동적생성
    int size;                 // 배열의 크기
public:
    Manager(int size); // size 크기의 배열 생성
    ~Manager();
    void searchByName(); // 사용자로부터 이름을 입력받아 소속과 입사연도 출력
    void searchByYear(); // 사용자로부터 입력받은 입사연도와 일치하는 값을 갖는 직원정보 출력
};
Manager::Manager(int size):size{size}
{
    int year;
    string name, dept;
    
    p = make_unique<Employee[]>(size);

    for (int i = 0; i < size; i++)
    {
        cout << "사원 " << i + 1 << "의 이름과 소속, 입사년도를 입력하세요 >> ";
        cin >> name >> dept >> year;
        p[i].setEmployee(name, dept, year);
    }
}
void Manager::searchByName()
{
    string findName;
    int count = 0;
    cout << "검색하고자 하는 사원의 이름 >> ";
    cin >> findName;

    for (int i = 0; i < size; i++)
    {
        if (p[i].getName() == findName)
        {
            p[i].disPlay();
            count++;
        }
    }
    if (count == 0)
        cout << findName << " 은 존재하지 않습니다. " << endl;
}
void Manager::searchByYear()
{
    int findYear, count = 0;
    cout << "입사 년도를 입력하세요 >> ";
    cin >> findYear;

    cout << findYear << "년도 이후에 입사한 사원을 검색합니다." << endl;
    for (int i = 0; i < size; i++)
    {
        if (p[i].getYear() >= findYear)
        {
            cout << (count + 1) << " ] ";
            p[i].disPlay();
            count++;
        }
    }
    if (count == 0)
        cout << findYear << " 은 존재하지 않습니다." << endl;
}
int main()
{
    Manager *pManager;
    cout << "사원수를 입력하세요 >> ";
    int size;
    cin >> size;
    if (size <= 0)
    {
        cout << "양수를 입력하세요." << endl;
        return 0;
    }
    pManager = new Manager(size);
    pManager->searchByName();
    pManager->searchByYear();
    return 0;
}
