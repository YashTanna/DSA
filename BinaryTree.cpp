#include <iostream>
#include <string>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = right = nullptr;
    }
};

class Binarytree
{
public:
    node *root;
    Binarytree()
    {
        root = nullptr;
    }

    void insertRec(node *&now, node *&new)
    {
        if (new->data > now->data)
        {
            if (now->right == NULL)
            {
                now->right = new;
            }
            else
            {
                insertRec(now->right, new);
            }
        }

        if (now->data > new->data)
        {
            if (now->left == NULL)
            {
                now->left = new;
            }
            else
            {
                insertRec(now->left, new);
            }
        }
    }

    node *serch(node *root, int d)
    {
        node *temp = root;
        while (temp != NULL)
        {
            if (temp->data == d)
            {
                return temp;
            }

            if (d > temp->data)
            {
                temp = temp->right;
            }

            if (d < temp->data)
            {
                temp = temp->left;
            }
        }
    }

    void insert(int d)
    {
        node *nn = new node(d);
        insertRec(root, nn);
    }
};

void preord(node *first)
{
    if (first == nullptr)
        return;

    cout << first->data;
    preord(first->left);
    preord(first->right);
}

main()
{
    Binarytree b;
    for (int i = 1; i <= 6; i++)
    {
        b.insert(i);
    }

    preord(b.root);
    return 0;
}