#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
bool isPrime[300001];
vector<int> primes;

int main() {
	memset(isPrime + 2, true, sizeof(isPrime));
	
	for (int i = 2; i * i <= 300000; i++) {
		if (isPrime[i]) {
			for (int j = i * i; j <= 300000; j += i)
				isPrime[j] = false;
		}
	}
	for (int i = 2; i <= 300000; i++)
		if (isPrime[i])
			primes.push_back(i);

	while (true) {
		scanf("%d", &n);

		if (n == 0)
			break;

		printf("%d\n", upper_bound(primes.begin(), primes.end(), 2 * n) - upper_bound(primes.begin(), primes.end(), n));
	}

	return 0;
}