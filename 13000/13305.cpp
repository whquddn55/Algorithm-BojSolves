#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n;
vector<int> dist;
vector<ll> sum;
vector<int> cost;

int main() {
	scanf("%d", &n);
	dist.resize(n);
	sum.resize(n, 0);
	cost.resize(n);
	for (int i = 1; i < n; i++) {
		scanf("%d", &dist[i]);
		sum[i] = sum[i - 1] + dist[i];
	}
	for (int i = 0; i < n; i++)
		scanf("%d", &cost[i]);
	cost[n - 1] = 0;
	int fillLocation = 0;
	ll result = 0;
	for (int i = 1; i < n; i++) {
		if (cost[fillLocation] >= cost[i]) {
			result += cost[fillLocation] * (sum[i] - sum[fillLocation]);
			fillLocation = i;
		}
	}
	printf("%lld\n", result);

	return 0;

}