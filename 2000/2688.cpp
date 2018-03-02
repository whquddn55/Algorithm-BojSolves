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

ll dp[65][10];

ll getDp(int idx1, int idx2) {
	if (idx1 == 1)
		return 1;

	ll& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;
	ret = 0;

	for (int i = 0; i <= idx2; i++)
		ret += getDp(idx1 - 1, i);

	return ret;
}

int main() {
	int tc;
	scanf("%d", &tc);
	memset(dp, -1, sizeof(dp));
	while (tc--) {
		int n;
		scanf("%d", &n);

		ll ret = 0;
		for (int i = 0; i < 10; i++)
			ret += getDp(n, i);

		printf("%lld\n", ret);
	}
	

	return 0;
}