#include <iostream>
#include <string>

using namespace std;

class Product
{
private:
    string name;
    int cost;
public:
    Product() {}
    void setPname(string s){
        this->name = s;
    }
    void setCost(int n){
        this->cost = n;
    }
    void write(){
        cout << "상품명 : " << name << ",\t 가격 : " << cost << endl;    
    }
    int calCost(int n){
        return cost*n;
    }
};

int main()
{
    Product p1{}, p2{};
    p1.setPname("c++");
    p1.setCost(20000);
    p2.setPname("java");
    p2.setCost(25000);
    cout << "------- p1 -------\n";
    p1.write();
    cout << "2개 구입가격 : " << p1.calCost(2) << endl;
    cout << "------- p2 -------\n";
    p2.write();
    cout << "4개 구입가격 : " << p2.calCost(4) << endl;

    return 0;
}
