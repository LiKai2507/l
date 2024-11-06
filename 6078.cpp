/*
為了防止期中考相關資訊外流，易佳助教與正坤助教在通訊時將0~9以自定義的加密機制進行保護，
然而有一天你在經過助教身旁時，無意間看到了加密的演算法並瞬間記住了所有項目，其內容如下：

***河內塔加密編號***
1.將該數字層數+2的河內塔以最少步驟進行搬移
2.有一數字k從2開始，每進行一次搬移，k都會增加1
3.將所有步驟的k相加，取得密碼表的編號

***核對密碼表***
1.任何密碼表都是10x10且內容為0~99的二維陣列
2.將編號從尾開始，兩兩一組為index，取得密碼表的內容(若不足以配對，則補0)
3.將取得的所有內容組合在一起

為了後續攔截並破解助教的密文，請你完成一個能夠將0~9轉換成密文的程式！

需要處理之項目：
1.main變數前處理
2.完成HanoiTowerCode()
3.完成getCipertext()

系統輸入：Plaintext
輸出：加密過的文字(密文)

範例輸入1(實際不會輸入該範例)：
15
範例輸出1：
671839
進階範例1：
從HanoiTowerCode得到327677，
再從密碼表取出[7][7]、[6][7]、[2][3]分別得到67,18,39

範例輸入2(實際不會輸入該範例)：
19
範例輸出2：
78326310
進階範例2：
從HanoiTowerCode得到5242877，
再從密碼表取出[7][7]、[8][2]、[4][2]、[5][0]分別得到78,32,63,10
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<vector<int>> getPasswordTable(int number)
{
    srand(number);
    vector<vector<int>> PasswordTable(10, vector<int>(10));
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            PasswordTable[i][j] = rand() % 100;
        }
    }

    return PasswordTable;
}

vector<int> getCipertext(int HTCode, vector<vector<int>> PasswordTable)
{
    vector<int> ans;
    while (HTCode > 0)
    {
        int index = HTCode % 100;
        ans.push_back(PasswordTable[index / 10][index % 10]);
        HTCode /= 100;
    }
    return ans;
}

void HanoiTowerCode(int n, int &k, int &total)
{
    if (n == 1)
    {
        k++;
        total += k;
        return;
    }
    HanoiTowerCode(n - 1, k, total);
    k++;
    total += k;
    HanoiTowerCode(n - 1, k, total);
}

int main()
{
    int Plaintext, k, total = 0;
    cin >> Plaintext;

    Plaintext += 2;
    k = 1;

    HanoiTowerCode(Plaintext, k, total);

    vector<vector<int>> PasswordTable = getPasswordTable(total);

    vector<int> ans = getCipertext(total, PasswordTable);
    for (int i = 0; i < ans.size(); ++i)
    {
        cout << ans[i];
    }
}