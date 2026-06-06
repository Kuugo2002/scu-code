#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <climits>
#include <algorithm>
using namespace std;
int main()
{
    int m;
    cin >> m;
    string dummy;
    getline(cin, dummy);
    vector<vector<int>> vec(m);
    for (int i = 0; i < m; i++)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        int num;
        while (ss >> num)
        {
            vec[i].push_back(num);
        }
    }
    vector<pair<int, int>> result(m); // 第一个装最小值 第二个装最大值
    for (int i = 0; i < m; i++)
    {
        result[i].first = INT_MAX;
        result[i].second = INT_MIN;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            result[i].first = min(result[i].first, vec[i][j]);
            result[i].second = max(result[i].second, vec[i][j]);
        }
    }
    int res = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            res = max(res, abs(result[j].second - result[i].first));
        }
    }
    cout << res << endl;
    return 0;
}