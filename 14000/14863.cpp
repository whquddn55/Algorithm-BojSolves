#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n, k;
vector<pii> walk;
vector<pii> cycle;
int dp[101][100001];

int get(int idx1, int idx2) {
	if (idx2 > k)
		return -INF;
	if (idx1 == n)
		return 0;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = max(get(idx1 + 1, idx2 + walk[idx1].first) + walk[idx1].second,
		get(idx1 + 1, idx2 + cycle[idx1].first) + cycle[idx1].second);
	return ret;
}

int main() {
	scanf("%d %d", &n, &k);
	walk.resize(n);
	cycle.resize(n);
	memset(dp, -1, sizeof(dp));

	for (int i = 0; i < n; i++) 
		scanf("%d %d %d %d", &walk[i].first, &walk[i].second, &cycle[i].first, &cycle[i].second);

	printf("%d\n", get(0, 0));
	
	return 0;

}
