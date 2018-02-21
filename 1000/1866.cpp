#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n;
vector<int> dist;
int dp[3000];
int truckCost, heliCost;

int get(int idx1) {
	if (idx1 == -1) 
		return 0;

	int& ret = dp[idx1];
	if (ret != -1)
		return ret;

	ret = dist[idx1] * truckCost + get(idx1 - 1);
	int sum = heliCost;
	for (int i = idx1; i >= 0; i--) {
		sum += (dist[(i + idx1 + 1) / 2] - dist[i]) * truckCost;
		ret = min(ret, get(i - 1) + sum);
	}
}

int main() {
	scanf("%d", &n);
	dist.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &dist[i]);
	scanf("%d %d", &truckCost, &heliCost);

	sort(dist.begin(), dist.end());
	memset(dp, -1, sizeof(dp));
	printf("%d\n", get(n - 1));

	return 0;
}
