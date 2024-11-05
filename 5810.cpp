/*
一個簡單的「堆疊管理器」處理著兩個堆疊A和B，堆疊的資料型態為int，容量大小為100。對堆疊管理器輸入指令，可對A或B進行操作。請編寫一個程式，該程式模擬堆疊管理器的工作情況。

系統輸入：
第一行包含一個整數N，N表示接下來會有多少個指令。第二行開始，每行代表一個指令，每個指令第一個數字表示指令ID，後面接著該指令的參數，每個參數以空格分隔。以下為堆疊管理器的指令：
●[1 X Y]
對堆疊進行Push。參數X為要進行Push的堆疊代號，X=1時表示堆疊A，X=2時表示堆疊B。Y表示Push的數值（1 ≤ Y ≤ 99）。
●[2 X]
對堆疊進行Pop。參數X為要進行Pop的堆疊代號，X=1時表示堆疊A，X=2時表示堆疊B。
●[3 X]
列印出堆疊的名稱，接著從索引0開始列印堆疊全部的元素內容。每個列印請以空格分隔，結束時換下一行。堆疊A的名稱請列印'A'，堆疊B的名稱請列印'B'。參數X為要進行列印的堆疊代號，X=1時表示堆疊A，X=2時表示堆疊B。

結果輸出：
根據指令來列印，請參考輸出範例。


輸入範例：
12
1 1 5
1 2 10
1 1 20
1 1 40
3 1
3 2
2 1
2 2
1 1 80
1 2 160
3 1
3 2

輸出範例：
A 5 20 40
B 10
A 5 20 80
B 160
*/

#include <iostream>
using namespace std;

const int stack_size = 100;
int stack_a[stack_size];
int stack_b[stack_size];
int top_a = -1;
int top_b = -1;

void stack_push(int stack[], int &top, int value)
{
    if (top < stack_size - 1)
    {
        stack[++top] = value;
    }
}

void stack_pop(int stack[], int &top)
{
    if (top > -1)
    {
        top--;
    }
}

void stack_print(int stack[], int top, char name)
{
    cout << name << " ";
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int id;
        cin >> id;
        if (id == 1)
        {
            int stack_id, value;
            cin >> stack_id >> value;
            if (stack_id == 1)
            {
                stack_push(stack_a, top_a, value);
            }
            else
            {
                stack_push(stack_b, top_b, value);
            }
        }
        else if (id == 2)
        {
            int stack_id;
            cin >> stack_id;
            if (stack_id == 1)
            {
                stack_pop(stack_a, top_a);
            }
            else
            {
                stack_pop(stack_b, top_b);
            }
        }
        else
        {
            int stack_id;
            cin >> stack_id;
            if (stack_id == 1)
            {
                stack_print(stack_a, top_a, 'A');
            }
            else
            {
                stack_print(stack_b, top_b, 'B');
            }
        }
    }
    return 0;
}