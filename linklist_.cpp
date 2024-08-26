#include<iostream>
#include<string>
using namespace std;

class imp;

class node
{
    int data;
    node * link;
    public:
    friend class imp;
    node(int d)
    {
        data = d;
        link = NULL;
    }
};



class imp
{
    node * first;
    public:
    imp(){first = NULL;}
    void insert(int d);
    void print();
    void reverse(int);
};

void imp ::reverse(int n)
{
    node * temp = first;
    node * rev[n];
    int i=0;
    while(temp->link!=NULL)
    {
        rev[i++] = temp;
        temp = temp->link;
    }
    rev[i] = temp;

    for(int i=n-1;i>=0;i--)
    {
        cout<<rev[i]->data<<"  ";
    }
}

void imp ::insert(int d)
{
    node * n1 = new node(d);
    if(first == NULL)
    {
        first = n1;
    }
    else
    {
        node * temp = first;
        while(temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = n1;
    }
}

void imp ::print()
{
    node * temp = first;
    while(temp != NULL)
    {
        cout<<temp->data<<"  ";
        temp = temp->link;
    }
    cout<<endl;
}

main()
{
    imp linklist;
    cout<<"Enter number\n";
    int n,num;
    cin>>n;
    cout<<"Enter "<<n<<" numbers\n";
    for(int i=0;i<n;i++)   
    {
        cin>>num;
        linklist.insert(num);
    }
    cout<<"Element of linklist is \n";
    linklist.print();

    cout<<"Reverse of linklist is \n";
    linklist.reverse(n);
    return 0;
}