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

int n;
vector<int> arr;
int dp1[2001];
int dp2[2001];

int a[11000];
int b[11000];

int getDp1(int idx1) {
	int& ret = dp1[idx1];
	if (ret != -1)
		return ret;

	ret = 1;
	for (int i = idx1 + 1; i < n; i++)
		if (arr[idx1] < arr[i])
			ret = max(ret, getDp1(i) + 1);

	return ret;
}

int getDp2(int idx1) {
	int& ret = dp2[idx1];
	if (ret != -1)
		return ret;

	ret = 1;
	for (int i = idx1 + 1; i < n; i++)
		if (arr[idx1] > arr[i])
			ret = max(ret, getDp2(i) + 1);

	return ret;
}

int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	memset(dp1, -1, sizeof(dp1));
	for (int i = 0; i < n; i++)
		getDp1(i);
	memset(dp2, -1, sizeof(dp2));
	for (int i = 0; i < n; i++)
		getDp2(i);

	int result = 0;
	for (int i = 0; i < n; i++)
		result = max(result, dp1[i] + dp2[i] - 1);

	printf("%d\n", result);
	return 0;
}