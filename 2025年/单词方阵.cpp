#include <iostream>
#include <vector>
#include <set>
using namespace std;
// 定义 8 个方向的偏移量：{dx, dy}
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool dfs( int x, int y, int cur, int N,string word, vector<vector<char>> &word_matrix, int dir_idx)
{
    // 给的位置不合法 当前字母不对
    if (x < 0 || x >= N || y < 0 || y >= N||word_matrix[x][y]!=word[cur]){
        return false;
    }
    if(cur==word.size()-1){
        return true;
    }
    return dfs(x+dx[dir_idx],y+dy[dir_idx],cur+1,N,word,word_matrix,dir_idx);
}
int main()
{
    int N;
    cin >> N;
    vector<vector<char>> word_matrix(N, vector<char>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> word_matrix[i][j];
        }
    }
    string word;
    cin >> word;
    int length = word.size();
    set<pair<int, int>> result;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            for (int k = 0; k < 8; k++)
            {
                if(dfs(i,j,0,N,word,word_matrix,k)){
                    result.insert({i,j});
                }
            }
        }
    }
    if (result.empty())
    {
        cout << "Not Found" << endl;
    }
    else
    {
        for(auto it=result.begin();it!=result.end();it++){
            cout<<it->first+1<<" "<<it->second+1<<endl;
        }
    }
    return 0;
}