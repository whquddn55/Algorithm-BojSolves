#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int n;
lld dp[3001][3001];
vector<int> pos;
vector<int> arr;

lld rec(int from, int to, bool flag) {
	lld& ret = dp[from][to];
	if (ret != -1) return ret;
	ret = 0;

	int diff = arr[to] - arr[from];
	if (arr[to] + diff > arr[n - 1] || pos[arr[to] + diff] == -1) {
		if (flag) 
			return ret = arr[from] + arr[to];
		else
			return 0;
	}
	else {
		int next = pos[arr[to] + diff];
		return ret = arr[from] + rec(to, next, true);
	}
}
int main() {
	scanf("%d", &n);
	arr.resize(n);
	for (int i = 0; i < n; ++i) 
		scanf("%d", &arr[i]);

	pos.resize(arr[n - 1] + 1, -1);
	for (int i = 0; i < n; ++i) 
		pos[arr[i]] = i;
	
	memset(dp, -1, sizeof(dp));

	lld ans = 0;
	for (int i = 0; i< n; ++i) 
		for (int j = i + 1; j < n; ++j) 
			ans = max(ans, rec(i, j, false));
	printf("%lld\n", ans);
}