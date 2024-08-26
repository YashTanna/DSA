void DFS(int g[][],int start,int n)
{
    stack <int> s;
    int visited[n] = {0};
    cout<<start<<" ";
    visited[start] = 1;
    s.push(strat);
    int i;
    int n;
    while(!s.empty())
    {
        n = s.top();
        s.pop();

        for(i=1;i<n;i++)
        {
            if(g[start][i] == 1 && visited[i] == 0)
            {
                cout<<i<<" ";
                visited[i] = 1;
                s.push(i);
            }
        }
    }
}