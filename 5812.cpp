/*
每位同學成績之範例如下表，請計算每一科目的平均分數並輸出，且輸出個人平均最低分

範例：
姓名 國文 英文 數學 自然 社會
李小明 65 85 78 75 69
王小華 66 55 52 92 47
劉小花 75 99 63 73 86
陳小學 77 88 99 91 100

答案應為：
70.8 81.8 73.0 82.8 75.5
62


系統輸入：
20個int型態的數值（4*5的矩陣）

結果輸出：
5個float型態的數值（小數點後一位）
1個int型態的數值

*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int score[4][5];
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> score[i][j];
        }
    }

    float avg[5] = {0};
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            avg[i] += score[j][i];
        }
        avg[i] /= 4;
    }

    int min_avg = 100;
    for (int i = 0; i < 4; i++)
    {
        int sum = 0;
        for (int j = 0; j < 5; j++)
        {
            sum += score[i][j];
        }
        sum /= 5;
        if (sum < min_avg)
        {
            min_avg = sum;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << fixed << setprecision(1) << avg[i] << " ";
    }
    cout << endl;
    cout << min_avg << endl;
}