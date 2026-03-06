#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i <= n; i++)
    {
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i <= n + 1 - len; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j], dp[i][j]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}