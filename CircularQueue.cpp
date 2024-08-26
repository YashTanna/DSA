#include <iostream>
#include <string>
using namespace std;

#define size 5

class queue
{
    int a[size];
    int front = -1, rear = -1;

public:
    void enqueue(int d);
    void dequeue();
    bool queuefull();
    bool queueEmpty();
    void display();
};

void queue ::display()
{
    int i = front;
    do
    {
        cout << a[i] << " ";
        i = (i + 1) % size;
        if (i == (rear + 1) % size)
        {
            break;
        }
    } while (i != front);

    cout << endl;
}

void queue ::enqueue(int d)
{
    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % size;
    }
    a[rear] = d;
}

void queue ::dequeue()
{
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % size;
    }
}

bool queue ::queueEmpty()
{
    if (front == -1)
        return true;
    return false;
}

bool queue ::queuefull()
{
    if (front == (rear + 1) % size)
        return true;
    return false;
}

main()
{
    queue q1;
    int n;
    for (int i = 0; i < 6; i++)
    {
        cin >> n;
        q1.enqueue(n);
    }
    q1.dequeue();
    q1.display();
    return 0;
}