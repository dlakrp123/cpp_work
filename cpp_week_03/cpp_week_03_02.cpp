#include <iostream>
using namespace std;

int main()
{
    int answer;
    enum class Rcp {Rock=1, Scissors, paper};
    Rcp rcp;
    

    while(true){
        cout << "enter a integer(enter a number other than 1,2,3 to exit) : ";
        cin >> answer;

        if (!(1<=answer && answer <=3))
            break;

        rcp=static_cast<Rcp>(answer);

        if(Rcp::Rock == rcp){
            cout << "Rcp::Rock" << endl;
        }
        else if(Rcp::Scissors == rcp){
            cout << "Rcp::Scissors" << endl;
        }
        else 
            cout << "Rcp::Paper" << endl;
    }
    return 0;
}

