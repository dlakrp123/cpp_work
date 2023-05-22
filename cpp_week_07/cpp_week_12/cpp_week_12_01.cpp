#include <iostream>

using namespace std;
class Square
{
private:
    int side;
public:
    Square(int side);
    ~Square();
    int getPeri();
    int getArea();
    void show(){
        cout << side << endl;
    }
    int getsize(){
        return this->side;
    }
};

Square::Square(int side):side{side}
{
}

Square::~Square()
{
}

int Square::getPeri(){
    return getsize()*4;
}

int Square::getArea(){
    return getsize()*getsize();
}

class Cube : public Square{
public:
    Cube(int side):Square(side){}
    ~Cube(){}
    int getSurfaceArea();
    int getVolume();
};

int Cube::getSurfaceArea(){
    return 6*(getsize()*getsize());
}

int Cube::getVolume(){
    return (getsize()*getsize()*getsize());
}

int main()
{
    Square sq{5};
    cout << ">> 정사각형 초기화 <<" << endl;
    cout << "Size: ";
    sq.show();
    cout << "Perimeter: " << sq.getPeri() << endl;
    cout << "Area: " << sq.getArea() << endl;

    Cube cb{5};
    cout << ">> 정육면체 초기화 <<" << endl;
    cout << "Size: ";
    cb.show();
    cout << "Surface: " << cb.getSurfaceArea() << endl;
    cout << "Volume: " << cb.getVolume() << endl;

    return 0;
}
