#include <iostream>

using namespace std;

char list_exam(initializer_list<int> arr, char c)
{
    int min = 99;
    char q = ' ';
    for (char j : arr)
    {
        if (abs(j - c) < min)
        {
            min = abs(j - c);
            q = j;
        }
    }
    return q;
}
int main()
{
    cout << "{ 'd', 'p', 'r', 'w', 'g', 'f' }문자 중 h와 가까운 문자는 : ";
    cout << list_exam({'d', 'p', 'r', 'w', 'g', 'f'}, 'h') << endl;

    cout << "{ 'k', 'q', 'b', 'r', 'a', 'e', 'v', 'z'}문자 중 w와 가까운 문자는 : ";
    cout << list_exam({'k', 'q', 'b', 'r', 'a', 'e', 'v', 'z'}, 'w') << endl;

    return 0;
}
