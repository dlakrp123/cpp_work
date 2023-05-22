#include <iostream>

using namespace std;

class Point
{
    int x, y;

public:
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    int getX() { return x; }
    int getY() { return y; }

protected:
    void move_up(int x, int y)
    {
        this->x += x;
        this->y += y;
    }
    void move_down(int x, int y)
    {
        this->x -= x;
        this->y -= y;
    }
};

class ColorPoint : public Point
{
    string color;

public:
    ColorPoint() : Point(0, 0), color{"BLACK"} {}
    ColorPoint(int x, int y) : Point(x, y), color{"BLUE"} {}
    ColorPoint(int x, int y, string c) : Point(x, y), color{c} {}
    void setPoint(int x, int y, char op)
    {
        switch (op)
        {
        case '+':
            move_up(x, y);
            break;

        case '-':
            move_down(x, y);
            break;
        }
    }
    void show()
    {
        cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
    }
};

int main()
{
    ColorPoint zeroPoint;
    cout << "zeropoint 객체 출력 " << endl;
    zeroPoint.show(); // BLACK에 (0, 0) 위치의 점
    ColorPoint blue(5, 5);
    cout << endl
         << "blue 객체 출력" << endl;
    cout << "현재 위치에서 x:+10, y:+20 위치로 이동합니다" << endl;
    blue.setPoint(10, 20, '+');
    blue.show();

    ColorPoint red(50, 40, "RED");
    cout << endl
         << "red 객체 출력" << endl;
    red.show();
    cout << "현재 위치에서 x:-10, y:-20 위치로 이동합니다" << endl;
    red.setPoint(10, 20, '-');
    red.show();
}
