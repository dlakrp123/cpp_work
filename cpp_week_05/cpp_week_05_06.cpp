#include <iostream>

using namespace std;

class TV
{
private:
    int volume = 1;
    int channel = 1;
    bool on = false; // 멤버 변수 기본값 설정

public:
    void power();
    void increaseChannel();
    void decreaseChannel();
    void increaseVolume();
    void decreaseVolume();
    void state();
};

void TV::power()
{
    if (TV::on == true)
        on = false;
    else
        on = true;
}

void TV::increaseChannel()
{
    if (TV::channel >= 128)
        TV::channel = 1;
    else
        TV::channel++;
}

void TV::decreaseChannel()
{
    if (TV::channel <= 0)
        TV::channel = 128;
    else
        TV::channel--;
}

void TV::increaseVolume()
{
    if (TV::volume >= 100)
        TV::volume = 100;
    else
        TV::volume++;
}

void TV::decreaseVolume()
{
    if (TV::volume <= 0)
        TV::volume = 0;
    else
        TV::volume--;
}
void TV::state()
{
    if (TV::on == 1)
        cout << "전원 켜짐" << endl;
    else
        cout << "전원 꺼짐" << endl;
    cout << "볼륨 : " << TV::volume << endl;
    cout << "채널 : " << TV::channel << endl;
}
int main()
{
    TV tv;
    cout << "멤버 함수 실행 전" << endl;
    tv.state(); // 멤버 변수 값을 변경 하지 않은 상태

    tv.power(); // 전원 키기
    tv.decreaseChannel();
    tv.decreaseChannel(); // 채널 128
    tv.increaseVolume();
    tv.increaseVolume();
    tv.increaseVolume(); // 볼륨 4
    cout << "멤버 함수 실행 후" << endl;
    tv.state();
    return 0;
}

