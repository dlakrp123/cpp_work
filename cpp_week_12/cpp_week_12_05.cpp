#include <iostream>

using namespace std;

class InkJetPrinter
{
    int availableInk;    // 잉크 잔량
    string model;        // 모델
    string manufacturer; // 제조사
    int printedCount;    // 총 인쇄 매수
    int availableCount;  // 인쇄 종이 잔량
public:
    InkJetPrinter()
    {
        availableInk = 10;
        model = "Officejet Y40";
        manufacturer = "HP";
        printedCount = 0;
        availableCount = 5;
    }
    void printInkJet(int pages = 1)
    {
        int add;
        if (availableCount < pages)
        {
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
            cout << "용지를 추가해 주세요 : ";
            cin >> add;
            if(add < (pages - availableCount)){
                cout << "용지가 아직 부족하여 필요한 만큼 더 채웁니다" << endl;
                add+=((pages - availableCount)-add);
            }
            availableCount += add;
            cout << "용지를 " << add << " 추가 합니다" << endl;
        }
        availableCount -= pages;
        availableInk -= pages;
        printedCount += pages;

        cout << "프린트하였습니다." << endl;
    } // pages 수만큼 용지 사용, 잉크잔량은 pages 수만큼 감소
    void showStateInkJet()
    {
        cout << "잉크젯 : " << model << ", " << manufacturer << ", 인쇄 매수 " << printedCount
             << "장 , 남은 종이 " << availableCount << "장, 남은 잉크 " << availableInk << endl;
    } // 현재 상태 출력
};

class LaserPrinter
{
    int availableToner;  // 토너 잔량
    string model;        // 모델
    string manufacturer; // 제조사
    int printedCount;    // 인쇄매수
    int availableCount;  // 인쇄 종이 잔량
public:
    LaserPrinter()
    {
        availableToner = 10;
        model = "SCX-6X45";
        manufacturer = "삼성전자";
        printedCount = 0;
        availableCount = 6;
    }
    void printLaser(int pages = 1)
    {
        int add;
        if (availableCount < pages)
        {
            cout << "용지가 부족하여 프린트할 수 없습니다." << endl;
            cout << "용지를 추가해 주세요 : ";
            cin >> add;
            if(add < (pages - availableCount)){
                cout << "용지가 아직 부족하여 필요한 만큼 더 채웁니다" << endl;
                add+=((pages - availableCount)-add);
            }
            availableCount += add;
            cout << "용지를 " << add << " 추가 합니다" << endl;
        }
        availableCount -= pages;
        availableToner--;
        printedCount += pages;
        cout << "프린트하였습니다." << endl;
    } // pages 수만큼 용지 사용, 토너 잔량은 -1 감소
    void showStateLaser()
    {
        cout << "레이저 : " << model << ", " << manufacturer << ", 인쇄 매수 " << printedCount
             << "장 , 남은 종이 " << availableCount << "장, 남은 토너 " << availableToner << endl;
    } // 현재 상태 출력
};

class PrinterManager : public LaserPrinter, public InkJetPrinter
{
    int num;
    int pages;

public:
    void operate()
    {
        cout << "현재 작동중인 2대의 프린터는 아래와 같다" << endl;
        showStateInkJet();
        showStateLaser();
        while (true)
        {
            cout << endl
                 << "프린터(1: 잉크젯, 2: 레이저)와 매수 입력 >> ";
            cin >> num >> pages;

            switch (num)
            {
            case 0:
                showStateInkJet();
                showStateLaser();
                break; 
            case 1:
                printInkJet(pages);
                showStateInkJet();
                break;
            case 2:
                printLaser(pages);
                showStateLaser();
                break;
            default:
                cout << "잘못된 숫자입니다." << endl;
                break;
            }
        }
    }
};
int main()
{
    PrinterManager man;
    man.operate();
}
