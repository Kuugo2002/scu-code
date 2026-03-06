#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    double result = a * 1.0 / b;
    cout << fixed << setprecision(c) << result << endl;
}