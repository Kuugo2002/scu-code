#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
bool dfs(int p, vector<int> &result, vector<vector<int>> &adj, vector<vector<bool>> &visited, int weight_sum, int t)
{
    if (p == t)
    {
        result.push_back(weight_sum);
        return true;
    }
    for (int i = 1; i <= adj.size(); i++)
    {
        if (adj[p][i] != 0)
        {
            if (visited[p][i] == true)
            {
                return false;
            }
            return dfs(i, result, adj, visited, weight_sum + adj[p][i], t);
        }
    }
    return false;
}
int main()
{
    int n, m, s, t; // n->节点数 m->边数 s->起点 t->终点
    cin >> n >> m >> s >> t;
    vector<vector<int>> adj(m + 1, vector<int>(m + 1));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        cin >> adj[u][v];
    }
    vector<vector<bool>> visited(m + 1, vector<bool>(m + 1));
    vector<int> result;
    if (!dfs(s, result, adj, visited, 0, t))
    {
        cout << -1 << endl;
    }
    int maxcost = INT_MIN;
    for (int i = 0; i < result.size(); i++)
    {
        maxcost = max(maxcost, result[i]);
    }
    cout << maxcost << endl;
    return 0;
}