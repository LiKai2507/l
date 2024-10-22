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

//後序運算
#include <stdio.h>
#include <iostream>
using namespace std;

int Transfer(char postfix[])
{
    int stack[20];
    int top = -1;
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            stack[++top] = postfix[i] - '0';
        }
        else
        {
            int a = stack[top--];
            int b = stack[top--];
            switch (postfix[i])
            {
            case '+':
                stack[++top] = a + b;
                break;
            case '-':
                stack[++top] = b - a;
                break;
            case '*':
                stack[++top] = a * b;
                break;
            case '/':
                stack[++top] = b / a;
                break;
            }
        }
        i++;
    }
    return stack[top];
}
int main()
{
    char itemset[20];
    scanf("%s", itemset);
    printf("%d\n", Transfer(itemset));
}