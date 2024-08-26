#include <iostream>
#include <string>
using namespace std;

class poly;

class term
{
    int cof;
    int exp;
    term *link;

public:
    term(int c, int e)
    {
        cof = c;
        exp = e;
        link = NULL;
    }
    friend class poly;
};

class poly
{
    term *first;

public:
    term *getfirst()
    {
        return first;
    }
    poly()
    {
        first = NULL;
    }
    void insert(int c, int e);
    void display();
    void add(term *p, term *q);
};

void poly ::add(term *p, term *q)
{
    term *t1 = p;
    term *t2 = q;
    int cof, exp;
    while (t1 != NULL && t2 != NULL)
    {
        if (t1->exp == t2->exp)
        {
            cof = t1->cof + t2->cof;
            exp = t1->exp;
            t1 = t1->link;
            t2 = t2->link;
        }
        else if (t1->exp > t2->exp)
        {
            cof = t1->cof;
            exp = t1->exp;
            t1 = t1->link;
        }
        else
        {
            cof = t2->cof;
            exp = t2->exp;
            t2 = t2->link;
        }
        insert(cof, exp);
    }
    while (t1 != NULL)
    {
        insert(t1->cof, t1->exp);
        t1 = t1->link;
    }
    while (t2 != NULL)
    {
        insert(t2->cof, t2->exp);
        t2 = t2->link;
    }
}

void poly ::insert(int c, int e)
{
    term *nn = new term(c, e);
    if (first == NULL)
    {
        first = nn;
    }
    else
    {
        term *temp = first;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = nn;
    }
}

void poly ::display()
{
    term *temp = first;
    while (temp->link != NULL)
    {
        cout << temp->cof << "x^" << temp->exp << " + ";
        temp = temp->link;
    }
    cout << temp->cof << "x^" << temp->exp << endl;
}

main()
{
    poly *p1 = new poly();
    cout << "Enter number of terms\n";
    int n;
    cin >> n;
    cout << "Enter " << n << " numbers\n";
    int cof, exp;
    for (int i = 0; i < n; i++)
    {
        cin >> cof >> exp;
        p1->insert(cof, exp);
    }

    p1->display();

    poly *p2 = new poly();
    cout << "Enter number of terms\n";

    cin >> n;

    cout << "Enter " << n << " numbers\n";
    for (int i = 0; i < n; i++)
    {
        cin >> cof >> exp;
        p2->insert(cof, exp);
    }

    p1->display();

    poly *sum = new poly();

    sum->add(p1->getfirst(), p2->getfirst());

    cout << "Polynomial aaddition is \n";
    sum->display();
    return 0;
}