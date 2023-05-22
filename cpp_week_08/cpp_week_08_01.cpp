#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

class Book
{
    char *title; // 제목 문자열
    int price;   // 가격
public:
    Book(Book &&b) noexcept;
    Book(const Book &b);
    Book(const char *title, int price);
    ~Book();
    void set(const char *title, int price);
    void show() { cout << title << ' ' << price << "원" << endl; }
};

Book::Book(const char *title, int price) : price{price} //(1) 정답 book클래스의 생성자와 소멸자
{
    int len = strlen(title);
    this->title = new char[len + 1];
    strcpy(this->title, title);
}
Book::~Book()
{
    if (title != nullptr)
    {
        cout << title << "소멸" << endl;
        delete[] title;
    }
}
/* (2) 정답 디폴트 복사 생성자
Book::Book(Book &b){
    title = b.title;
    prive = b.price;
}
*/

Book::Book(const Book &b) : price{price}
{ //(3) 정답 깊은 복사 생성자 작성
    int len = strlen(b.title);
    title = new char[len + 1];
    strcpy(title, b.title);
}

Book::Book(Book &&b) noexcept
{
    price = b.price;
    title = b.title;
    b.title = nullptr;
    b.price = 0;
}
void Book::set(const char *title, int price) // set함수 구현
{
    if (this->title != nullptr)
    {
        delete[] this->title;
    }
    int len = strlen(title);
    this->title = new char[len + 1];
    strcpy(this->title, title);
    this->price = price;
}

int main()
{
    Book cpp("명품C++", 10000);
    Book java = cpp;
    java.set("명품자바", 12000);
    cpp.show();
    java.show();

    vector<Book> b;
    b.push_back(Book("명품파이썬", 15000));
    b.at(0).show();
    Book book(Book{"명품스크립트", 34000});
    book.show();
}
