#include<iostream>
using namespace std;
int C(int n,int r){
    if(r==1) return n;
    return C(n,r-1)*(n-r+1)/r;
}
int main(){
    while(true){
        int n,r;
        cin>>n>>r;
        if(n==0&&r==0) break;
        if(r==0){
            cout<<1<<endl;
            continue;
        }
        if(r>n){
            cout<<"error!"<<endl;
            continue;
        }
        cout<<C(n,r)<<endl;
    }
    return 0;
}