#include <iostream>
using namespace std;

class Custom
{
  string name;
  string tel;

public:
  Custom() = default;
  Custom(string name, string tel):name{name}, tel{tel}{};
  string getName() const { return name; }
  string getTel() const { return tel; }
  void set(string name, string tel) { this->name = name, this->tel = tel; }
  string info() { return "name : " + name + "\ttel : " + tel; }
};

class CustomManager
{
  Custom *p;
  int size;

public:
  CustomManager(int n); // n크기의 Custom 객체 배열 동적 생성하고 콘솔에서 입력받은 값으로 배열 초기화
  void show();          // Custom 객체의 이름과 전화번호 출력
  void search();        // Custom 객체의 전화번호 출력
  ~CustomManager();
};

CustomManager::CustomManager(int n)
{
  size = n;
  p = new Custom[n];
  string name, tel;
  for (int i = 0; i < size; i++)
  {
    cout << "이름과 전화번호를 입력해 주세요 >> " << endl;
    cout << "사람 " << i + 1 << ">> ";
    cin >> name >> tel;

    p[i].set(name, tel);
  }
}

void CustomManager::show()
{
  cout << "Custom 객체 배열 원소 출력 >>>>" << endl;
  for (int i = 0; i < size; i++)
  {
    cout << p[i].info() << endl;
  }
}

void CustomManager::search()
{
  int count = 0;
  string s;
  cout << "전화번호 검색합니다. 이름을 입력하세요 >> ";
  cin >> s;

  for (int i = 0; i < size; i++)
  {
    if (s == p[i].getName()){
      cout << s << "님의 전화 번호 >> " << p[i].getTel() << endl;
      count ++;
      }
  }
  if(count == 0)
    cout << "없는 사람 입니다." << endl;
}

CustomManager::~CustomManager()
{
  delete[] p;
  p = nullptr;
}
int main()
{
  CustomManager manager(4);
  manager.show();
  manager.search();

  return 0;
}
