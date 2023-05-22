#include<iostream>

using namespace std;

class Book {
	string title;
	int price, pages;
public:
    Book& operator +=(const int& op2);
    Book& operator -=(const int& op2);
    bool operator ==(const int& op2);
    bool operator ==(const string& op2);
    bool operator ==(const Book& op2);
	Book(string title = "", int price = 0, int pages = 0);
	void show();
	string getTitle();  //title 반환
};

Book::Book(string title, int price, int pages):title{title},price{price},pages{pages}{}

Book& Book::operator += (const int& op2){
    this->price += op2;
    return *this;
}
Book& Book::operator -= (const int& op2){
    this->price -= op2;
    return *this;
}
bool Book::operator== (const int& op2){
    if(this->price == op2)
        return true;
    else
        return false;
}
bool Book::operator== (const string& op2){
    if(this->title == op2)
        return true;
    else
        return false;
}
bool Book::operator== (const Book& op2){
    if(this->title == op2.title && this->pages == op2.pages && this->price == op2.price){
        return true;
    }
    else    
        return false;
}
void Book::show(){
    cout << "책 이름: " << this->getTitle() << " 가격 : " << this->price << " pages : " << this->pages << endl;
}

string Book::getTitle(){
    return this->title;
}
int main() {
	Book a{"청춘", 20000, 300}, b{"미래", 30000, 500};
	a += 500;  // 책 a의 가격 500원 증가
	b -= 500;  // 책 b의 가격 500원 감소
	a.show(); 
	b.show();

	Book b1{"명품 C++", 30000, 500}, b2{"고품 C++", 30000, 500};
	if (b1 == 30000) cout << "정가 30000원" << endl;          // price 비교
	if (b1 == "명품 C++") cout << "명품 C++ 입니다." << endl; // 책 title 비교
	if (b1 == b2) cout << "두 책이 같은 책입니다." << endl;     // title, price, pages 모두 비교 
}
