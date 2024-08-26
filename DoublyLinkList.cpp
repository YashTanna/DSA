#include <iostream>
#include <string>
using namespace std;

class implement;
class node
{
protected:
    int data;
    node *prev;
    node *next;

public:
    node(int d)
    {
        data = d;
        prev = next = NULL;
    }
    friend class implement;
};

class implement
{
    node *first;

public:
    implement()
    {
        first = NULL;
    }
    void Insert(int d);
    void InsertAfter(int x, int d);
    void InsertBefore(int x, int d);
    void InsertBegin(int d);
    void DeleteAfter(int x);
    void DeletBefore(int x);
    void Display();
};

void implement ::Insert(int d)
{
    node *nn = new node(d);
    if (first == NULL)
    {
        first = nn;
    }
    else
    {
        node *temp = first;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        nn->prev = temp;
        temp->next = nn;
    }
}

void implement ::InsertAfter(int x, int d)
{
    node *nn = new node(d);
    node *temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
    }

    nn->prev = temp;
    if (temp->next != NULL)
    {
        nn->next = temp->next;
        temp->next->prev = nn;
    }
    temp->next = nn;
}

void implement ::InsertBefore(int x, int d)
{
    node *nn = new node(d);
    node *temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
    }

    nn->next = temp;
    nn->prev = temp->prev;
    temp->prev->next = nn;
    temp->prev = nn;
}

void implement ::InsertBegin(int d)
{
    node *nn = new node(d);
    nn->next = first;
    first = nn;
}

void implement ::DeleteAfter(int x)
{
    node *temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
    }
    if (temp->next->next == NULL)
    {
        temp->next->prev = NULL;
        temp->next = NULL;
    }
    else
    {
        temp->next = temp->next->next;
        temp->next->prev = temp;
    }
}

void implement ::DeletBefore(int x)
{
    node *temp = first;
    while (temp->data != x)
    {
        temp = temp->next;
    }
    temp->prev = temp->prev->prev;
    temp->prev->next = temp;
}

void implement ::Display()
{
    node *temp = first;
    while (temp->next != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << endl;
}

main()
{
    implement list;
    int num;
    for (int i = 0; i < 5; i++)
    {
        cin >> num;
        list.Insert(num);
    }

    list.Display();
    int a;
    cin >> a;
    list.DeleteAfter(a);

    list.Display();
    return 0;
}