#include<iostream>
#include<vector>
#include <numeric>
#include<cmath>
using namespace std;
int main() {
	vector<int> primes;
	for (int num = 2; num <= 10000; num++) {
		bool is_prime = true;
		for (int i = 2; i * i < num; i++) {
			if (num % i == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			primes.push_back(num);
		}

	}
}
