#include <iostream>
#include <string>
using namespace std;

class imp;

class node
{
    int exp;
    int cof;
    node *link;

public:
    node(int a, int b)
    {
        cof = a;
        exp = b;
        link = nullptr;
    }
    friend class imp;
};

class imp
{
    node *first;

public:
    imp()
    {
        first = nullptr;
    }
    void insert(int c, int e);
    void display();
    void polymul(node *n1, node *n2);
    node *getfirst()
    {
        return first;
    }
};

void imp::insert(int c, int e)
{
    node *nn = new node(c, e);
    if (first == nullptr)
    {
        first = nn;
    }
    else
    {
        node *temp = first;
        while (temp->link != nullptr)
        {
            temp = temp->link;
        }
        temp->link = nn;
    }
}

void imp::display()
{
    node *temp = first;
    while (temp != nullptr)
    {
        cout << temp->cof << "x^" << temp->exp;
        if (temp->link != nullptr)
        {
            cout << " + ";
        }
        temp = temp->link;
    }
    cout << endl;
}

void imp::polymul(node *n1, node *n2)
{
    node *temp1 = n1;
    node *temp2 = n2;
    int cof, exp;
    int flag;

    // Clear any previous content in the list
    while (first != nullptr)
    {
        node *temp = first;
        first = first->link;
        delete temp;
    }

    while (temp1 != nullptr)
    {
        temp2 = n2;
        while (temp2 != nullptr)
        {
            cof = temp1->cof * temp2->cof;
            exp = temp1->exp + temp2->exp;
            flag = 0;
            node *temp3 = first;
            while (temp3 != nullptr)
            {
                if (temp3->exp == exp)
                {
                    flag = 1;
                    break;
                }
                else
                {
                    temp3 = temp3->link;
                }
            }
            if (flag == 1)
            {
                temp3->cof += cof;
            }
            else
            {
                // Insert new node at the beginning of the list
                insert(cof,exp);
            }
            temp2 = temp2->link;
        }
        temp1 = temp1->link;
    }
}

int main()
{
    imp polyResult;
    imp poly1;
    imp poly2;

    // Insert elements in the polynomial 1
    poly1.insert(2, 3);
    poly1.insert(3, 2);
    poly1.insert(1, 0);

    // Insert elements in the polynomial 2
    poly2.insert(4, 2);
    poly2.insert(1, 0);

    // Perform polynomial multiplication and display the result
    polyResult.polymul(poly1.getfirst(), poly2.getfirst());
    cout << "Polynomial 1: ";
    poly1.display();
    cout << "Polynomial 2: ";
    poly2.display();
    cout << "Resultant Polynomial: ";
    polyResult.display();

    return 0;
}
