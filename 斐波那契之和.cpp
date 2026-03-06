#include<iostream>
#include<vector>
#include<map>
using namespace std;
int f(int target,int i,map<pair<int,int>,int>& memo,vector<int> &nums){
    if(target==0) return 1;
    if(target<0) return 0;
    if(i<0&&target>0) return 0;
    auto mit = memo.find({target,i});
    if(mit!=memo.end()){
        return mit->second;
    }
    int res=f(target-nums[i],i-1,memo,nums)+f(target,i-1,memo,nums);
    memo[{target,i}]=res;
    return res;
}
int main(){
    int n;
    cin>>n;
    vector<int> nums={1,2};
    for(int i=1;nums[i]<n;i++){
        int input=nums[i]+nums[i-1];
        if(input<=n){
            nums.push_back(input);
        }
    }
    map<pair<int,int>,int> memo;
    cout<<f(n,nums.size()-1,memo,nums);
}