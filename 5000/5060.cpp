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
using std::make_pair;
using std::fill;

typedef long long ll;
typedef pair<int, int> pii;

#define INF (INT_MAX / 2)

int h, c;
vector<int> arr;
vector<vector<double>> diff;
double dp[201][201]; // i번째 집을 j번째 집으로 선택할 때 총 오차의 최소값

double getDp(int idx1, int idx2) {
	if (idx2 == c)
		return (idx1 == h - 1) ? 0 : INF;

	double& ret = dp[idx1][idx2];
	if (ret != -1.0)
		return ret;
	ret = INF;

	for (int i = idx1 + 1; i < h; i++)
		ret = min(ret, getDp(i, idx2 + 1) + diff[idx1][i]);
}

int main() {
	int tc;
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d %d", &h, &c);
		arr.clear();
		arr.resize(h);
		for (int i = 0; i < h; i++)
			scanf("%d", &arr[i]);
		sort(arr.begin(), arr.end());

		diff.clear();
		diff.resize(h);
		for (int i = 0; i < h; i++)
			diff[i].resize(h, 0.0);

		for (int i = 0; i < h; i++)
			for (int j = i + 2; j < h; j++)
				for (int k = i + 1; k < j; k++) {
					double expectedValue = arr[i] + (double)(arr[j] - arr[i]) * (k - i) / (j - i);
					diff[i][j] += expectedValue - arr[k] > 0 ? expectedValue - arr[k] : -(expectedValue - arr[k]);
				}

		for (int i = 0; i < 201; i++)
			for (int j = 0; j < 201; j++)
				dp[i][j] = -1.0;

		printf("%.4lf\n", getDp(0, 1) / h);
	}

	return 0;
}