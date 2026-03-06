#include <iostream>
#include <vector>
using namespace std;
int dfs(int x, int y, vector<vector<int>> &matrix, int scale)
{ // scale表示目前矩阵的等级 1表示1*1 2表示2*2
    // 先判断是否越界
    if (x + scale > matrix.size() || y + scale > matrix.size())
    {
        return scale - 1;
    }
    bool flag = true;
    for (int i = 0; i < scale; i++)
    {
        for (int j = 0; j < scale; j++)
        {
            if (matrix[x + i][y + j] == 0)
            {
                flag = false;
            }
        }
    }
    // 当矩阵的等级够，试试下一个等级
    if (flag)
    {
        return dfs(x, y, matrix, scale + 1);
    }
    // 失败了，返回上一个等级
    return scale - 1;
}
int main()
{
    int m, n; // 矩阵的行数和列数
    cin >> m >> n;
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
    int maxscale = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1)
            {
                // 为1说明1*1的等级够
                maxscale = max(maxscale, dfs(i, j, matrix, 2));
            }
        }
    }
    cout << maxscale << endl;
    return 0;
}