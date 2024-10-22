/*
請寫一個Stack類別，裡面有建構子，Push(int x)、Pop()、PrintStack() 三個函式和 int capacity、int* array、int top 三個變數。capacity定義堆疊大小，array當作堆疊，top紀錄目前堆疊頂端的索引值，初始值設為-1表示堆疊為空。建構子將變數capacity、top設初始值，並建立長度為capacity的array，Push(int x)可將變數x加入到array堆疊頂端，Pop()可從array堆疊頂端取出一個元素，PrintStack()則列印出堆疊全部的元素內容(從由上而下Top-Down)。

注意：預設程式中main函式請勿修改，僅可加上函式定義與函式原型。

輸入範例：
6 10 20 30 40 50 60 2

輸出範例：
40 30 20 10

系統輸入：Push次數(最多10)+放入堆疊的元素+Pop次數

結果輸出：函式PrintStack()的執行結果
*/
#include <iostream>
using namespace std;

class Stack
{
public:
    Stack()
    {
        capacity = 10;
        array = new int[capacity];
        top = -1;
    }

    void Push(int x)
    {
        if (top + 1 < capacity)
            array[++top] = x;
    }

    int Pop()
    {
        if (top >= 0)
            return array[top--];
    }

    void PrintStack()
    {
        for (int i = top; i >= 0; i--)
            cout << array[i] << " ";
    }

private:
    int capacity;
    int *array;
    int top;
};

int main(int argc, char *argv[])
{
    Stack stack;
    int times, input;
    cin >> times;
    for (int i = 0; i < times; i++)
    {
        cin >> input;
        stack.Push(input);
    }
    cin >> times;
    for (int i = 0; i < times; i++)
    {
        stack.Pop();
    }
    stack.PrintStack();
}
