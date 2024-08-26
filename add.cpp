#include<iostream>
#include<string>
using namespace std;

class poly;
class term
{
    int cof;
    int pow;
    public:
    friend class poly;
};

class poly
{
    int n;
    term * num;
    public:
    poly(){}
    void create();
    void display();
    void add(poly * p1,poly * p2);
};

void poly::add(poly * p1,poly * p2)
{
    num = new term[p1->n+p2->n];
    int i,j,k;
    i=j=k=0;
    while(i<p1->n && j<p2->n)
    {
        if(p1->num[i].pow == p2->num[j].pow)
        {
            num[k].cof = p1->num[i].cof + p2->num[j].cof;
            num[k++].pow = p1->num[i++].pow;
            j++;
        }
        else if(p1->num[i].pow > p2->num[j].pow)
        {
            num[k++] = p1->num[i++];
        }
        else
        {
            num[k++] = p2->num[j++];
        }
        n = k;
    }

    while(i<p1->n)
    {
        num[k++] = p1->num[i++];
    }

    while(j<p2->n)
    {
        num[k++] = p2->num[j++];
    }
}

void poly ::create()
{
    cout<<"Enter number\n";
    cin>>n;
    num = new term[n];
    cout<<"Enter "<<n<<" number\n";
    for(int i=0;i<n;i++)
    {
        cin>>num[i].cof>>num[i].pow;
    }
}

void poly ::display()
{
    int i;
    for(i=0;i<n-1;i++)
    {
        cout<<num[i].cof<<"x^"<<num[i].pow<<" + ";
    }
    cout<<num[i].cof<<endl;
}

main()
{
    poly * p1 = new poly;
    p1->create();
    cout<<"First Polynomial Equation is \n";
    p1->display();

    poly * p2 = new poly;
    p2->create();
    cout<<"Second Polynomial Equation is \n";
    p2->display();

    poly * p = new poly;
    p->add(p1,p2);
    cout<<"Addition of Polynomial Equation is \n";
    p->display();
    return 0;
}