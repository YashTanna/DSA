#include<iostream>
#include<string>
#include<stack>
using namespace std;

int prec(char op)
{
    switch(op)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '#': return 0;
    }
    return 0;
}

string intopost(string infix)
{
    string postfix = "";
    stack <char> s;
    for(char ch : infix)
    {
        if(isalnum(ch))
        {
            postfix += ch;
        }
        else if(ch == '(')
        {
            s.push(ch);
        }
        else if(ch == ')')
        {
            while(!s.empty() && ch != '(')
            {
                postfix += s.top();
                s.pop();
            }
            if(!s.empty() && s.top() == '(')
            {
                s.pop();
            }
        }
        else
        {
            while(!s.empty() && prec(ch) <= prec(s.top()))
            {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }
    while(!s.empty())
    {
        postfix += s.top();
        s.pop();
    }
    return postfix;
}

main()
{
    string postfix = intopost("a+b*c-d/e");
    cout<<postfix<<endl;
    return 0;
}