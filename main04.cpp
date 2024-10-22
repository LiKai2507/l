/*
請寫一個int Eval(char infix[])副程式，可以輸入中序運算式，並回傳運算結果。請結合3-2「中序轉後序」和3-3「後序運算」所寫的副程式，來完成題目需求。

輸入範例：
3+4*(7-5)/2

輸出範例：
7

系統輸入：char型態的陣列（中序式）

結果輸出：一個int型態的數值
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

void InfixToPostfix(char infix[], char Postfix[20])
{
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
}

int Transfer(char postfix[])
{
    int stack[20] = {};
    int top = -1;
    int i = -1;
    while (postfix[++i])
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
                stack[++top] = b + a;
                break;
            case '-':
                stack[++top] = b - a;
                break;
            case '*':
                stack[++top] = b * a;
                break;
            case '/':
                stack[++top] = b / a;
                break;
            }
        }
    }
    return stack[top];
}

int Eval(char infix[])
{
    char Postfix[20] = {};
    InfixToPostfix(infix, Postfix);
    return Transfer(Postfix);
}

int main()
{
    char itemset[20];
    scanf("%s", itemset);
    cout << Eval(itemset);
}