#include <iostream>

using namespace std;

class Fraction{
	int numer;  //분자
	int denom;   //분모
public:
	Fraction(int num, int den); //매개변수가 있는 생성자
	Fraction(); //디폴트 생성자
	~Fraction();
	
	int getNumer() const;  //접근자
	int getDenom() const;
	
	void setNumer(int num); //설정자
	void setDenom(int den);
	void print() const;  //분수 출력
private:
	void normalize();  //gcd() 함수를 사용하여 기약분수로 처리
	int gcd(int n, int m); //분모와 분자의 최대 공약수
};

Fraction::Fraction(int num, int den):numer{num}, denom{den} {
    normalize();  //생성자 호출 시 바로 분수를 기약분수로 변환
}
Fraction::Fraction():numer{0}, denom{1}{
}
Fraction::~Fraction(){
}

int Fraction::getNumer() const{
    return numer;
}
int Fraction::getDenom() const{
    return denom;
}

void Fraction::setNumer(int num){
    numer = num;
    normalize();  //분자를 바꾼 후 분수를 기약분수로 변환
}
void Fraction::setDenom(int den){
    denom = den;
    normalize();  //분모를 바꾼 후 분수를 기약분수로 변환
}

void Fraction::print() const{
    cout << numer << "/" << denom << endl;
}

void Fraction::normalize(){
    int divisor = gcd(numer, denom);
    numer /= divisor;
    denom /= divisor;
    if(denom < 0){
        denom = -denom;
        numer = -numer;
    }
}

int Fraction::gcd(int n, int m){
    if(m == 0) return n;
    else return gcd(m, n%m);
}

Fraction& multiplyFract(const Fraction& f1, const Fraction& f2, Fraction& product){
    int newNumer = f1.getNumer() * f2.getNumer();
    int newDenom = f1.getDenom() * f2.getDenom();
    product.setNumer(newNumer);
    product.setDenom(newDenom);
    return product;
}

Fraction& addFract(const Fraction& f1, const Fraction& f2, Fraction& sum){
    int newNumer = f1.getNumer() * f2.getDenom() + f2.getNumer() * f1.getDenom();
    int newDenom = f1.getDenom() * f2.getDenom();
    sum.setNumer(newNumer);
    sum.setDenom(newDenom);
    return sum;
}

void write(const Fraction& fract){
    fract.print();
}


int main(){
  Fraction fract1(12, 15);
  Fraction fract2(6, 9);
  Fraction product{};

  cout << "\n== 다음과 같은 분수에 대하여 산술연산을 합니다.=="<<endl;
  cout << "fract1: ";
  write(move(fract1));
  cout << "fract2: ";
  write(move(fract2));
  
  cout << endl<<"The result of multiplying is: ";
  multiplyFract(fract1, fract2, product).print();

  cout << endl<< "The result of adding is: ";
  addFract(fract1, fract2, product).print();
}
