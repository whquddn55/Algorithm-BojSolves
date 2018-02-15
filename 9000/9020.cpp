#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

int n;
bool isPrime[10001];
vector<int> primes;

int main() {
	int tc;
	scanf("%d", &tc);

	memset(isPrime, true, sizeof(isPrime));

	for (int i = 2; i <= 10000; i++) {
		if (isPrime[i] == false)
			continue;

		primes.push_back(i);
		for (int j = i + i; j <= 10000; j += i)
			isPrime[j] = false;
	}

	while (tc--) {
		scanf("%d", &n);

		if (isPrime[n / 2])
			printf("%d %d\n", n / 2, n / 2);
		else {
			int idx = lower_bound(primes.begin(), primes.end(), n / 2) - primes.begin();
			for(; idx < primes.size(); idx++)
				if (isPrime[n - primes[idx]]) {
					printf("%d %d\n", n - primes[idx], primes[idx]);
					break;
				}
		}
	}

	return 0;
}