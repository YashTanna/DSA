#include<iostream>
#include<string>
using namespace std;

class list;

class node
{
    int data;
    node * next;
    //node * prev;
    public:
    node(int d,node * first)
    {
        data = d;
        next = first;
    }
    friend class list;
};

class list
{
    node * first;
    public:
    list()
    {
        first = nullptr;
    }
    void insert(int d);
    void display();
};

void list ::insert(int d)
{
    node * nn = new node(d,first);
    if(first == nullptr)
    {
        first = nn;
        nn->next = nn;
    }
    else
    {
        node * temp = first;
        while(temp->next!= first)
        {
            temp = temp->next;
        }
        temp->next = nn;
    }
}

void list ::display()
{
    node * temp = first;
    while(temp->next != first)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }

    cout<<temp->data<<endl;
}

main()
{
    
    return 0;
}