#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
int main()
{
    int n;
    cin >> n;
    double result = 0;
    vector<int> numerator = {2, 3};
    vector<int> denominator = {1, 2};
    for (int i = 0; i < n - 2; i++)
    {
        int idx = numerator.size() - 1;
        numerator.push_back(numerator[idx] + numerator[idx - 1]);
        denominator.push_back(denominator[idx] + denominator[idx - 1]);
    }
    for (int i = 0; i < n; i++)
    {
        result += numerator[i] * 1.0 / denominator[i];
    }
    cout << fixed << setprecision(2) << result << endl;
}