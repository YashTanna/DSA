#include <bits/stdc++.h>
using namespace std;


int fib(int n,vector<int> &dp){
    if(n <= 1){
        return n;
    }

    if(dp[n] != -1){
        return dp[n];
    }

    dp[n] = fib(n-1,dp) + fib(n-2,dp);
    return dp[n];
}

int main(){

    cout<< "Enter Number"<<endl;
    int n;
    cin>>n;

    vector<int> dp(n+1,-1);


    printf("Fibonacci number for %dth element is %d",n,fib(n,dp));

    return 0;
}