#include<iostream>
#include<string>
using namespace std;
main()
{
    int n,m;
    cin>>n>>m;
    int graph[n+1][n+1] = {0};

    for(int i=0;i<m;++i)
    {
        int v1,v2;
        cin>>v1>>v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;

        /*For weighted graph

        int wt;

        graph[v1][v2] = wt;
        graph[v2][v1] = wt;
        
        */

    }

    return 0;
}