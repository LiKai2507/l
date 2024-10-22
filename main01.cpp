#include <iostream>
using namespace std;

class Stack
{
private:
    int capacity;
    int *array;
    int top;

public:
    Stack()
    {
        capacity = 10;
        array = new int[capacity];
        top = -1;
    }

    void Push(int x)
    {
        array[++top] = x;
    }

    void Pop()
    {
        top--;
    }

    void PrintStack()
    {
        for (int i = top; i >= 0; i--)
        {
            cout << array[i] << " ";
        }
    }
};

int main()
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