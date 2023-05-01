//accountmain.cpp
#include <iostream>
#include "account.h"

using namespace std;

int main() {
    Account a("C++", 0);
    MENU choice;
    int menu, money;

    do {
        cout << "--------------------------------------------" << endl;
        cout << "menu : 1. �Ա�, 2. ���  3. ��ȸ  4. ���� >> ";
        cin >> menu;
        choice = static_cast<MENU>(menu);

        if(choice == MENU::QUIT) 
            break;

        switch (choice) {
        case MENU::DEPOSIT:
            cout << "�Աݾ� >> ";
            cin >> money;
            a.deposit(money);
            cout << a.getOwner() << "�� �Ա� ���� " << money << endl;
            cout << a.getOwner() << "�� �ܾ��� " << a.check() << endl;
            break;
        case MENU::WITHDRAW:
            cout << "��ݾ� >> ";
            cin >> money;
            a.withdraw(money);
            cout << a.getOwner() << "�� ��� ���� " << money << endl;
            cout << a.getOwner() << "�� �ܾ��� " << a.check() << endl;
            break;
        case MENU::CHECK:
            cout << a.getOwner() << "�� �ܾ��� " << a.check() << endl;
        }
    } while (true);
    return 0;
}
