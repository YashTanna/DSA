#include<iostream>
#include<string>
#include<vector>

using namespace std;
main()
{
    int m,n;
    cin>>m>>n;
    vector <int> graph[n];

    for(int i=0;i<m;i++)
    {
        int v1,v2;
        cin>>v1>>v2;

        graph[v1].push_back(v2);
        graph[v2].push_baack(v1);

    }

    /*For Weighted graph

    vector <pair <int,int> > graph[n];

    for(int i=0;i<m;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;

        graph[v1].push_back({v2,wt});
        graph[v2].push_back({v1,wt});
    }
    
    */

    return 0;
}