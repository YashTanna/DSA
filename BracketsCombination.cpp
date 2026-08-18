#include <bits/stdc++.h>
using namespace std;

void solution(int right, int left,int n, string res, vector<string> &result){

    if(right+left == (2*n)){
        result.push_back(res);
    }

    if(right < n){
        solution(right+1,left,n,res+'(',result);
    }

    if(left < right){
        solution(right,left+1,n,res+')',result);
    }

}

vector<string> findCombination(int n){
    int right = 0, left = 0;
    vector<string> result;
    solution(right,left,n,"",result);

    return result;
}

main(){
    cout << "Enter number : ";
    int n;
    cin >> n;

    vector<string> result = findCombination(n);

    int i = 0;
    for (string res : result){
        cout<<++i<<". "<<res<<endl;
    }

    return 0;
}