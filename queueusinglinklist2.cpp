#include<iostream>
#include<string>
using namespace std;

class queue;

class qnode
{
    protected:
    int data;
    qnode * link;
    public:
    qnode(int d)
    {
        data = d;
    }
    friend class queue;
};

class queue
{
    qnode * head;
    qnode * tail;
    public:
    queue()
    {
        head = tail = nullptr;
    }
    void enqueue(int d);
    void dequeue();
    void display();
};

void queue ::enqueue(int d)
{
    if(head == nullptr)
    {
        head = tail = new qnode(d);
    }
    else
    {
        tail = tail->link = new qnode(d);
    }
}

void queue ::dequeue()
{
    if(head == tail)
    {
        cout<<"Queue is empty\n";
    }
    else
    {
        head = head->link;;
    }
}

void queue ::display()
{
    qnode * temp = head;
    while(temp != tail)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<temp->data<<endl;

}

main()
{
    queue list;
    int num,n;
    cout<<"How many element you want to add?\n";
    cin>>n;

    cout<<"Enter "<<n<<" element\n";
    for(int i=0;i<n;i++)
    {
        cin>>num;
        list.enqueue(num);
    }

    list.display();
    
    cout<<"Enter how many element you want to delete?\n";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        list.dequeue();
    }

    list.display();

    return 0;
}