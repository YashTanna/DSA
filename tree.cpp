#include <iostream>
#include <string>
#include <queue>
using namespace std;

class node
{
public:
    node *left;
    int data;
    node *right;
    node(int d)
    {
        data = d;
        left = right = nullptr;
    }
};

node *create()
{
    node *root;
    node *temp, * temp2;
    int x;
    queue<node *> q;
    cout << "Enter root\n";
    cin >> x;
    root = new node(x);

    q.push(root);
    while (!q.empty())
    {
        temp = q.front();
        q.pop();

        cout << "Enter Left child of " << temp->data << endl;
        cin >> x;

        if (x != -1)
        {
            temp2 = new node(x);
            q.push(temp2);
            temp->left = temp2;
        }
        cout << "Enter Right child of " << temp->data << endl;
        cin>>x;

        if(x!= -1)
        {
            temp2 = new node(x);
            q.push(temp2);
            temp->right = temp2;
        }
    }
    return root;
}

void inorder(node * root)
{
    if(root)
    {
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(node * root)
{
    if(root)
    {
        preorder(root->left);
        preorder(root->right);
        cout<<root->data<<" ";
    }
}

void postorder(node * root)
{
    if(root)
    {
        cout<<root->data<<" ";
        postorder(root->left);
        postorder(root->right);
    }
}

main()
{
    node * root = create();
    inorder(root);
    return 0;   
}