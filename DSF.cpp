#include<iostream>
#include<string>
#include<vector>
using namespace std;

const int N = 100;

bool vis[N] = {false};

vector <int> graph[N];

void dsf(int var)
{
    cout<<var<<endl;
    vis[var] = true;
    for(int child : graph[var])
    {
        cout<<"Par"<<var<<" Child"<<child<<endl;

        if(!vis[child])
            dsf(child);    


    }
}

main()
{
    int m;
    cin>>m;
    for(int i=0;i<m;i++)    
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }

    dsf(1);

    return 0;
}