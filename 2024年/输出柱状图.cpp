#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int N;
    cin >> N;
    vector<int> height(N);
    int maxheight = 0;
    for (int i = 0; i < N; i++)
    {
        cin >> height[i];
        maxheight = max(height[i], maxheight);
    }
    vector<vector<char>> res(maxheight, vector<char>(N, ' '));
    for(int i=0;i<N;i++){
        for(int j=maxheight-1;j>maxheight-height[i]-1;j--){
            res[j][i]='*';
        }
    }
    for (int i = 0; i < maxheight; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (j == 0)
            {
                cout << res[i][j];
            }
            else
            {
                cout << " " << res[i][j];
            }
        }
        cout << endl;
    }
}