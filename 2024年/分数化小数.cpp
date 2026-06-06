#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int integerPart = a / b;
    a %= b;
    vector<int> digits;
    // 多算一位，用来判断是否需要进位
    for (int i = 0; i < c + 1; i++)
    {
        a *= 10;
        digits.push_back(a / b);
        a %= b;
    }
    // 四舍五入逻辑
    bool carry = false;
    if (digits.back() >= 5)
    {
        carry = true;
    }
    digits.pop_back(); // 删掉用来判断的那一位
    // 从最后一位开始向前进位
    for (int i = c - 1; i >= 0 && carry; i--)
    {
        digits[i]++;
        if (digits[i] < 10)
        {
            carry = false;
        }
        else
        {
            digits[i] = 0;
            carry = true;
        }
    }
    // 如果最后carry还是true,说明进位到了整数部分
    if (carry)
    {
        integerPart++;
    }
    // 输出结果
    cout << integerPart << ".";
    for (int d : digits)
    {
        cout << d;
    }
    cout << endl;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        solve();
    }
    return 0;
}
