#include <iostream>
#include <string>

using namespace std;

class Max{
public:
    static string big(string str1, string str2){
        return str1 > str2 ? str1 : str2;
    }
    static int big(char *ch, int size){
        int index = 0;
        for(int i = 1 ; i < size ; i ++){
            if(ch[index] < ch[i]){
                index = i;
            }
        }
        return index;
    }
};
int main() {
  char ch[] = { 'd', 'a', 'e', 'A', 'p', 'x', 'q' };
  cout << "big(\"list\", \"array\") : " << Max::big("list", "array") << endl;

//size() �Լ��� �迭�� ũ�⸦ ��ȯ�մϴ�. ��, �����Ϸ��� c++17�� ����ؾ� �մϴ�.
  int index = Max::big(ch, size(ch));
  cout << "big(ch," << size(ch)<< ") :" <<ch[index] << endl;

  return 0;
}
