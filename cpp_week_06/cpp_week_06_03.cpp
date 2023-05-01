#include <iostream>

using namespace std;

class Plus
{
    int a, b;
    int count = 0;

public:
    void setValue(int x, int y)
    {
        this->a = x;
        this->b = y;
    }
    int calculate()
    {
        return a + b;
    }

    void getCount()
    {
        count++;
    }

    int setCount()
    {
        return count;
    }
};
class Minus
{
    int a, b;
    int count = 0;

public:
    void setValue(int x, int y)
    {
        this->a = x;
        this->b = y;
    }
    int calculate()
    {
        return a - b;
    }

    void getCount()
    {
        count++;
    }

    int setCount()
    {
        return count;
    }
};
class MUltiple
{
    int a, b;
    int count = 0;

public:
    void setValue(int x, int y)
    {
        this->a = x;
        this->b = y;
    }
    int calculate()
    {
        return a * b;
    }

    void getCount()
    {
        count++;
    }

    int setCount()
    {
        return count;
    }
};
class Division
{
    int a, b;
    int count = 0;

public:
    void setValue(int x, int y)
    {
        this->a = x;
        this->b = y;
    }
    int calculate()
    {
        return a % b;
    }

    void getCount()
    {
        count++;
    }

    int setCount()
    {
        return count;
    }
};

int main(int argc, char const *argv[])
{
    int a, b, c;
    Plus p{};
    Minus m{};
    MUltiple mul{};
    Division d{};
    while (true)
    {
        cout << "1 : (+) , 2 : (*) , 3 : (%) , 4 : (-) 5 : exit >>";
        cin >> c;
        if (c>5 || c<1){
            cout << "wrong number" <<endl;
            continue;    
        }
        if(c == 5)
            break;
        cout << "operand >> ";
        cin >> a >> b;
        switch (c)
        {
        case 1 /* constant-expression */:
            p.setValue(a, b);
            cout << "Add : " << p.calculate() << endl;
            p.getCount();
            continue;
        case 2:
            mul.setValue(a, b);
            cout << "mul : " << mul.calculate() << endl;
            mul.getCount();
            continue;
        case 3:
            d.setValue(a, b);
            cout << "Mod : " << d.calculate() << endl;
            d.getCount();
            continue;
        case 4:
            m.setValue(a, b);
            cout << "Minus : " << m.calculate() << endl;
            m.getCount();
            continue;
        }
        break;
    }

    cout << "Add = " << p.setCount() << endl;
    cout << "Mod = " << d.setCount() << endl;
    cout << "mul = " << mul.setCount() << endl;
    cout << "minus = " << m.setCount() << endl;
    return 0;
}
