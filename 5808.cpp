/*
每位同學成績之範例如下表，請計算每一科目的平均分數並輸出，且輸出個人平均最高分

範例：
姓名 國文 英文 數學 自然 社會
李小明 65 85 78 75 69
王小華 66 55 52 92 47
劉小花 75 99 63 73 86
陳小學 77 88 99 91 100
黃小萱 85 87 90 94 63
詹小茹 91 62 64 78 86

答案應為：
76.5 79.3 74.3 83.3 75.16
91

系統輸入：
30個int型態的數值（6*5的矩陣）

結果輸出：
5個float型態的數值（小數點後一位）
1個int型態的數值
*/

#include <iomanip>
#include <iostream>
using namespace std;

int main()
{
    int Score[6][5] = {};

    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> Score[i][j];
        }
    }

    float avg[5] = {};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            avg[i] += Score[j][i];
        }
        avg[i] /= 6;
    }

    int max_avg = 0;
    for (int i = 0; i < 6; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += Score[i][j];
        }
        sum /= 5;
        if (sum > max_avg)
        {
            max_avg = sum;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << fixed << setprecision(1) << avg[i] << " ";
    }
    cout << endl;
    cout << max_avg << endl;
}