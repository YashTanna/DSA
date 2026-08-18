#include<bits/stdc++.h>
using namespace std;

bool isAnogram(string s1,string s2){

    vector<char> v1;
    for(char c : s1){
        v1.push_back(c);
    }

    vector<char> v2;
    for(char c:s2){
        v2.push_back(c);
    }

    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());

    for(int i=0;i < v1.size();i++){
        if(v1[i] != v2[i])
            return false;
    }

    return true;
}

main()
{

    string s1;
    string s2;

    cout<<"Enter First String : ";
    cin>>s1;

    cout<<"Enter Second String :";
    cin>>s2;

    cout<<"Is strong anogram? : "<<(isAnogram(s1,s2)?"Yes":"No");

    return 0;
}