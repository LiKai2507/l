/*
系統會給出幾個多項式例子，請編寫一個程式，依序將這些多項式「相加」後，列印出結果。

系統輸入：
輸入資料包含幾個例子，每個例子如下所述。每個例子由兩行組成，第一行包含一個整數n（2 ≤ n ≤ 20, n∈偶數），
第二行包含n個整數a1, b1, a2, b2, … ,an（0 ≤ ai ≤ 100, -50 ≤ bi ≤ 50），a1表示多項式非零項的「指數」，
b1表示多項式非零項的「係數」，依此類推。最後，輸入0作為結束。

結果輸出：
以降冪方式，顯示每個非零項的指數k、係數a、未知數x，格式為ax^k。未知數以字元'x'表示，a等於1或-1時且k不等於0時不顯示a，
k等於1時不顯示^k，k等於0時不顯示x^k，每個非零項之間含有一個的加號或減號。舉例：2x^2+4x-7。


輸入範例：
6
3 -2 2 3 0 4
4
3 2 2 1
6
4 5 2 -5 0 3
0

輸出範例：
5x^4-x^2+7
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int Polynomial[101] = {};

    while (n != 0)
    {
        for (int i = 0; i < n / 2; i++)
        {
            int ai, bi;
            cin >> ai >> bi;

            Polynomial[ai] += bi;
        }

        cin >> n;
    }

    bool first = false;
    for (int i = 100; i >= 0; i--)
    {
        if (Polynomial[i] != 0)
        {
            if (Polynomial[i] > 0 && first == true)
                cout << "+";

            first = true;
            if (i == 0)
                cout << Polynomial[i];
            else if (Polynomial[i] == 1)
                cout << "x^" << i;
            else if (Polynomial[i] == -1)
                cout << "-x^" << i;
            else
            {
                if (i != 1)
                    cout << Polynomial[i] << "x^" << i;
                else
                    cout << Polynomial[i] << "x";
            }
        }
    }
}