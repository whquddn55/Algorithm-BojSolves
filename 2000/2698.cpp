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

int n, k;
int dp[101][101][2];

int getDp(int idx1, int idx2, int idx3) {
	if (idx1 <= idx2)
		return 0;
	if (idx1 == 1)
		return (idx2 == 0);
	if (idx1 == idx2 + 1)
		return idx3;
	

	int& ret = dp[idx1][idx2][idx3];
	if (ret != -1)
		return ret;
	ret = 0;

	if (idx3 == 0)
		ret = getDp(idx1 - 1, idx2, 0) + getDp(idx1 - 1, idx2, 1);
	else
		ret = getDp(idx1 - 1, idx2, 0) + getDp(idx1 - 1, idx2 - 1, 1);

	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);
	memset(dp, -1, sizeof(dp));
	while (tc--) {
		scanf("%d %d", &n, &k);

		printf("%d\n", getDp(n, k, 0) + getDp(n, k, 1));
	}
	

	return 0;
}