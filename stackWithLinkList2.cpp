#include<iostream>
#include<string>
using namespace std;

class stack;

class stacknode
{
    protected:
    int data;
    stacknode * link;
    public:
    stacknode(){}
    stacknode(int d,stacknode * top)
    {
        data = d;
        link = top;
    }
    friend class stack;
};

class stack : public stacknode
{
    stacknode * top = nullptr;
    public:
    // stack(){top = nullptr;}
    void push(int d);
    void pop();
    void display();
};

void stack::push(int d)
{
    stacknode * temp;
    top = temp = new stacknode(d,top);
}


void stack ::pop()
{
    if(top==nullptr)
    {
        cout<<"Stack is underflow\n";
        exit(0);
    }   
        
    top = top->link;
}

void stack ::display()
{
    stacknode * temp = top;
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp = temp->link;
    }
    cout<<endl;
}

main()
{
    stack s1;
    int n;
    cout<<"How many number you want to enter?\n";
    cin>>n;
    int num;
    cout<<"Enter "<<n<<" number\n";
    for(int i=0;i<n;i++)   
    {
        cin>>num;
        s1.push(num);
    }

    s1.display();
    cout<<"How many nuumber you want to delete?\n";
    cin>>n;

    for(int i=0;i<n;i++)
    {
        s1.pop();
    }

    s1.display();
    return 0;
}