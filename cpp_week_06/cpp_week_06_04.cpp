#include <iostream>

using namespace std;

class CoffeeMachine
{
    int coffee, water, suger;

public:
    CoffeeMachine(int c, int w, int s)
    {
        coffee = c;
        water = w;
        suger = s;
    }
    void drinkEspresso()
    {
        if (coffee <= 0 || water <= 0 || suger <= 0)//재료중 하나가 0이되면 empty함수를 출력하고 재료가 0에서 더 감소할 수 없도록 했습니다.
            empty();
        else
        {
            coffee--;
            water--;
        }
    }
    void drinkAmericano()
    {
        if (coffee <= 0 || water <= 0 || suger <= 0)
            empty();
        else
        {
            coffee--;
            water -= 2;
        }
    }
    void drinkSugarCoffee()
    {
        if (coffee <= 0 || water <= 0 || suger <= 0)
            empty();
        else
        {
            coffee--;
            water -= 2;
            suger--;
        }
    }
    void show()
    {
        cout << "커피 머신 상태 - 커피: " << coffee << "\t물: " << water << "\t설탕 : " << suger << endl;
    }
    void fill()
    {
        coffee = 10;
        water = 10;
        suger = 10;
    }
    void empty()//재료가 소진되면 알림이뜨는 함수를 추가했습니다. 
    {
        if (coffee <= 0)
        {
            cout << "커피 재료가 소진됐습니다. fill을 눌러 재료를 채워야 합니다." << endl;
        }
        else if (water <= 0)
        {
            cout << "물이 소진됐습니다. fill을 눌러 재료를 채워야 합니다." << endl;
        }
        else
            cout << "설탕이 소진됐습니다. fill을 눌러 재료를 채워야 합니다." << endl;
    }
};

int main()
{
    CoffeeMachine java{10, 10, 10};
    int n;
    while (true)
    {
        cout << "커피 종류 선택 : Espresso = 1, Americano = 2, SugarCoffee=3, Exit=4, Fill=5 >> ";
        cin >> n;

        if (n > 5 || n < 1)
        {
            cout << "wrong number" << endl;
            continue;
        }
        switch (n)
        {
        case 1:
            java.drinkEspresso();
            java.show();
            continue;
        case 2:
            java.drinkAmericano();
            java.show();
            continue;
        case 3:
            java.drinkSugarCoffee();
            java.show();
            continue;
        case 5:
            java.fill();
            java.show();
            continue;
        default:
            break;
        }
        break;
    }
    cout << "커피 머신을 종료합니다.";

    return 0;
}
