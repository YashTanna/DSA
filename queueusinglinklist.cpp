#include<iostream>
#include<string>
using namespace std;

class imp;

class node
{
    int data;
    node * link;
    public:
    node(int d)
    {
        data = d;
        link = NULL;
    }
    friend class imp;
};

class imp
{
    protected:
    node * first;
    
    void insert(int d);
    void display();
    void delet();
};

void imp ::delet()
{
    first = first->link;
}

void imp ::insert(int d)
{
    node * nn = new node(d);
    if(first == NULL)
    {
        first = nn;
    }
    else
    {
        node * temp = first;
        while(temp->link!=NULL)
        {
            temp = temp->link;
        }
        temp->link = nn;
    }
}

void imp ::display()
{
    node * temp = first;
    while(temp->link!=NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<temp->data<<endl;
}



class queue : public imp
{
    public:
    void enqueue(int d)
    {
        insert(d);
    }

    void dequeue()
    {
        delet();
    }

    void print()
    {
        display();
    }
};

main()
{
    queue * list = new queue();
    cout<<"Enter number of element\n";
    int n;
    cin>>n;
    cout<<"Enter "<<n<<" number\n";
    int num;
    for(int i=0;i<n;i++)   
    {
        cin>>num;
        list->enqueue(num);
    }

    cout<<"Element of queue is \n";
    list->print();

    cout<<"Enter how many number youy want to delet\n";
    cin>>n;
    cout<<"Enter "<<n<<" number\n";
    for(int i=0;i<n;i++)
    {
        list->dequeue();
    }

    cout<<"Element of queue after delet\n";
    list->print();
    return 0;
}