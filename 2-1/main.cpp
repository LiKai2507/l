#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> parseInts(string str)
{
    vector<int> v;
    stringstream ss;
    ss << str;
    string temp;
    while (getline(ss, temp, ','))
    {
        v.push_back(stoi(temp));
    }
    return v;
}

int main(int argc, char *argv[])
{
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++)
    {
        cout << integers[i] << "\n";
    }

    return 0;
}