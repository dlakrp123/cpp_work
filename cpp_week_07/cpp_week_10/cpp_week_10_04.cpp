#include <iostream>

using namespace std;

class ArrayUtil
{
public:
    // s1과 s2를 연결한 새로운 배열을 동적 생성하여 리턴
    static int *concat(int s1[], int size1, int s2[], int size2, int &retSize);

    // s1에서 s2에 있는 숫자를 모두 삭제한 새로운 배열을 동적 생성하여 리턴
    static int *remove(int s1[], int size1, int s2[], int size2, int &retSize);

    // 입력 받은 크기만큼 배열을 동적 생성하여 리턴, 입력 받은 배열 크기는 count에 저장
    static int *create(int &count);

    // 배열 원소 출력
    static void print(int *arr, int size);
};
int *ArrayUtil::concat(int s1[], int size1, int s2[], int size2, int &retSize)
{
    retSize = size1 + size2;
    int *concattedarr = new int[retSize];
    int index = 0;

    for (int i = 0; i < size1; i++)
    {
        concattedarr[index] = s1[i];
        index++;
    }

    for (int i = 0; i < size2; i++)
    {
        concattedarr[index] = s2[i];
        index++;
    }
    return concattedarr;
}
int *ArrayUtil::remove(int s1[], int size1, int s2[], int size2, int &retSize)
{
    int* removedarr = new int[size1];
    int index = 0;
    int check = 0;

    for(int i = 0; i < size1 ; i++){
        for(int j = 0 ;j <size2 ; j++){
            if(s1[i] == s2[j]){
                check = 1;
                break;
            }
        }
        if(!check){
            removedarr[index] = s1[i];
            index++;
        }
        check=0;
    }
    retSize = index;
    return removedarr;
}

int *ArrayUtil::create(int &count)
{
    cout << "x배열의 원소(1~5)는 몇 개 ? ";
    cin >> count;

    int *arr = new int[count];
    cout << "x배열에 저장할 정수 입력 : ";

    for (int i = 0; i < count; i++)
    {
        cin >> arr[i];
    }
    return arr;
}
void ArrayUtil::print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int xcount = 0, ycount = 0;
    int *x, *y;

    // 반환 된 동적으로 생성된 배열을 x, y에 저장
    x = ArrayUtil::create(xcount);
    y = ArrayUtil::create(ycount);

    // concat() 함수를 호출한다.
    int retsize = 0;
    int *conarr = ArrayUtil::concat(x, xcount, y, ycount, retsize);
    cout << "\nx배열과 y배열을 연결한 배열은 ";
    ArrayUtil::print(conarr, retsize);

    // remove() 함수를 호출한다.
    int *remarr = ArrayUtil::remove(x, xcount, y, ycount, retsize);
    cout << "\nx배열에서 y배열의 원소를 삭제한 결과, x배열의 개수는 " << retsize << "개, ";
    ArrayUtil::print(remarr, retsize);

    // 동적 할당된 모든 변수를 해제 한다.
    delete[] x;
    delete[] y;
    delete[] conarr;
    delete[] remarr;
}
