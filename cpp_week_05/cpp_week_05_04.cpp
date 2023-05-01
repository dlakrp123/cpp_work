#include <iostream>

using namespace std;

void prime(initializer_list<int> ilist, int &p, const int &n);

int main(){
  int primeCnt;
  prime({3,12,6,37, 5, 8, 43, 29}, primeCnt, 0);
  cout<<"소수 갯수 : " << primeCnt<<endl;
  prime({5,8,21,84,12,31,27,7,87, 99, 121}, primeCnt, 0);
  cout<<"소수 갯수 : " << primeCnt<<endl;
}

void prime(initializer_list<int> ilist, int &p, const int &n){
    p=n;
    for(auto i : ilist){
        int c = 0;
        for(int j = 2 ; j<i ; j++){
            if (i % j == 0)
              c++;  
        }
        if(c == 0)
            p++;
    }
}