#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> primes;
    for (int num = 2; num <= 100000; num++)
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
            primes.push_back(num);
    }
    for (int i = 0;i< primes.size(); i++)
    {
        cout << primes[i] << ",";
    }
    return 0;
}