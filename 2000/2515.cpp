#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int n, s;
vector<pii> arr;
vector<int> dp;

bool comp(const pii& a, const pii& b) {
	return a.first < b.first;
}

int get(int here) {
	if (here > n)
		return 0;
	if (here == n - 1)
		return arr[n - 1].second;

	int &ret = dp[here];
	if (ret != -1) return ret;
	int pos = lower_bound(arr.begin(), arr.end(), pii(arr[here].first + s, 0), comp) - arr.begin();
	return ret = max(get(here + 1), get(pos) + arr[here].second);
}

int main() {
	scanf("%d %d", &n, &s);
	arr.resize(n);
	dp.resize(n, -1);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &arr[i].first, &arr[i].second);
	sort(arr.begin(), arr.end());

	printf("%d\n", get(0));

	return 0;
}