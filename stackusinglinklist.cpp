#include <iostream>
#include <string>
using namespace std;

class imp;

class node
{
    int num;
    node *link;

public:
    node(int d)
    {
        num = d;
        link = NULL;
    }
    friend class imp;
};
 
class imp
{
    
    protected:
    node * first;
    imp()
    {
        first = NULL;
    }
    void insert(int d);
    void delet();
    void display();
};

void imp ::insert(int d)
{
    node *nn = new node(d);
    if (first == NULL)
    {
        first = nn;
    }
    else
    {
        node *temp = first;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = nn;
    }
}

void imp ::display()
{
    node *temp = first;
    while (temp->link != NULL)
    {
        cout << temp->num << " ";
        temp = temp->link;
    }
    cout << temp->num << endl;
}

void imp ::delet()
{
    node *temp = first;
    while (temp->link->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = temp->link->link;
}

// imp *st = new imp();

class stack : public imp
{
    public:

    void push(int d)
    {
        insert(d);
    }

    void pop()
    {
        delet();
    }

    void display()
    {
        imp::display();
    }
};
main()
{
    cout<<"Enter number\n";
    stack * s1 = new stack();
    int n;
    cin>>n;
    int num;
    cout<<"Enter "<<n<<" number\n";
    for(int i=0;i<n;i++)
    {
        cin>>num;
        s1->push(num);
    }

    cout<<"Element of stack is \n";
    s1->display();

    cout<<"How many number you want to delet\n";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        s1->pop();
    }

    cout<<"Element of stack after delet is \n";
    s1->display();
    return 0;
}