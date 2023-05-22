#include <iostream>
#include <memory>

using namespace std;

class Subject{
  string pname;  //과목명
public:
  Subject(){}
  Subject(string pname):pname(pname){}
  string getName() const {return pname;}
  void setName(string pname) {this->pname = pname;}
};

class Major{
  string fname; //전공명
  unique_ptr<Subject[]> p; // Subject 배열 포인터
  int size;               // Subject 배열의 크기, 전공과목 수
public:
  Major(string fname, int size); // size 개수만큼 Subject 배열 동적 생성
  void setName();  //Subject 배열 초기화
  void show();    //전공과목 출력
  ~Major();
};
Major::Major(string fname, int size):fname{fname}, size{size}{}
void Major::setName(){
   string pname;
    p = make_unique<Subject[]>(size);

    for(int i = 0; i <size ; i++){
        cout << "과목명을 입력하세요 >> " ;
        cin >> pname;
        p[i].setName(pname);
    }
}
void Major::show(){
    cout << fname << " 전공과목은 " << size << "개 입니다." <<endl;
    for(int i = 0 ; i<size ; i++)
      cout << p[i].getName() << endl;

}
Major::~Major(){
  p = nullptr;
  cout << fname << " 소멸자 실행" << endl;
}

int main(){
  Major *major;
  int size;
  string name;
  cout << "전공 교과목 수를 입력하세요 >> ";
  cin >> size;
  cout << "전공명을 입력하세요 >> ";
  cin >> name;
  major = new Major(name, size); 
  major->setName();
  major->show();
  return 0 ;
}

