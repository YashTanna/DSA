#include<bits/stdc++.h>
using namespace std;

int solve(long long nStairs,long long i){
    if(nStairs == i){
        return 1;
    }

    if(i > nStairs){
        return 0;
    }

    return (solve(nStairs,i+1) + solve(nStairs,i+2));
}

int countWays(long long nStairs){
    int res = solve(nStairs,0);
    return res;
}

main()
{
    int n;
    cin>>n;

    cout<<"Number of distinct way to climb "<< n <<"Stairs is " << countWays(n);

    return 0;
}