#include <iostream>
#include <vector>
using namespace std;
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(int x, int y, vector<vector<char>> &matrix, vector<vector<bool>> &visited)
{
    if (x < 0 || y < 0 || x >= matrix.size() || y >= matrix[0].size() || visited[x][y] || matrix[x][y] != 'w')
    {
        return;
    }
    visited[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        dfs(x + dx[i], y + dy[i], matrix, visited);
    }
}
int main()
{
    int h, w;
    cin >> h >> w;
    vector<vector<char>> matrix(h, vector<char>(w));
    vector<vector<bool>> visited(h, vector<bool>(w));
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int count = 0;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (matrix[i][j] == 'w' && visited[i][j] == false)
            {
                count++;
                dfs(i, j, matrix, visited);
            }
        }
    }
    cout << count << endl;
    return 0;
}