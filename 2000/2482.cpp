#include <bits/stdc++.h>
using namespace std;

const int INF = INT_MAX / 2;
const int MOD = 1000000003;
typedef pair<int, int> pii;
typedef long long ll;

int n, k;
vector<vector<int> > dp;

int getDp(int idx1, int idx2) {
	if (idx1 <= 0)
		return 0;
	if (idx2 == 1)
		return idx1;
	if (idx1 / 2 < idx2)
		return 0;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = (getDp(idx1 - 2, idx2 - 1) + getDp(idx1 - 1, idx2)) % MOD;
	return ret;
}

int main() {
	scanf("%d%d", &n, &k);
	dp.resize(n + 1);
	for (int i = 1; i <= n; i++)
		dp[i].resize(k + 1, -1);

	printf("%d\n", getDp(n, k));

	return 0;
}