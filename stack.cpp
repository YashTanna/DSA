#include <iostream>
#include <string>
using namespace std;

class stack
{
    int stack[100];
    int top = -1;

public:
    void push(int d);
    void pop();
    void print();
    bool IsEmpty();
    // void top();
};

void stack ::push(int d)
{
    if (top >= 100)
    {
        cout << "Stack overflow\n";
    }
    else
    {
        stack[++top] = d;
    }
}

void stack ::pop()
{
    if (top == -1)
    {
        cout << "Stack is underflow\n";
    }
    else
    {
        top--;
    }
}

void stack ::print()
{
    for (int i = 0; i <= top; i++)
    {
        cout << stack[i] << "  ";
    }
    cout << endl;
}

bool stack ::IsEmpty()
{
    if (top == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

main()
{
    stack s1;
    cout << "Enter number\n";
    int n, num;
    cin >> n;
    cout << "Emter " << n << " number\n";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        s1.push(num);
    }

    if (s1.IsEmpty())
    {
        cout << "Stack is Empty\n";
    }
    else
    {
        cout << "Stack is not Empty\n";
    }

    cout << "Element of stack is \n";
    s1.print();

    cout << "How many element you want to delet?\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        s1.pop();
    }

    cout << "Element of stack after deleting is \n";
    s1.print();

    return 0;
}