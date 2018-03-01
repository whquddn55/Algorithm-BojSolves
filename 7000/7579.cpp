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

int n, m;
vector<pii> arr;
int dp[101][10001];

int getDp(int idx1, int idx2) {
	if (idx1 == n) 
		return 0;
	

	int& ret = dp[idx1][idx2];
	if (ret != -1)
		return ret;

	ret = 0;
	if (idx2 >= arr[idx1].second)
		ret = max(ret, arr[idx1].first + getDp(idx1 + 1, idx2 - arr[idx1].second));

	return ret = max(ret, getDp(idx1 + 1, idx2));
}

int main() {
	scanf("%d %d", &n, &m);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i].first);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i].second);

	memset(dp, -1, sizeof(dp));
	
	for (int i = 0;; i++)
		if (getDp(0, i) >= m) {
			printf("%d\n", i);
			break;
		}
	return 0;

}
