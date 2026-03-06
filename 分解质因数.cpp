#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    while (cin >> n)
    {
        vector<int> primes;
        for (int num = 2; num <= n; num++)
        {
            bool isPrime = true;
            for (int i = 2; i * i <= num; i++)
            {
                if (num % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
            {
                primes.push_back(num);
            }
        }
        if(n==primes[primes.size()-1]){
            continue;
        }
        vector<int> res;
        for (int i = 0; primes[i] <= n; i++)
        {
            while (n % primes[i] == 0)
            {
                res.push_back(primes[i]);
                n /= primes[i];
            }
        }
        for (int i = 0; i < res.size(); i++)
        {
            if (i == 0)
            {
                cout << res[i];
            }
            else
            {
                cout << "*" << res[i];
            }
        }
        cout << endl;
    }
    return 0;
}