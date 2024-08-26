#include<iostream>
#include<string>
using namespace std;


class poly;


class term
{
    int cof;
    int exp;
    public:
    friend class poly;
};

class poly
{
    int n;
    term * terms;
    public:
    poly(){terms = NULL;}
    poly * mult(poly * p1, poly * p2,poly * p3);
    void create();
    void display();
};

void poly ::create()
{
    
}

poly* poly::mult(poly * p1,poly * p2,poly * p3)
{
    int i,j,k,flag;
    int co,exp;
    int next3;
    i = next3 = 0;
    while(i<p1[i]->n)
    {
        j=0;
        while(j<p2[j]->n)
        {
            exp = p1[i]->exp + p2[j]->exp;
            co = p1[i]->cof * p2[j]->cof;
            k = flag = 0;
            while(k<p3[k]->n)
            {
                if(p3[k]. == exp)
            }
        }
    }
}

main()
{
    
    return 0;
}


