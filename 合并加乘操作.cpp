#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
string op;
void dfs(vector<int> v,set<int>& res,int op_idx,int a,int b){
    int c;
    if(op[op_idx]=='+'){
        c=a+b;
    }
    else{
        c=a*b;
    }
    if(v.empty()){
        res.insert(c);
        return;
    }
    v.push_back(c);
    for(int i=0;i<v.size()-1;i++){
        a=v[i];
        for(int j=i+1;j<v.size();j++){
            b=v[j];
            vector<int> temp_v=v;
            temp_v.erase(temp_v.begin()+j);
            temp_v.erase(temp_v.begin()+i);
            dfs(temp_v,res,op_idx+1,a,b);
        }
    }

}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    op.resize(n-1);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    cin>>op;
    set<int> res;
    for(int i=0;i<n-1;i++){
        int a=v[i];
        for(int j=i+1;j<n;j++){
            int b=v[j];
            vector<int> temp_v=v;
            temp_v.erase(temp_v.begin()+j);
            temp_v.erase(temp_v.begin()+i);
            dfs(temp_v,res,0,a,b);
        }
    }
    for(int c:res){
        cout<<c<<" ";
    }
}
