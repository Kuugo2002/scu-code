#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    vector<string> num0 = {"*****", "*   *", "*   *", "*   *", "*   *", "*   *", "*****"};
    vector<string> num1 = {"    *", "    *", "    *", "    *", "    *", "    *", "    *"};
    vector<string> num2 = {"*****", "    *", "    *", "*****", "*    ", "*    ", "*****"};
    vector<string> num3 = {"*****", "    *", "    *", "*****", "    *", "    *", "*****"};
    vector<string> num4 = {"*   *", "*   *", "*   *", "*****", "    *", "    *", "    *"};
    vector<string> num5 = {"*****", "*    ", "*    ", "*****", "    *", "    *", "*****"};
    vector<string> num6 = {"*****", "*    ", "*    ", "*****", "*   *", "*   *", "*****"};
    vector<string> num7 = {"*****", "    *", "    *", "    *", "    *", "    *", "    *"};
    vector<string> num8 = {"*****", "*   *", "*   *", "*****", "*   *", "*   *", "*****"};
    vector<string> num9 = {"*****", "*   *", "*   *", "*****", "    *", "    *", "*****"};
    vector<vector<string>> nums = {num0, num1, num2, num3, num4, num5, num6, num7, num8, num9};
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        cout << num << ":" << endl;
        stack<int> number;
        while (num > 0)
        {
            int tmp = num % 10;
            number.push(tmp);
            num /= 10;
        }
        vector<string> print_res(7);
        bool flag = true;
        while (!number.empty())
        {
            int m = number.top();
            if (flag)
            {
                for (int i = 0; i < 7; i++)
                {
                    print_res[i] += nums[m][i];
                }
                flag = false;
            }
            else
            {
                for (int i = 0; i < 7; i++)
                {
                    print_res[i] += ("  " + nums[m][i]);
                }
            }
            number.pop();
        }
        for (int i = 0; i < 7; i++)
        {
            cout << print_res[i] << endl;
        }
    }
    return 0;
}