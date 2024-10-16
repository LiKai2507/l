/*
有一個上三角矩陣如下，請使用「以行為主」的方式，將上三角矩陣儲存成一維陣列，並輸出其結果。

範例輸入：
1 2 3 4 5
0 6 7 8 9
0 0 10 11 12
0 0 0 13 14
0 0 0 0 15

範例輸出：

1 2 6 3 7 10 4 8 11 13 5 9 12 14 15

系統輸入：25個int型態的數值（5*5的陣列）

結果輸出：15個int型態的數值

※不使用if條件式*/
#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    int Array_Data[5][5];
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            cin >> Array_Data[i][j];

    int Array_Ans[15] = {};
    int count = -1;
    for (int i = 0; i < 5; i++)
        for (int j = 0; j <= i; j++)
            Array_Ans[++count] = Array_Data[j][i];

    for (int i = 0; i < 15; i++)
        cout << Array_Ans[i] << " ";
}
