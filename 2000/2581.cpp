#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n, m;
vector<bool> prime;

int main() {
	scanf("%d %d", &n, &m);
	prime.resize(m + 1, true);
	prime[1] = false;

	for (int i = 2; i <= m; i++) {
		if (prime[i]) 
			for (int j = i * 2; j <= m; j += i)
				prime[j] = false;
	}

	int sum = 0;
	int minValue = INF;
	for (int i = n; i <= m; i++) {
		if (prime[i]) {
			minValue = min(minValue, i);
			sum += i;
		}
	}
	if (minValue == INF) 
		printf("-1\n");
	else
		printf("%d\n%d\n", sum, minValue);
	
	return 0;
}
