#include<iostream>
#include<string>
using namespace std;

class poly;

class term {
    int cof;
    int exp;
    friend class poly;
};

class poly {
    int n;
    term* terms;
public:
    poly() {
        terms = NULL;
    }
    poly* add(poly* p1, poly* p2);
    void create();
    void display();
};

poly* poly::add(poly* p1, poly* p2) {
    poly* p = new poly;
    p->n = p1->n + p2->n;
    p->terms = new term[p->n];
    int i = 0, j = 0, k = 0;
    while (i < p1->n && j < p2->n) {
        if (p1->terms[i].exp == p2->terms[j].exp) {
            p->terms[j].cof = p1->terms[i].cof + p2->terms[j].cof;
            p->terms[k].exp = p1->terms[i].exp;
            i++;
            j++;
            k++;
        }
        else if (p1->terms[i].exp > p2->terms[j].exp) {
            p->terms[k].exp = p1->terms[i].exp;
            p->terms[k++].cof = p1->terms[i++].cof;
        }
        else {
            p->terms[k].exp = p2->terms[j].exp;
            p->terms[k++].cof = p2->terms[j++].cof;
        }
    }
    while (i < p1->n) {
        p->terms[k].exp = p1->terms[i].exp;
        p->terms[k++].cof = p1->terms[i++].cof;
    }
    while (j < p2->n) {
        p->terms[k].exp = p2->terms[j].exp;
        p->terms[k++].cof = p2->terms[j++].cof;
    }
    return p;
}

void poly::create() {
    cout << "Enter number\n";
    cin >> n;
    terms = new term[n];
    cout << "Enter coefficient and power\n";
    for (int i = 0; i < n; i++) {
        cin >> terms[i].cof >> terms[i].exp;
    }
}

void poly::display() {
    int i;
    for (i = 0; i < n - 1; i++) {
        cout << terms[i].cof << "x^" << terms[i].exp << " + ";
    }
    cout << terms[i].cof << "x^" << terms[i].exp;
    cout << endl;
}

int main() {
    poly* p1;
    poly* p2;
    poly* p;
    p1 = new poly;
    p2 = new poly;
    p = new poly;
    p1->create();
    cout << "Polynomial of p1 is \n";
    p1->display();

    p2->create();
    cout << "Polynomial of p2 is \n";
    p2->display();

    p = p->add(p1, p2);
    cout << "Sum of these two polynomials is \n";
    p->display();
    return 0;
}
