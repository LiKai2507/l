/*
請寫一個void matrix_mul(int a[][a_columns], int b[][b_columns], int c[][columns])的副程式，可以對矩陣a和矩陣b進行「矩陣相乘」，並將相乘的結果儲存至矩陣c。再寫void matrix_print(int arr[][columns])的副程式，輸出矩陣c的結果。

系統輸入：12個int型態的數值（3*2的矩陣a和2*3的矩陣b）

結果輸出：9個int型態的數值（3*3的矩陣c）


矩陣a範例：
1 2
3 4
5 6

矩陣b範例：
1 0 1
1 1 0

相乘後的矩陣c：
3 2 1
7 4 3
11 6 5

輸出範例：
3 2 1 7 4 3 11 6 5
*/
#include <iostream>
using namespace std;

const int a_rows = 3;
const int b_rows = 2;
const int a_columns = 2;
const int b_columns = 3;

void matrix_init(int a[][a_columns], int b[][b_columns])
{
    for (int i = 0; i < a_rows; i++)
    {
        for (int j = 0; j < a_columns; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < b_rows; i++)
    {
        for (int j = 0; j < b_columns; j++)
        {
            cin >> b[i][j];
        }
    }
}

void matrix_mul(int a[][a_columns], int b[][b_columns], int c[][b_columns])
{
    for (int i = 0; i < a_rows; i++)
    {

        for (int j = 0; j < b_columns; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < a_columns; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void matrix_print(int arr[][b_columns])
{
    for (int i = 0; i < a_rows; i++)
    {
        for (int j = 0; j < b_columns; j++)
        {
            cout << arr[i][j] << " ";
        }
    }
}

int main()
{
    int A[a_rows][a_columns], B[b_rows][b_columns], C[a_rows][b_columns];
    matrix_init(A, B);
    matrix_mul(A, B, C);
    matrix_print(C);
}