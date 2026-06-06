#include <iostream>
#include <vector>
using namespace std;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int x, int y, vector<vector<char>> &garden, vector<vector<bool>> &visited)
{
    // 先判断位置是否合法
    int n = garden.size(), m = garden[0].size();
    if (x < 0 || y < 0 || x >= n || y >= n || garden[x][y] != 'W' || visited[x][y])
    {
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        dfs(x + dx[i], y + dy[i], garden, visited);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> garden(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> garden[i][j];
        }
    }
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (garden[i][j] == 'W' && visited[i][j] == false)
            {
                cnt++;
                for (int k = 0; k < 8; k++)
                {
                    dfs(i + dx[k], j + dy[k], garden, visited);
                }
            }
        }
    }
    cout << cnt << endl;
}