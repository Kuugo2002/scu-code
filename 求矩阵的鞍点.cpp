#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> matrix(n,vector<int>(m));
    vector<int> row_max(n,INT_MIN);
    vector<int> col_min(m,INT_MAX);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>matrix[i][j];
            row_max[i]=max(row_max[i],matrix[i][j]);
            col_min[j]=min(col_min[j],matrix[i][j]);
        }
    }
    bool flag=true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j]==row_max[i]&&matrix[i][j]==col_min[j])
            {
                cout<<i+1<<" "<<j+1<<" "<<matrix[i][j]<<endl;
                flag=false;
            }
        }
    }
    if(flag){
        cout<<"NO"<<endl;
    }
    return 0;
}