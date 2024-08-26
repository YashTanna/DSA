#include <iostream>
#include <string>
using namespace std;

class queue
{
    int queuea[99];
    int head, tail;

public:
    queue()
    {
        head = -1;
        tail = -1;
    }
    void enqueue(int d);
    void dequeue();
    void print();
};

void queue ::enqueue(int d)
{
    if (tail == 100)
    {
        cout << "Queue is overflow\n";
    }
    else if (head == -1)
    {
        head++;
    }
    queuea[++tail] = d;
}

void queue ::dequeue()
{
    if (tail == head)
    {
        cout << "Queue is underflow\n";
    }
    else
    {
        head++;
    }
}

void queue ::print()
{
    for (int i = head; i <= tail; i++)
    {
        cout << queuea[i] << "  ";
    }
    cout << endl;
}

main()
{
    queue q1;
    cout << "Enter number\n";
    int n = 0;
    int num = 0;
    cin >> n;
    cout << "Enter " << n << " number\n";
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        q1.enqueue(num);
    }

    cout << "Element of Queue is \n";
    q1.print();

    cout << "How many element you want to delet\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        q1.dequeue();
    }

    cout << "Element of Queue after deleting is\n";
    q1.print();
    return 0;
}