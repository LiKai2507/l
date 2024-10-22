/*
請寫一個int Priority(char op)副程式，可以輸入運算子op並回傳優先度。再寫一個void InfixToPostfix(char infix[])副程式，可以輸入中序運算式，然後使用Priority(char op)比較每個運算子的優先度，透過堆疊的方式轉成後序運算式，並輸出結果。

輸入範例：
3+4*(7-5)/2

輸出範例：
3475-*2/+


系統輸入：char型態的陣列（中序式）

結果輸出：char型態的陣列（後序式）
*/

#include <stdio.h>
#include <iostream>
using namespace std;

int Priority(char op)
{
    if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

void InfixToPostfix(char infix[])
{
    char Postfix[20] = {};
    char symbol_temp[10] = {};
    int current_infix = -1, symbol_top = -1, postfix_top = -1;

    while (infix[++current_infix])
    {
        switch (infix[current_infix])
        {
        case '(':
            symbol_temp[++symbol_top] = infix[current_infix];
            break;

        case '+':
        case '-':
        case '*':
        case '/':
            while (Priority(infix[current_infix]) <= Priority(symbol_temp[symbol_top]))
            {
                Postfix[++postfix_top] = symbol_temp[symbol_top--];
            }
            symbol_temp[++symbol_top] = infix[current_infix];
            break;

        case ')':
            while (symbol_temp[symbol_top] != '(')
            {
                Postfix[++postfix_top] = symbol_temp[symbol_top--];
            }
            symbol_top--;
            break;

        default:
            Postfix[++postfix_top] = infix[current_infix];
            break;
        }
    }

    while (symbol_top != -1)
    {
        Postfix[++postfix_top] = symbol_temp[symbol_top--];
    }

    printf("%s\n", Postfix);
}


int main()
{
    char itemset[20];
    scanf("%s", itemset);
    InfixToPostfix(itemset);
}