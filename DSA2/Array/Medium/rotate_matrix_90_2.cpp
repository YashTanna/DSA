#include <bits/stdc++.h>
using namespace std;



vector<vector<int>> rotateClockwise(vector<vector<int>> a){
    int n = a.size();

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            swap(a[i][j],a[j][i]);
        }
    }

    for(int i=0;i<n;i++)
        reverse(a[i].begin(),a[i].end());

    return a;
}

int main() {
    vector<vector<int>> mat = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    cout<<"Original matrix"<<endl;

    for (auto row : mat) {
        for (int val : row) cout << val << "  ";
        cout << endl;
    }

    vector<vector<int>> rotated = rotateClockwise(mat);

    cout<<"After rotate"<<endl;

    // Print the rotated matrix
    for (auto row : rotated) {
        for (int val : row) cout << val << " ";
        cout << endl;
    }

    return 0;
}