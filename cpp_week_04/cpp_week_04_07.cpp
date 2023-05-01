#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string input, result = "";

    while (true)
    {
        cout << "문자열을 입력하세요: (exit)\t";
        getline(cin, input);

        if (input == "exit")
        {
            cout << "finish";
            break;
        }

        for (int i = 0; i < input.length(); i++)
        {
            if (!isdigit(input[i]))
            {                               // 현재 문자가 숫자가 아니면
                result += input[i]; // 결과 문자열에 추가
            }
        }

        cout << "숫자가 제거된 문자열: " << result << endl;
        result ="";
    }
    return 0;
}
