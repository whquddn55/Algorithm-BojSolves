#include <bits/stdc++.h>
using namespace std;

#define INF (INT_MAX / 2)
typedef long long ll;
typedef pair<int, int> pii;

string init;
int dp[501][501];

int getDp(int idx1, int idx2) {
	if (idx2 - idx1 == 1)
		if ((init[idx1] == 'a' && init[idx2] == 't') || (init[idx1] == 'g' && init[idx2] == 'c'))
			return 2;
		else
			return 0;
	if (idx2 - idx1 < 1)
		return 0;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	if ((init[idx1] == 'a' && init[idx2] == 't') || (init[idx1] == 'g' && init[idx2] == 'c'))
		ret = getDp(idx1 + 1, idx2 - 1) + 2;

	for (int i = idx1; i < idx2; i++)
		ret = max(ret, getDp(idx1, i) + getDp(i + 1, idx2));

	return ret;
}

int main() {
	cin >> init;
	
	memset(dp, -1, sizeof(dp));
	printf("%d\n", getDp(0, init.size() - 1));

	return 0;
}