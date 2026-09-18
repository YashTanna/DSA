#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> & a){

    int rowCnt = a.size();
    int colCnt = a[0].size();
    int col0 = 1;

    for(int i=0;i<rowCnt;i++){
        for(int j=0;j<colCnt;j++){
            if(a[i][j] == 0){
                a[i][0] = 0;
                if(j != 0)
                    a[0][j] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for(int i=1;i<rowCnt;i++){
        for(int j=1;j<colCnt;j++){
            if(a[i][j] != 0){
                if(a[i][0] == 0 || a[0][j] == 0){
                    a[i][j] = 0;
                }
            }
        }
    }

    if(a[0][0] == 0){
        for(int j=0;j<colCnt;j++)
            a[0][j] = 0; 
    }

    if(col0 == 0){
        for(int i=0;i<rowCnt;i++)
            a[i][0] = 0;
    }

}

int main() {
    // Create the matrix
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    cout<<"Before setting Zeros"<<endl;
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    cout<<"After setting Zeros"<<endl;
    // Call function
    setZeroes(matrix);
    
    // Print the updated matrix
    for (auto row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}