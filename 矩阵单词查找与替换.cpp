#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> matrix(n);
    for (int i = 0; i < n; i++)
    {
        cin >> matrix[i];
    }
    vector<string> res(n, string(m, '*'));
    string target = "hello";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] != 'h')
                continue;
            for (int k = 0; k < 8; k++)
            {
                bool found = true;
                // 提前检测是否越界
                int endX = i + 4 * dx[k];
                int endY = j + 4 * dy[k];
                if (endX < 0 || endX >= n || endY < 0 || endY >= m)
                    continue;
                for (int step = 1; step < 5; ++step)
                {
                    if (matrix[i + step * dx[k]][j + step * dy[k]] != target[step])
                    {
                        found = false;
                        break;
                    }
                }
                if (found)
                {
                    for (int step = 0; step < 5; ++step)
                    {
                        res[i + step * dx[k]][j + step * dy[k]] = target[step];
                    }
                }
            }
        }
    }
    for (string row : res)
    {
        cout << row << endl;
    }
    return 0;
}