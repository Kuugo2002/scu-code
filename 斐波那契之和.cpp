#include<iostream>
#include<vector>
using namespace std;
void dfs(vector<int> &nums,int cur,int target,int sum,int& cnt){
    if(sum==target){
        cnt++;
        return;
    }
    if(cur>=nums.size()||sum>target){
        return;
    }
    // 算入加和
    dfs(nums,cur+1,target,sum+nums[cur],cnt);
    // 不算入加和
    dfs(nums,cur+1,target,sum,cnt);
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
    int cnt=0;
    dfs(nums,0,n,0,cnt);
    cout<<cnt;
}