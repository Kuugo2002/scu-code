#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int n;
vector<int> chessboard;
int cnt = 0;
// 检查在col列放入row行是否合法
bool is_vaild(int col, int row)
{
    if (col == 0)
        return true; // 第一行左侧无约束
    if (chessboard[col - 1] == 0)
        return true; // 前一列没有填，先不检查（但实际一定填了）
    return abs(chessboard[col - 1] - row) <= 1;
}
void dfs(int col)
{
    if (col == n)
    {
        cnt++;
        return;
    }
    // 如果当前列已经有了棋子
    if (chessboard[col] != 0)
    {
        if (is_vaild(col, chessboard[col]))
        {
            dfs(col + 1);
        }
        return;
    }
    // 如果当前列没有棋子
    for (int row = 1; row <= n; row++)
    {
        if (is_vaild(col, row))
        {
            chessboard[col] = row;
            dfs(col + 1);
            chessboard[col] = 0; // 回溯
        }
    }
}
int main()
{
    while (true)
    {
        cnt=0;
        cin >> n;
        if(n==0) break;
        chessboard.resize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> chessboard[i];
        }
        // 检查初始状态是否合法
        bool isPossible=true;
        for (int i = 0; i < n - 1; i++)
        {
            if (chessboard[i] != 0 && chessboard[i + 1] != 0)
            {
                if (abs(chessboard[i] - chessboard[i + 1]) > 1)
                {
                    isPossible = false;
                }
            }
        }
        if (!isPossible)
        {
            cout << 0 << endl;
        }
        else
        {
            dfs(0);
            cout << cnt << endl;
        }
    }
    return 0;
}