/*
請寫一個int Transfer(char postfix[])副程式，可以輸入後序運算式，並回傳運算結果。

注意：課本中此題程式碼有誤，請仔細驗證結果。

輸入範例：
3475-*2/+

輸出範例：
7

系統輸入：char型態的陣列（後序式）

結果輸出：一個int型態的數值
*/
#include <stdio.h>
#include <iostream>
#include <stack>
using namespace std;

int Transfer(char postfix[])
{
    int number[20] = {};
    int top = -1, ansNum;

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        switch (postfix[i])
        {
        case '+':
            ansNum = number[top - 1] + number[top];
            top -= 2;
            break;
        case '-':
            ansNum = number[top - 1] - number[top];
            top -= 2;
            break;
        case '*':
            ansNum = number[top - 1] * number[top];
            top -= 2;
            break;
        case '/':
            ansNum = number[top - 1] / number[top];
            top -= 2;
            break;
        default:
            ansNum = postfix[i] - '0';
        }

        number[++top] = ansNum;
    }

    return number[0];
}

int main(int argc, char *argv[])
{
    char itemset[20];
    scanf("%s", itemset);
    cout << Transfer(itemset);
}
