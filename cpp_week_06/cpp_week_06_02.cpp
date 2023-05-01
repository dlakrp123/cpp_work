#include <iostream>
#include <string>

using namespace std;

class Member{
    string id ;
    string pw ;
public:
    Member() : Member("null","null"){

    }
    Member(string str){
        cout << "매개변수가 하나인 생성자 입니다" << endl;
        cout << "pw >> ";
        cin >> this->pw;
        this->id = str;
        
    }
    Member(string str1, string str2){
        this->id = str1;
        this->pw = str2;
    }
    void disPlay() const{
        cout << "id >> " << this->id << endl;
        cout << "pw >> " << this->pw << endl;
    }
    bool isCheck() const{
        if(this->id == this->pw){
            return false;
        }
        else
            return true;
    }
};
int main()
{
    Member mem;
    Member mem1("C++", "C++");
    Member mem2("Java1");
    mem.disPlay();
    mem1.disPlay();
    if (mem1.isCheck())
        cout << "사용 가능한 pw 입니다" << endl;
    else
        cout << "id와 동일한 pw는 사용할 수 없습니다" << endl;
    mem2.disPlay();
    return 0;
}
