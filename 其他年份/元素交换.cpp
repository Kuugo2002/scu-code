#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    if(n%2==1){
        n--;
    }
    for(int i=0;i<n;i+=2){
        swap(vec[i],vec[i+1]);
    }
    for(int i=0;i<vec.size();i++){
        if(i==0){
            cout<<vec[i];
        }
        else{
            cout<<" "<<vec[i];
        }
    }
    cout<<endl;
    return 0;
}