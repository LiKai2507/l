#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int detectHumanGenome(string allowed, vector<string> &datas)
    {
        int count = 0;
        for (int i = 0; i < datas.size(); i++)
        {
            bool Plus = true;
            for (int j = 0; j < datas[i].size(); j++)
            {
                for (int k = 0; k < allowed.size(); k++)
                {
                    if (datas[i][j] == allowed[k])
                    {
                        break;
                    }
                    if (k == allowed.size() - 1)
                    {
                        Plus = false;
                    }
                }
            }
            if (Plus == false)
            {
                continue;
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};

int main()
{
    string allowed, data;
    vector<string> datas;
    int num, ans = 0;
    cin >> allowed >> num;

    for (int i = 0; i < num; i++)
    {
        cin >> data;
        datas.push_back(data);
    }

    Solution sol;
    ans = sol.detectHumanGenome(allowed, datas);
    cout << ans;

    return 0;
}