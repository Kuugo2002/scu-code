#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<pair<int,int>,int> memo;
vector<int> nums={1,2};
int f(int target,int i){
    if(target==0) return 1;
    if(target<0 || i<0 ) return 0;
    // auto mit = memo.find({target,i});
    // if(mit!=memo.end()){
    //     return mit->second;
    // }
    if(memo.count({target,i})) return memo[{target,i}];
    //int res=f(target-nums[i],i-1)+f(target,i-1);
    int res = f(target,i-1);
    if (target >= nums[i]) {
        res += f(target-nums[i],i-1);
    }
    return memo[{target,i}]=res;
}
int main(){
    int n;
    cin>>n;
    for(int i=1;nums[i]<n;i++){
        int input=nums[i]+nums[i-1];
        if(input<=n){
            nums.push_back(input);
        }
    }
    cout<<f(n,nums.size()-1);
}