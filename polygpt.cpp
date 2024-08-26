#include <iostream>
#include <string>
using namespace std;

class polynomial;

class term
{
    int cof;
    int exp;
    term * link;

public:
    friend class polynomial;
    term(int c, int e)
    {
        cof = c;
        exp = e;
        link = NULL;
    }
};

class polynomial
{
    term *first;

public:
    void setfirst(term *p)
    {
        first = p;
    }
    term *getfirst()
    {
        return first;
    }
    void addpolynomial(term *p1, term *p2);
    polynomial() { first = NULL; }
    void insert(int a, int b);
    void display();
};

void polynomial::addpolynomial(term *p1, term *p2)
{
    term *a = p1;
    term *b = p2;
    int exp = 0, cof = 0;
    while (a != NULL && b != NULL)
    {
        if (a->exp == b->exp)
        {
            exp = a->exp;
            cof = a->cof + b->cof;
            a = a->link;
            b = b->link;
        }
        else if (a->exp > b->exp)
        {
            exp = a->exp;
            cof = a->cof;
            a = a->link;
        }
        else
        {
            exp = b->exp;
            cof = b->cof;
            b = b->link;
        }
        this->insert(cof, exp); // Update the current polynomial directly
    }
    while (a != NULL)
    {
        this->insert(a->cof, a->exp); // Update the current polynomial directly
        a = a->link;
    }
    while (b != NULL)
    {
        this->insert(b->cof, b->exp); // Update the current polynomial directly
        b = b->link;
    }
}

void polynomial::insert(int c, int e)
{
    term *nn = new term(c, e);
    term *temp = first;
    if (first == NULL)
    {
        first = nn;
    }
    else
    {
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = nn;
    }
}

void polynomial::display()
{
    term *temp = first;
    while (temp != NULL)
    {
        cout << temp->cof << "x^" << temp->exp;
        if (temp->link != NULL)
        {
            cout << " + ";
        }
        temp = temp->link;
    }
    cout << endl;
}

int main()
{
    polynomial *p1 = new polynomial();
    polynomial *p2 = new polynomial();

    cout << "Enter the number of terms\n";
    int n;
    int cof, exp;
    cin >> n;
    cout << "Enter polynomial terms\n";
    for (int i = 0; i < n; i++)
    {
        cin >> cof >> exp;
        p1->insert(cof, exp);
    }

    cout << "Enter the number of terms\n";
    cin >> n;
    cout << "Enter polynomial terms\n";
    for (int i = 0; i < n; i++)
    {
        cin >> cof >> exp;
        p2->insert(cof, exp);
    }

    polynomial *p = new polynomial();
    p->addpolynomial(p1->getfirst(), p2->getfirst());

    cout << "Polynomial addition is \n";
    p->display();

    return 0;
}
