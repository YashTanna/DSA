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
    imp()
    {
        first = NULL;
    }
    void insert_after(int ee,int ne);
    void insert(int);
    void display();
    void insert_before(int ee,int ne);
    void delet_after(int ee,int num);
};

void imp ::delet_after(int ee,int num)
{
    node * temp = first;
    while(temp->link != NULL && temp->data != ee)
    {
        temp = temp->link;
    }
    if(temp->link == NULL)
    {
        cout<<"Element not found\n";
        exit(0);
    }
    else
    {
        for(int i=0;i<num;i++)
        {
            temp->link = temp->link->link;
        }
    }
}

void imp ::insert_before(int ee,int ne)
{
    node * temp = first;
    while(temp->link->data != ee && temp->link->data != NULL)
    {
        temp = temp->link;
    }
    if(temp->link == NULL)
    {
        cout<<"Element not found\n";
        exit(0);
    }
    else
    {
        node * new_element = new node(ne);
        new_element->link = temp->link;
        temp->link = new_element;
    }

}

void imp ::insert_after(int ee,int ne)
{
    node * temp = first;
    while(temp->data != ee && temp->link!= NULL)
    {
        temp = temp->link;
    }
    if(temp->link == NULL)
    {
        cout<<"Element not found\n";
        exit(0);
    }
    else
    {
        node * new_element = new node(ne);
        new_element->link = temp->link;
        temp->link = new_element;
    }
}

void imp ::display()
{
    node * temp = first;
    while(temp->link != NULL)
    {
        cout<<temp->data<<"  ";
        temp = temp->link;
    }
    cout<<temp->data<<endl;
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


main()
{
    int n,num;
    cout<<"Enter number\n";
    cin>>n;
    imp * list = new imp();
    cout<<"Enter "<<n<<" numbers\n";
    for(int i=0;i<n;i++)
    {
        cin>>num;
        list->insert(num);
    }
    cout<<"Element of LinkList is \n";
    list->display();

    // cout<<"Enter which and before which element you want to add new element\n";

    // cin>>num>>n;

    // list->insert_before(n,num);

    // cout<<"Element of LinkList is \n";
    // list->display();

    cout<<"From where and how namy element you want to delet\n";
    cin>>num>>n;

    list->delet_before(num);

    cout<<"New LinkList after delet is \n";
    list->display();

    return 0;
}