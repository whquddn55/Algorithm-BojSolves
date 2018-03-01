#include <bits/stdc++.h>
using std::pair;
using std::vector;
using std::queue;
using std::stack;
using std::priority_queue;
using std::set;
using std::map;
using std::deque;
using std::greater;
using std::max;
using std::min;
using std::sort;
using std::binary_search;
using std::lower_bound;
using std::upper_bound;
using std::reverse;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int n;
vector<int> arr;
int dp[31][30001];

int getDp(int idx1, int idx2) {
	if (idx1 == n)
		return dp[idx1][idx2] = 1;

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;
	ret = 0;

	return ret = max({ ret, getDp(idx1 + 1, idx2 + arr[idx1]), getDp(idx1 + 1, idx2), getDp(idx1 + 1, idx2 - arr[idx1]) });
}

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	memset(dp, -1, sizeof(dp));

	getDp(0, 15000);

	int tc;
	scanf("%d", &tc);

	while (tc--) {
		int t;
		scanf("%d", &t);
		if (t >= 15001) {
			printf("N ");
			continue;
		}

		if (dp[n][t + 15000] == 1 || dp[n][15000 - t] == 1)
			printf("Y ");
		else
			printf("N ");
	}

	return 0;
}