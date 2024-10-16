/*
有一個二維陣列如下，請使用「以列為主」的方式，將二維陣列轉成一維陣列。

※main函式不可修改

範例輸入：

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15

範例輸出：

1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
*/
#include <iostream>
using namespace std;

int main()
{
    int Array_Data[15];
    for (int i = 0; i < 15; i++)
        cin >> Array_Data[i];

    int Array_Ans[3][5];
    for (int i = 0; i < 15; i++)
    {
        Array_Ans[i / 5][i % 5] = Array_Data[i];
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << Array_Ans[i][j] << " ";
        cout << endl;
    }
}
