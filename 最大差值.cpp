#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    int min_num = INT_MAX;
    int result = INT_MIN;
    for (int i = 1; i < n; i++)
    {
        cin >> nums[i];
        if (nums[i] < min_num)
        {
            min_num = nums[i];
        }
        if (nums[i] - min_num > result)
        {
            result = nums[i] - min_num;
        }
    }
    if (n < 2)
    {
        cout << 0;
    }
    else
    {
        cout << result;
    }
    return 0;
}